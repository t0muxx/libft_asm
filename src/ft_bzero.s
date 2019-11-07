global	_ft_bzero

section .text

_ft_bzero:
	mov	rbx, rdi
	mov rcx, rsi

loop:
	cmp rcx, 0
	jle end
	mov byte [rbx], 0
	inc rbx
	dec rcx
	jmp loop

end:
	ret
