global _ft_isalpha

section .text

_ft_isalpha:
	cmp rdi, 0x41
	jl false
	cmp rdi, 0x5A
	jle true
	cmp rdi, 0x61
	jl false
	cmp rdi, 0x7A
	jle true
	jmp false

false:
	xor rax,rax
	ret

true:
	xor rax, rax
	mov rax, 1
	ret
