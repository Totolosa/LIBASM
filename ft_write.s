%ifdef	__LINUX__
    %define DEF_FT_WRITE ft_write
    %define DEF_ERRNO_LOCATION __errno_location
    %define DEF_SYSCALL_WRITE 1
	%define DEF_EXTERN_CALL_SUFFIX wrt ..plt
%else
    %define DEF_FT_WRITE _ft_write
    %define DEF_ERRNO_LOCATION ___error
    %define DEF_SYSCALL_WRITE 0x2000004
	%define DEF_EXTERN_CALL_SUFFIX
%endif

; ret = ft_write(int fd, const void *buf, size_t count) ---> fd(first parameter) = rdi, buf(second parameter) = rsi, count(third parameter) = rdx

extern DEF_ERRNO_LOCATION

section .text
	global DEF_FT_WRITE
																;		OPERATION					EXPLICATION
DEF_FT_WRITE:
    mov			rax, DEF_SYSCALL_WRITE							; 								put system index in rax for the syscall of function write
    syscall
%ifdef	__LINUX__
    cmp			rax, 0
    jl			error											; if (rax < 0) -> error
%else
	jc			error											; if (CF flag = 1) -> error
%endif
    ret

error:
%ifdef	__LINUX__
    neg  		rax												; rax = -rax
%endif
    push		rax												; 								put value of rax on the top of stack = SAVE RAX VALUE
    call 		DEF_ERRNO_LOCATION DEF_EXTERN_CALL_SUFFIX		; 								call the function who localise the adress of the var errno ,  wrt..pl avoids overflow in R_X86_64_PC32 relocation
    pop  		qword [rax]										;								put the value of rax previously saved to the adress pointed by rax. Value of 8 bits (q = 4, word = 2 : 2 x 4 = 8)
    mov  		rax, -1
    ret