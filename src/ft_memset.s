%ifidn __OUTPUT_FORMAT__, elf64
	%define NAME ft_memset
%else
	%define NAME _ft_memset
%endif

global	NAME

section .text

NAME:
    push rbp
    mov rbp, rsp
	sub rsp, 16
	push rdi
	mov rax, rsi
	mov rcx, rdx
	cld
	rep stosb
	pop rax
	leave
	ret	
