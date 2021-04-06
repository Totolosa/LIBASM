%ifdef	__LINUX__
    %define DEF_FT_STRLEN ft_strlen
%else
    %define DEF_FT_STRLEN _ft_strlen
%endif

; ret = ft_strlen(char *str) ---> str(first parameter) = rdi

global DEF_FT_STRLEN

										;			OPERATION						EXPLICATION
DEF_FT_STRLEN:
	mov		rax, 0						; rax = 0							init var to return at 0
	jmp		count						; 									go to function count

count:
	cmp		BYTE [rdi + rax], 0			; *(rdi + rax) - 0 = ?				compare the byte at the adress pointed by (rdi + rax) to 0
	je		exit						; if (*(rdi + rax) = 0) -> exit		if *(rdi + rax) egual to 0, go to function exit
	inc		rax							; rax++								increment rax
	jne		count						; if (*(rdi + rax) != 0) -> count	if *(rdi + rax) not egual to 0 -> go back to function count, loop !

exit:
	ret									; return (rax)									return value of rax