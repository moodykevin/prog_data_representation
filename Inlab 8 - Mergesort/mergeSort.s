; Kevin Moody			Found examples of MergeSort online
; CS 2150 In-Lab 8		that I used for inspiration and adapted to fit x86
; Spring 2018
; mergeSort.s	

	global mergeSort
	global merge

	section .text


; Parameter 1 is a pointer to the int array 
; Parameter 2 is the left index in the array 
; Parameter 3 is the right index in the array
; Return type is void 
mergeSort:

	; Implement mergeSort here		MERGESORT(rdi,  rsi,   rdx)
	cmp rsi, rdx		; Compare rsi and rdx
	je end			; If equal (base case, recursion complete), end
	push rsi		; Store rsi (left index)
	push rdx		; Store rdx (right index)
	
	xor rax, rax		; Set rax to 0
	add rax, rsi		; Add rsi to rax
	add rax, rdx		; Add rdx to rax
	
	xor rdx, rdx		; Set RDX:RBX to 0
	xor rcx, rcx		; to make sure divison works
	xor rbx, rbx		;
	
	mov r15, 2		; Move value 2 to any register
	idiv r15		; Divide by 2
	
	mov rdx, rax		; move MIDPOINT to rdx
	
	push rsi		; Store	mergesort(rdi, L index, MIDPOINT)
	push rdx		;   |
	push rax		;   |
	push rcx		;   v
	call mergeSort		;	Call Mergesort(rdi, rsi, rdx)
	pop rcx		;   ^
	pop rax		;   |
	pop rdx		;   |
	pop rsi		; Restore
	
	mov rsi, rdx		; Move MIDPOINT to rsi
	inc rsi		; Add 1
	pop rdx		; Pop rdx from beginning (aka R index)
	
	push rsi		; Store	mergesort(rdi, MIDPOINT+1, R index)
	push rdx		;   |
	push rax		;   |
	push rcx		;   v
	call mergeSort		;	Call Mergesort(rdi, rsi, rdx)
	pop rcx		;   ^
	pop rax		;   |
	pop rdx		;   |
	pop rsi		; Restore
	
	mov rcx, rdx		; Move R index to rcx
	mov rdx, rsi		; Move MIDPOINT+1 to rdx
	dec rdx		; Change back to MIDPOINT
	pop rsi		; Pop rsi from beginning (aka L index)
	
	push rsi		; Store	merge(rdi, L index, MIDPOINT, R index)
	push rdx		;   |
	push rcx		;   |
	push rax		;   |
	push r10		;   |
	push r9		;   v
	call merge		; 	Call Merge: (rdi, rsi, rdx, rcx)
	pop r9			;   ^
	pop r10		;   |
	pop rax		;   |
	pop rcx		;   |
	pop rdx		;   |
	pop rsi		; Restore

end:
	ret



; Parameter 1 is a pointer to the int array 
; Parameter 2 is the left index in the array
; Parameter 3 is the middle index in the array 
; Parameter 4 is the right index in the array
; Return type is void 
merge:
	; Save callee-save registers
	; Store local variables 
	push rbx			; int i
	push r12			; int j
	push r13			; int k
	push r14			; int n1
	push r15			; int n2
	
	mov r14, rdx			; n1 = mid - left + 1
	sub r14, rsi
	inc r14

	mov r15, rcx			; n2 = right - mid 
	sub r15, rdx

	lea r11, [r14+r15]		; r11 = rsp offset = 4(n1 + n2)
	lea r11, [4*r11]		
	sub rsp, r11			; allocate space for temp arrays

	mov rbx, 0			; i = 0
	mov r12, 0			; j = 0
	
; Copy elements of arr[] into L[]	
copyLloop:
	cmp rbx, r14			; is i >= n1?
	jge copyRloop
					; L[i] = arr[left + i]
	lea r10, [rsi+rbx]		
	mov r10d, DWORD [rdi+4*r10]	; r10 = arr[left + i]
	mov DWORD [rsp+4*rbx], r10d	; L[i] = r10
	inc rbx				; i++
	jmp copyLloop

; Copy elements of arr[] into R[]
copyRloop:
	cmp r12, r15			; is j >= n2?
	jge endcopyR
 					; R[j] = arr[mid + 1 + j]
	lea r10, [rdx+r12+1]	
	mov r10d, DWORD [rdi+4*r10]	; r10 = arr[mid + 1 + j]
	lea rax, [r12+r14]		
	mov DWORD [rsp+4*rax], r10d	; R[j] = r10
	inc r12				; j++
	jmp copyRloop

endcopyR:	
	mov rbx, 0			; i = 0
	mov r12, 0			; j = 0
	mov r13, rsi			; k = left

; Merge L[] and R[] into arr[]
mergeLoop:
	cmp rbx, r14			; is i >= n1 or j >= n2?
	jge loopL
	cmp r12, r15
	jge loopL
	lea r10, [r12+r14]
	mov r10d, DWORD [rsp+4*r10] 	; r10d = R[j]
	cmp DWORD [rsp+4*rbx], r10d	; is L[i] <= R[j]?
	jle if
	mov DWORD [rdi+4*r13], r10d	; arr[k] = R[j]
	inc r12				; j++
	jmp endif 
if:
	mov r10d, DWORD [rsp+4*rbx] 
	mov DWORD [rdi+4*r13], r10d	; arr[k] = L[i] 
	inc rbx				; i++
endif:	
	inc r13				; k++	
	jmp mergeLoop
	
; Copy elements of L[] into arr[]
loopL:				
	cmp rbx, r14			; is i >= n1?
	jge loopR
	mov r10d, DWORD [rsp+4*rbx] 
	mov DWORD [rdi+4*r13], r10d	; arr[k] = L[i]
	inc rbx				; i++
	inc r13				; k++
	jmp loopL

; Copy elements of R[] into arr[]
loopR:	
	cmp r12, r15			; is j >= n2?
	jge endR
	lea r10, [r12+r14]
	mov r10d, DWORD [rsp+4*r10] 	
	mov DWORD [rdi+4*r13], r10d	; arr[k] = R[j]

	inc r12				; j++
	inc r13				; k++
	jmp loopR
	
endR:
	; deallocate temp arrays
	; restore callee-save registers
	add rsp, r11	
	pop r15			
	pop r14
	pop r13
	pop r12
	pop rbx
	ret
