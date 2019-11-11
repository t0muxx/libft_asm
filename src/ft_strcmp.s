%ifidn __OUTPUT_FORMAT__, elf64
	%define NAME ft_strcmp
%else
	%define NAME _ft_strcmp
%endif

global	NAME

section .text

NAME:
	xor rcx, rcx
	
loop:
	xor rax, rax
	xor rbx, rbx
	mov al, [rdi + rcx]
	mov bl, [rsi + rcx]
	cmp al, bl
	jne end
	cmp byte al, 0
	je end
	cmp byte bl, 0
	je end
	inc rcx
	jmp loop

end:
	sub rax, rbx
	ret
