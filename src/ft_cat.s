%ifidn __OUTPUT_FORMAT__, elf64
	%define NAME ft_cat
	%define SYS_READ 0
	%define SYS_WRITE 1
	%define MEMSET memset
	%define PLT wrt ..plt
%else
	%define NAME _ft_cat
	%define PLT
	%define MEMSET _memset
	%define SYS_READ 0x2000003
	%define SYS_WRITE 0x2000004
%endif

section .text
global	NAME
extern MEMSET

NAME:
	push rbp
	mov rbp, rsp
	sub rsp, 1024
	mov r9, rdi

read_loop:
	lea rdi, [rbp - 1024]
	mov rsi, 0
	mov rdx, 1024
	call MEMSET PLT ; memset(stack, 0, 1024)
	mov rax, SYS_READ
	mov rdi, r9
	lea rsi, [rbp - 1024] 
	mov rdx, 1024
	syscall
	mov r8, rax
	cmp rax, 0
	jle end
	jnc end
	jmp print

print:
	mov rax, SYS_WRITE
	mov rdi, 0
	lea rsi, [rbp - 1024]
	mov rdx, r8
	syscall
	xor r8, r8
	jmp read_loop
	
end:
	leave
	ret
