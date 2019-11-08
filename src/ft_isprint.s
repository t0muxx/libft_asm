global _ft_isprint

section .text

_ft_isprint:
	cmp rdi, 0x20
	jl false
	cmp rdi, 0x7e
	jle true

false:
	xor rax,rax
	ret

true:
	xor rax, rax
	mov rax, 1
	ret
