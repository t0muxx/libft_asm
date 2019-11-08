global _ft_tolower

section .text

_ft_tolower:
	cmp rdi, 0x41
	jl false
	cmp rdi, 0x5a
	jle true

false:
	xor rax, rax
	mov rax, rdi
	ret

true:
	xor rax, rax
	mov rax, rdi
	add rax, 32
	ret
