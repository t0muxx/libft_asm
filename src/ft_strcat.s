global _ft_strcat

section .text
	
_ft_strcat:
	mov rax, rdi
	cmp rdi, 0
	je end
	cmp rsi, 0
	je end

loop_s1:
	cmp byte [rdi], 0
	je loop_cat
	inc rdi
	jmp loop_s1

loop_cat:
	cmp byte [rsi], 0
	je end
	mov cl, byte [rsi]
	mov	byte [rdi], cl
	inc rsi
	inc rdi
	jmp loop_cat

end_cat:
	mov byte [rdi], 0

end:
	ret
