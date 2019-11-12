%ifidn __OUTPUT_FORMAT__, elf64
	%define NAME ft_bzero
%else
	%define NAME _ft_bzero
%endif

section .text
global	NAME

NAME:
	mov	rbx, rdi
	mov rcx, rsi

loop:
	cmp rcx, 0
	jle end
	mov byte [rbx], 0
	inc rbx
	dec rcx
	jmp loop

end:
	ret
