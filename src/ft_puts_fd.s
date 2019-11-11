%ifidn __OUTPUT_FORMAT__, elf64
	%define NAME ft_puts_fd
%else
	%define NAME _ft_puts_fd
%endif

global NAME 

section .text

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
%ifidn __OUTPUT_FORMAT__, elf64
	mov rax, 1
%endif
%ifidn __OUTPUT_FORMAT__, macho64
	mov     rax, 0x2000004
%endif
	syscall
	cmp rax, 0
	jge true
	jmp false

true:
%ifidn __OUTPUT_FORMAT__, elf64
	mov rax, 1
%endif
%ifidn __OUTPUT_FORMAT__, macho64
	mov     rax, 0x2000004
%endif
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
