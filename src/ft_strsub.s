%ifidn __OUTPUT_FORMAT__, elf64
	%define NAME ft_strsub
	%define PLT wrt ..plt
	%define MALLOC malloc
%else
	%define NAME _ft_strsub
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
	xor rax, rax
	cmp rdi, 0
	je end
	push rdi ; s
	push rsi ; start
	push rdx ; len

mall:
	mov rdi, rdx
	inc rdi
	call MALLOC PLT
	cmp rax, 0
	je end
	xor r9, r9 ; i = 0;
	pop rdx
	pop rsi
	pop rdi
	add rdi, rsi

loop:
	cmp byte [rdi+r9], 0
	je add_backslash
	cmp r9, rdx
	jge add_backslash
	mov bl, [rdi+r9]
	mov [rax+r9], bl
	inc r9
	jmp	loop

add_backslash:
	mov bl, 0
	mov [rax+r9], bl
	mov rax, rdi

end:
	leave
	ret
