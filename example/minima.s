section .text
	global start
	global _main

; Label start.
start:
	call _main
	ret

_main:
	ret
