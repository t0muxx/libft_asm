%ifidn __OUTPUT_FORMAT__, elf64
	%define NAME ft_isalnum
%else
	%define NAME _ft_isalnum
%endif

global NAME 

section .text

NAME:
	cmp rdi, 0x30
	jl false
	cmp rdi, 0x39
	jle true
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
