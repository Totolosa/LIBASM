%ifdef	__LINUX__
    %define DEF_FT_WRITE ft_write
    %define DEF_ERRNO_LOCATION __errno_location
    %define DEF_SYSCALL_WRITE 0
	%define DEF_EXTERN_CALL_SUFFIX wrt ..plt
%else
    %define DEF_FT_WRITE _ft_write
    %define DEF_ERRNO_LOCATION ___error
    %define DEF_SYSCALL_WRITE 0x2000003
	%define DEF_EXTERN_CALL_SUFFIX
%endif

extern DEF_ERRNO_LOCATION

section .text
	global DEF_FT_WRITE

DEF_FT_WRITE:
    mov			rax, DEF_SYSCALL_WRITE
    syscall
    cmp			rax, 0
    jl			error
	jg			DEF_FT_WRITE
    ret

error:
    neg  		rax
    push		rax
    call 		DEF_ERRNO_LOCATION wrt ..plt
    pop  		qword [rax]
    mov  		rax, -1
    ret