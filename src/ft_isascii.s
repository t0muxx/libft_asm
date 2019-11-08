%ifidn __OUTPUT_FORMAT__, elf64
	%define NAME ft_isascii
%else
	%define NAME _ft_isascii
%endif

global NAME 

section .text

NAME:
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
