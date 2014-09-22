	.global _start
	
_start:
	MOV R0, #0         @ set the output to zero 
	MOV R1, #0         @ set counter to zero 
	MOV R2, #111       @ A=111 
	MOV R3, #5         @ B=5   
	CMP R2, R3         @ compares the values of A and B
	BGE case_subtr     @ Branch if A and B are greater or equal

case_subtr:
	SUB R2, R2, R3       @ R2=R2-R3
	ADD R1, R1, #1       @ counter += 1
	CMP R2, R3           @ compares the values of A and B once again
	BGE case_subtr       @ Loop
	B end			     @Branch to end of program
	
end:
	MOV R0, R2			 @Moves row 1 to row 0 for output of answer
	MOV R7, #1
	SWI 0