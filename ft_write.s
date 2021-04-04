segment .text
	global _ft_write

_ft_write:
	mov		rax, 0
	jmp		write

write:
	mov		