.data
.balign 4
message_1 : .asciz "type a numerator:"
.balign 4
message_2 : .asciz "type a denominator:"
.balign 4
message_3 : .asciz "%d divide by %d is %d\n"
.balign 4
message_4 : .asciz "The remainder is %d\n"
.balign 4
scan_pattern : .asciz "%d"
.balign 4
number_num : .word 0
.balign 4
number_den : .word 0
.balign 4
return : .word 0
.balign 4
return2 : .word 0

.text
division:
    push {lr}
	ldr r1, address_of_return2
	str lr, [r1]

        mov r0, #0
        mov r4, #1
        mov r5, r3
        mov r1, r2
divMod:
        cmp r1, r3
        beq case_equal
        bmi end
        pop {lr}
        bx lr          @end it if r1<r3
scaleLeft:
    push {lr}
        mov r4, r4, lsl#1       @div counter
        mov r5, r5, lsl#1       @Remainder sub
        cmp r1, r5
        bge scaleLeft
	mov r4, r4, lsr#1
	mov r5, r5, lsr#1
    pop {lr}
    bx lr
addSub:
        push {lr}
        add r0, r0, r4
        sub r1, r1, r5
        pop {lr}
        bx lr
scaleRight:
        push {lr}
        mov r4, r4, lsr#1
        mov r5, r5, lsr#1
        cmp r1, r5
        bmi scaleRight
        cmp r4, #1
        bge addSub
end:
	ldr lr, address_of_return2
	ldr lr, [lr]
	bx lr
address_of_return2 : .word return2
    pop {lr}
    bx lr
case_equal:
        mov r0, #1
        b end

.global main
main:
    push {lr}
	ldr r1, address_of_return
	str lr, [r1]
	ldr r0, address_of_message_1
	bl printf
	ldr r0, address_of_scan_pattern
	ldr r1, address_of_number_num
	bl scanf
	ldr r0, address_of_message_2
	bl printf
	ldr r0, address_of_scan_pattern
	ldr r1, address_of_number_den
	bl scanf


	ldr r0, address_of_number_num
	ldr r2, [r0]
	ldr r0, address_of_number_den
	ldr r3, [r0]
	bl division

	mov r3, r0
	mov r6, r1
	ldr r1, address_of_number_num
	ldr r1, [r1]
	ldr r2, address_of_number_den
	ldr r2, [r2]
	ldr r0, address_of_message_3
	bl printf
	mov r1, r6
	ldr r0, address_of_message_4
	bl printf
    ldr lr, address_of_return
	ldr lr, [lr]
	bx lr
    pop {lr}
    bx lr
address_of_message_1 : .word message_1
address_of_message_2 : .word message_2
address_of_message_3 : .word message_3
address_of_message_4 : .word message_4
address_of_scan_pattern : .word scan_pattern
address_of_number_num : .word number_num
address_of_number_den : .word number_den
address_of_return :.word return

.global printf
.global scanf