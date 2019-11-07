global _ft_isdigit

section .text

_ft_isdigit:
	cmp rdi, 0x30
	jl false
	cmp rdi, 0x39
	jle true

false:
	xor rax,rax
	ret

true:
	xor rax, rax
	mov rax, 1
	ret
