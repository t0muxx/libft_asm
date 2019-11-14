%ifidn __OUTPUT_FORMAT__, elf64
	%define NAME ft_atoi
%else
	%define NAME _ft_atoi
%endif

section .text
global	NAME

NAME:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	xor rcx, rcx
	xor rax, rax
	mov byte [rsp-8], 0
	
skip_space:
	cmp byte [rdi+rcx], 0
	je end
	cmp byte [rdi+rcx], 0x20 ; space
	je increm	
	cmp byte [rdi+rcx], 0x09 ; space
	je increm	
	cmp byte [rdi+rcx], 0x0A ; space
	je increm	
	cmp byte [rdi+rcx], 0x0B ; space
	je increm	
	cmp byte [rdi+rcx], 0x0C ; space
	je increm	
	cmp byte [rdi+rcx], 0x0D ; space
	je increm

next:
	cmp byte [rdi+rcx], 0
	je end
	cmp byte [rdi+rcx], 0x2D
	je is_neg
	cmp byte [rdi+rcx], 0x2B	
	je is_pos

fill_ret:
	xor rbx, rbx
	cmp byte [rdi+rcx], 0x30
	jl end
	cmp byte [rdi+rcx], 0x39
	jg end
	cmp byte [rdi+rcx], 0
	je end
	imul rax, 10 ; x10
	mov bl, [rdi+rcx]
	sub bl, 48
	add rax, rbx
	inc rcx
	jmp fill_ret
		
is_pos:
	inc rcx
	jmp fill_ret

is_neg:
	mov byte [rsp-8], 1
	inc rcx
	jmp fill_ret

increm:
	inc rcx
	jmp skip_space

neg:
	neg rax
	cmp rax , -0x80000000
	jge end_bad
	leave
	ret

end:
	cmp byte [rsp-8], 1
	je neg
	cmp rax , 0x7fffffff
	jge end_bad
	leave
	ret

end_bad:
	xor rax, rax
	mov rax, -1
	leave
	ret
