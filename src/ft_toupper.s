global _ft_toupper

section .text

_ft_toupper:
	cmp rdi, 0x61
	jl false
	cmp rdi, 0x7a
	jle true

false:
	xor rax, rax
	mov rax, rdi
	ret

true:
	xor rax, rax
	mov rax, rdi
	sub rax, 32
	ret
