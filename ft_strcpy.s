segment .data
	global _ft_strcpy

_ft_strcpy:
	mov		rax, rdi
	jmp		copy

copy:
	mov		al, [rsi]
	; mov		bl, BYTE [rdi]
	mov		[rdi], al
	cmp		al, 0
	je		exit
	inc		rdi
	inc		rsi
	jmp		copy

exit:
	ret