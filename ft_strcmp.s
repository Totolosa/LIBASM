%ifdef	__LINUX__
    %define DEF_FT_STRCMP ft_strcmp
%else
    %define DEF_FT_STRCMP _ft_strcmp
%endif

; ret = ft_strcmp(char *str1, char *str2) ---> str1(first parameter) = rdi, str2(second parameter) = rsi

segment	.text
	global DEF_FT_STRCMP
										;		OPERATION					EXPLICATION
DEF_FT_STRCMP:
	mov		rax, 0						; rax = 0					init var to return at 0
	mov		rbx, 0						; rbx = 0					init register rbx to 0
	jmp		compare						; 							go to function compare

compare:
	mov		al, BYTE [rdi + rbx]		; al = *(rdi + rbx)			put the caracter of rdi at the index rbx on the register al (8 bits register)
	mov		bl, BYTE [rsi + rbx]		; bl = *(rsi + rbx)			put the caracter of rsi at the index rbx on the register bl (8 bits register)
	cmp		al, 0						; al - 0 = ?				compare value in register al with 0
	je		exit						; if (al = 0) -> exit		if al egual to 0 -> go to exit
	cmp		bl, 0						; bl - 0 = ?				compare value in register bl with 0
	je		exit						; if (bl = 0) -> exit		if bl egual to 0 -> go to exit
	cmp		al, bl						; al - bl = ?				compare value in register al with value in register bl
	jne		exit						; if (al != bl) -> exit		if al not egual to bl, go to exit
	inc		rbx							; rbx++						increment rbx
	jmp		compare						;							go to begin of function compare --> loop

exit:
	movzx	rax, al						; rax = al					copy value of al to rax with 0 in extension bits (bits that are bigger that the value)
	movzx	rbx, bl						; rbx = bl					copy value of al to rbx with 0 in extension bits (bits that are bigger that the value)
	sub		rax, rbx					; rax = rax - rbx			sub rbx to rax and put the return value in rax
	ret									; return (rax)				return value in rax