%ifdef	__LINUX__
	%define DEF_FT_READ ft_read
	%define DEF_ERRNO_LOCATION __errno_location
	%define DEF_SYSCALL_READ 0
	%define DEF_EXTERN_CALL_SUFFIX wrt ..plt
%else
	%define DEF_FT_READ _ft_read
	%define DEF_ERRNO_LOCATION ___error
	%define DEF_SYSCALL_READ 0x2000003
	%define DEF_EXTERN_CALL_SUFFIX
%endif

extern DEF_ERRNO_LOCATION

global DEF_FT_READ

DEF_FT_READ:
	mov				rax, DEF_SYSCALL_READ
	syscall
%ifdef	__LINUX__
	cmp				rax, 0
	jl				error
%else
	jc				error
%endif
	ret

error:
%ifdef	__LINUX__
	neg			rax
%endif
	push		rax
	call		DEF_ERRNO_LOCATION DEF_EXTERN_CALL_SUFFIX
	pop			qword [rax]
	mov			rax, -1
	ret