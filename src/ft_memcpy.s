%ifidn __OUTPUT_FORMAT__, elf64
	%define NAME ft_memcpy
%else
	%define NAME _ft_memcpy
%endif

section .text
global	NAME

NAME:
	push rdi
	mov rcx, rdx
	cld
	rep movsb
	pop rax
	ret
