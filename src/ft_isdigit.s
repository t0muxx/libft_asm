%ifidn __OUTPUT_FORMAT__, elf64
	%define NAME ft_isdigit
%else
	%define NAME _ft_isdigit
%endif

global NAME 

section .text

NAME:
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
