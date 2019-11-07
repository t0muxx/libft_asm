global	_ft_bzero

section .text

_ft_bzero:
	mov	rbx, rdi
	mov rcx, rsi

loop:
	mov byte [rbx], 0
	inc rbx
	dec rcx
	cmp rcx, 0
	je end
	jmp loop


end:
	ret
