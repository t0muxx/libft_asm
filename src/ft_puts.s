%ifidn __OUTPUT_FORMAT__, elf64
	%define NAME ft_puts
%else
	%define NAME _ft_puts
%endif

global NAME 

section .text

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
	mov byte [rsp-4], 0x0a
	lea rsi, [rsp-4]
	mov edx, 1
	syscall
	cmp rax, 0
	jle false
	ret

false:
	xor rax, rax
	mov rax, -1
	ret
