; Kevin Moody
; CS 2150 postlab 9
; Spring 2022
; binarySearch.s
	global binarySearch
	
	section .text
; Parameter 1 (rdi) pointer to int array
; Parameter 2 (rsi) integer representing beginning of array
; Parameter 3 (rdx) integer representing end of the array
; Parameter 4 (rcx) integer representing target element to find in array
; Return type (rax) is int, index of array that the target was found, or -1 if not

binarySearch:
	xor rax, rax		; Clear return register
search:
	cmp rdx, rsi		; Compare low to high
	jl end			; if high is less than low, jump to end
	mov r10, rdx		; Move low to r10
	add r10, rsi		; Add high to r10
	shr r10, 1		; Divide by 2, to get mid
	cmp [rdi+4*r10], ecx	; compare a[mid] to key
	je found
	jl lessThan		; If less, jump
	jg greaterThan		; If greater, jump

lessThan:
	mov rsi, r10		; Low = mid
	inc rsi		; Low += 1
	jmp search
greaterThan:
	mov rdx, r10		; High = mid
	dec rdx		; High -=1
	jmp search
found:
	mov rax, r10
	ret
end:
	mov rax, -1		; Not found, return 1
	ret
