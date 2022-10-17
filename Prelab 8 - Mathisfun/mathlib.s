; mathlib.s

	global product
	global power
	section .text

product:
	; Subroutine body
	xor	rax, rax
start1:
	cmp	rsi, 0		; does rsi (second int) == 0?
	je	done		; if so, return value for 0
	dec	rsi		; decrease second int by one
	add	rax, rdi	; add rdi to rax
	jmp	start1		; Jump back to start, to check and add rdi again
done:	
	ret			; Return rax
	
	
power:
	; Subroutine body
	xor	rax, rax	; Reset rax, just to be cautious
start2:
	mov	rax, rdi	; move rdi to rax register
	dec	rsi		; decrease rsi by one
	cmp	rsi, 0		; compare rsi to 0
	je	recursion_end	; jump to the end
	call	power		; call power (recursive)
	mov	rsi, rax	; move rax to rsi
	call product		; call product
recursion_end:
	ret			; Return value of rax
