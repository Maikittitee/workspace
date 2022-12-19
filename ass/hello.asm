section .text
	global _start

section .data
	msg db "Hello world!", 0x30 ;comment
	len equ $ - msg
	
_start:
	;sys_write
	mov ecx, msg 
	mov edx, len 
	mov ebx, 1 
	mov eax,4
	int 0x80

	; sys_exit
	mov ebx, 0
	mov eax, 1
	int 0x80


