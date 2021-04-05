%ifdef	__LINUX__
    %define DEF_FT_STRCPY ft_strcpy
%else
    %define DEF_FT_STRCPY _ft_strcpy
%endif

segment .text
	global DEF_FT_STRCPY

DEF_FT_STRCPY:
	mov		rax, 0
	jmp		copy

copy:
	mov		bl, [rsi + rax]
	cmp		bl, 0
	je		exit
	mov		[rdi + rax], bl
	inc		rax
	jmp		copy

exit:
	mov		BYTE [rdi + rax], 0
	mov		rax, rdi
	ret