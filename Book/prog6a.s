/* Preform R0=R1+R2 */
	.global _start
_start:
	MOV R1, #50
	MOV R2, #316
	ADDS R0, R1, R2

	MOV R7, #1
	SWI 0
