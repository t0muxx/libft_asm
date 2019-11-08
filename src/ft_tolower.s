%ifidn __OUTPUT_FORMAT__, elf64
	%define NAME ft_tolower
%else
	%define NAME _ft_tolower
%endif

global NAME 

section .text

NAME:
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
