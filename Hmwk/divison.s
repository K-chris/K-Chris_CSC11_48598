
.text
.global main
main:
	MOV R0, #0         @ set counter to zero
	MOV R2, #11        @ A=111
        MOV R1, R2         @ R1=A
	MOV R3, #5         @ B=
	MOV R4, #0	       @ Swap if value =1
	CMP R1, R3         @ compares the values of A and B
	BGE case_subtr     @ Branch if A and B are greater or equal
	B end
case_subtr:
	SUB R1, R1, R3       @ R2=R2-R3
	ADD R0, R0, #1       @ counter += 1
	CMP R1, R3           @ compares the values of A and B once again
	BGE case_subtr       @ Loop
    CMP R4, #0           @compare for switch, switch if =1
    BEQ end              @Branch to end of program
	B case_swi
case_swi:
    MOV R5, R0
    MOV R0, R1
    MOV R1, R5

end:
	bx lr
