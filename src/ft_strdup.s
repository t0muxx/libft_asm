%ifidn __OUTPUT_FORMAT__, elf64
	%define NAME ft_strdup
	%define PLT wrt ..plt
	%define MALLOC malloc
%else
	%define NAME _ft_strdup
	%define PLT
	%define MALLOC _malloc
%endif

section .text
global	NAME
extern	MALLOC

NAME:
	push rbp
	mov rbp, rsp
	sub rsp, 32
	push rdi ; saved source
	xor rax, rax
	push rax
	cld
	mov rcx, -1
	repne scasb
	not rcx
	sub rcx, 1

allocate:
	mov rdi, rcx
	inc rdi
	push rdi
	xor rax, rax
	push rax
	call MALLOC PLT
	cmp rax, 0
	je false
	
copy:
	mov rdi, rax
	pop rcx
	pop rcx
	pop rsi
	pop rsi
	cld
	rep movsb
	leave
	ret

false:
	xor rax, rax
	leave
	ret
