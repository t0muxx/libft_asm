%ifidn __OUTPUT_FORMAT__, elf64
	%define NAME ft_puts
	%define SYS_WRITE 1
%else
	%define NAME _ft_puts
	%define SYS_WRITE 0x2000004
%endif

section .text
global NAME 

NAME:
	xor rcx, rcx

check_len:
	cmp	byte [rdi + rcx], 0
	je print
	inc rcx
	jmp check_len

print:
	mov rsi, rdi
	xor rdi, rdi
	mov rdi, 1
	mov rdx, rcx
	mov rax, SYS_WRITE
	syscall
	cmp rax, 0
	jge true
	jmp false

true:
	mov rax, SYS_WRITE
	mov byte [rsp-4], 0x0a
	lea rsi, [rsp-4]
	mov edx, 1
	syscall
	cmp rax, 0
	jle false
	mov rax, 0xa
	ret

false:
	xor rax, rax
	mov rax, -1
	ret
