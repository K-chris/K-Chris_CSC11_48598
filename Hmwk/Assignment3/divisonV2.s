.text
.global main
main:
	MOV R0, #0         @ set counter to zero
    MOV R2, #111       @ A=R2
    MOV R1, R2             @ R1=A
	MOV R3, #5         @ B=
	MOV R4, #0         @ Swap if value =1
	MOV R5, #0	       @r5 = r6(1) * r8(10)
	MOV R6, #0	       @r6=1
	MOV R7, #0  	   @R7= r3 * r6
	MOV R8, #10        @ r8 =10
	MOV R9, #0	       @r9 = r7 * r8
case_compare:
	CMP R1, R3         @ compares the values of A and B
	BLT case_swi       @ Branch if A and B are less than
	MOV R6, #1
case_scale:
	MUL R7, R3, R6     @ = R3 * 1
	MUL R9, R7, R8     @ = R7 * 10
	CMP R1, R9
	BLT case_add
	MUL R5, R6, R8
	MOV R6, R5
	B case_scale

case_add:
	ADD R0, R0, R6
	SUB R1, R1, R7
	CMP R1, R7
	BGT case_add
	B case_compare

case_swi:
	CMP R4, #0
	BEQ end
    MOV R5, R0
    MOV R0, R1
    MOV R1, R5

end:
	bx lr
