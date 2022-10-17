; Kevin Moody			
; CS 2150 In-Lab 8		
; Spring 2018
; linearSearch.s	

	global linearSearch

	section .text

; Parameter 1 is a pointer to the int array 	(rdi)
; Parameter 2 is the size of the array 	(rsi)
; Parameter 3 is the target element to find	(rdx)
; Return type is void 
linearSearch:
	xor rax, rax		; Clear return address
	xor r10, r10		; Clear accumulator variable
start:
	cmp rsi, 0		; Compare size to 0
	je didnt_find		; If 0, not found, and jump to end
	dec rsi		; Dec size by 1
	cmp edx, [rdi+4*r10]	; Compare 32bit version of rdx to a[i]+4*k
	je found		; If equal, found, jump to end
	inc r10		; Increment accumulator
	jmp start		; Loop
found:
	mov rax, r10		; Move r10 accumulator to return
	ret
didnt_find:
	mov rax, -1		; Move -1 to return
	ret
