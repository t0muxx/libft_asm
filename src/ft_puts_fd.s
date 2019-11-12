%ifidn __OUTPUT_FORMAT__, elf64
	%define NAME ft_puts_fd
	%define SYS_WRITE 1
%else
	%define NAME _ft_puts_fd
	%define SYS_WRITE 0x2000004
%endif

section .text
global NAME 

NAME:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	xor rcx, rcx
	mov [rsp-8], rdi
	mov [rsp-16], rsi

check_len:
	cmp	byte [rdi + rcx], 0
	je print
	inc rcx
	jmp check_len

print:
	mov rsi, [rsp-8]
	xor rdi, rdi
	mov rdi, [rsp-16]
	mov rdx, rcx
	mov rax, SYS_WRITE
	syscall
	cmp rax, 0
	jge true
	jmp false

true:
	mov     rax, SYS_WRITE
	xor [rsp-4], dword 0
	mov byte [rsp-4], 0x0a
	lea rsi, [rsp-4]
	mov edx, 1
	syscall
	cmp rax, 0
	jle false
	leave
	ret

false:
	xor rax, rax
	mov rax, -1
	leave
	ret
