global _ft_isascii

section .text

_ft_isascii:
	cmp rdi, 0x00
	jl false
	cmp rdi, 0x7f
	jle true

false:
	xor rax,rax
	ret

true:
	xor rax, rax
	mov rax, 1
	ret
