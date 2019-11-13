%ifidn __OUTPUT_FORMAT__, elf64
	%define NAME ft_cat
	%define SYS_READ 0
	%define SYS_WRITE 1
	%define MEMSET ft_memset
	%define PLT wrt ..plt
%else
	%define NAME _ft_cat
	%define PLT
	%define MEMSET _ft_memset
	%define SYS_READ 0x2000003
	%define SYS_WRITE 0x2000004
%endif

section .text
global	NAME
extern MEMSET

NAME:
	push rbp
	mov rbp, rsp
	sub rsp, 1040
	mov [rbp-8], rdi ; fd

read_loop:
	lea rdi, [rbp - 1040]
	mov rsi, 0
	mov rdx, 1024
	call MEMSET PLT ; memset(stack, 0, 1024)
	mov rax, SYS_READ
	mov rdi, [rbp-8]
	lea rsi, [rbp - 1040] 
	mov rdx, 1024
	clc
	syscall
	mov [rbp-16], rax ; byte read
	jc end
	cmp rax, 0
	jle end
	jmp print

print:
	mov rax, SYS_WRITE
	mov rdi, 0
	lea rsi, [rbp - 1040]
	mov rdx, [rbp-16]
	syscall
	xor r8, r8
	jmp read_loop
	
end:
	leave
	ret
