%ifdef	__LINUX__
    %define DEF_FT_READ ft_read
    %define DEF_ERRNO_LOCATION __errno_location
    %define DEF_SYSCALL_READ 1
	%define DEF_EXTERN_CALL_SUFFIX wrt ..plt
%else
    %define DEF_FT_READ _ft_read
    %define DEF_ERRNO_LOCATION ___error
    %define DEF_SYSCALL_READ 0x2000004
	%define DEF_EXTERN_CALL_SUFFIX
%endif

extern DEF_ERRNO_LOCATION

global DEF_FT_READ

DEF_FT_READ:
    mov         rax, DEF_SYSCALL_READ
    syscall
    cmp         rax, 0
    jl          error
    ret

error:
    neg  		rax
    push		rax
    call 		DEF_ERRNO_LOCATION wrt ..plt
    pop  		qword [rax]
    mov  		rax, -1
    ret