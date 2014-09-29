.text
	.global _start
_start:
	mov r2, #111
	mov r3, #5
	mov r0, #0
	mov r1, r2
	mov r4, #0
	mov r5, #0
	mov r6, #0
	mov r7, #0
	mov r8, #10
	mov r9, #0
	cmp r1, r3
	blt _swap
_scale:
	cmp r6, #1	@ scale r6
	mul r7, r3, r6  @ subtraction factor
	mul r9, r7, r8  @ next subtraction factor to test
	b _next2
_next2:
	mul r6, r6, r8	@ scale factor
	mul r7, r3, r6	@ subtraction factor
	mul r9, r7, r8  @ next subtraction factor to test
	cmp r1, r9
	bge _next2
_next3:
	add r0, r0, r6	@ Increase by scale
	sub r1, r1, r7	@ Subtract by b*scale
	cmp r1, r7
	bge _next3
_next4:
	cmp r6, #1
	bge _scale
_swap:
	cmp r4, #0      @ Check if r4 is set
        beq _end        @ end program if r4 is 0
        mov r5, r0      @ if r4 is set, switch r0 and r1
        mov r0, r1
        mov r1, r5
_end:
	mov r7, #1
	swi 0