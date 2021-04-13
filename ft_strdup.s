%ifdef	__LINUX__
	%define DEF_FT_STRDUP ft_strdup
	%define DEF_FT_STRLEN ft_strlen
	%define DEF_MALLOC malloc
	%define DEF_FT_STRCPY ft_strcpy
	%define DEF_ERRNO_LOCATION __errno_location
	%define DEF_EXTERN_CALL_SUFFIX wrt ..plt
%else
	%define DEF_FT_STRDUP _ft_strdup
	%define DEF_FT_STRLEN _ft_strlen
	%define DEF_MALLOC _malloc
	%define DEF_FT_STRCPY _ft_strcpy
	%define DEF_ERRNO_LOCATION ___error
	%define DEF_EXTERN_CALL_SUFFIX
%endif

extern DEF_MALLOC
extern DEF_FT_STRLEN
extern DEF_FT_STRCPY

segment .text
	global DEF_FT_STRDUP

DEF_FT_STRDUP:
	jmp				strlen_strdup

strlen_strdup:
	mov				rax, 0
	call			DEF_FT_STRLEN
	inc				rax
	mov				r12, rax
	jmp				malloc_strdup

malloc_strdup:
	mov				rax, 0
	push			rdi
	mov				rdi, r12
	call			DEF_MALLOC
	pop				rsi
	mov				rdi, rax
	cmp				rax, 0
	je				error
	jne				copy

copy:
	call			DEF_FT_STRCPY
	ret

error:
	mov				rax, 0
	ret
