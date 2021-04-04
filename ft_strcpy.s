segment .text
	global _ft_strcpy

_ft_strcpy:
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