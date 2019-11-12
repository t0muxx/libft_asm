%ifidn __OUTPUT_FORMAT__, elf64
	%define NAME ft_strlen
%else
	%define NAME _ft_strlen
%endif

section .text
global	NAME

NAME:
	xor al, al
	cld
	xor rcx, rcx
	mov rcx, -1
	repne scasb
	je end

end:
	not rcx
	sub rcx, 1
	xor rax, rax
	mov rax, rcx
	ret	
