%ifdef	__LINUX__
    %define DEF_FT_STRLEN ft_strlen
%else
    %define DEF_FT_STRLEN _ft_strlen
%endif

global DEF_FT_STRLEN

DEF_FT_STRLEN:
	mov		rax, 0
	jmp		count

count:
	cmp		BYTE [rdi + rax], 0
	je		exit
	inc		rax
	jnz		count

exit:
	ret