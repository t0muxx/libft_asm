%ifidn __OUTPUT_FORMAT__, elf64
	%define NAME ft_isprint
%else
	%define NAME _ft_isprint
%endif

section .text
global NAME 

NAME:
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
