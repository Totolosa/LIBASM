%ifdef	__LINUX__
    %define DEF_FT_STRCMP ft_strcmp
%else
    %define DEF_FT_STRCMP _ft_strcmp
%endif

segment	.text
	global DEF_FT_STRCMP

DEF_FT_STRCMP:
	mov		rax, 0
	jmp		compare

compare:
	mov		al, BYTE [rdi]
	mov		bl, BYTE [rsi]
	cmp		al, 0
	je		exit
	cmp		bl, 0
	je		exit
	cmp		al, bl
	jne		exit
	inc		rdi
	inc		rsi
	jmp		compare

exit:
	movzx	rax, al
	movzx	rbx, bl
	sub		rax, rbx
	ret