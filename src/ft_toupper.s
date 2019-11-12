%ifidn __OUTPUT_FORMAT__, elf64
	%define NAME ft_toupper
%else
	%define NAME _ft_toupper
%endif

section .text
global NAME 

NAME:
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
