; Kevin Moody
; CS 2150 prelab 9
; Spring 2022
; threexplusone.s

	global threexplusone
	
	section .text
	
; Parameter 1 is the interger having the conjecture called on it (rdi)
; Return type is int (rax) how many steps necessary to reach one

threexplusone:
	; xor rax, rax		; Clear return
start2:
	cmp rdi, 1		; Base case: n = 1
	je recursion_end	; Jump to end
	mov r10, rdi		; Move rdi to another register
	shr r10, 1		; Divide by 2
	shl r10, 1		; Multiply by 2
	cmp r10, rdi		; If same as original rdi, that means last bit was 0
	je even		; Therefore even, so we jump to even
	jmp odd		; Otherwise jump to odd
even:
	shr rdi, 1		; Divide by 2
	call threexplusone	; Recursively call
	inc rax		; Add 1
	ret			; Return
odd:
	mov r10, rdi		; Move rdi to r10
	shl rdi, 1		; Multiple rdi by 2
	add rdi, r10		; Add r10 to rdi (multiplying it by three)
	inc rdi		; Add one
	call threexplusone	; Recursively call
	inc rax		; Add 1
	ret			; Return
recursion_end:
	mov rax, 0		; Return 0
	ret
