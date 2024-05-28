<<<<<<< HEAD
<<<<<<< HEAD
;noahlr2, gsayy2
;
;DESCRIPTION: This code evaluates postfix expressions by utilizing stacks.
;This program accepts any number or algebra function (* / + - ^) and calculates
;a solution. This code throws errors if a not accepted char is submitted or the 
;input does not match the reverse polish notation.
.ORIG x3000	
;your code goes here
AND R0, R0, #0
AND R1, R1, #0 	;These three lines clear registers
AND R2, R2, #0

READNEXT GETC ;READ KEYBOARD INPUT
OUT ; PRINT OUTPUT 
ADD R2, R0, #0 ;Sets R2 to equal R0 to make algebra easier

;IS IT '='?
LD R1, HEXEQUALS ;Loads hex of '=' char into R1
JSR INVVAR ;2s compliment and adds R1 + R2
BRnp MAYBESPACE ;breaks to space check 

;EXACTLY 1 RESULT ON THE STACK?
;R4 HAS STACK TOP, SHOULD BE AT x4000
AND R0, R0, #0 ;clears R0
LD R6, STACK_TOP
LD R4, STACK_START ;loads top and start into R6/R4
NOT R6, R6
ADD R6, R6, #1 ;twos compliment of r6
ADD R4, R4, #-1
ADD R6, R4, R6 ;checks to see if there is only 1 char in stack
BRnp INVALIDMESSAGE ;jumps to invalid message

;POP AND PRINT RESULT
JSR POP ;pops one digit to r0
AND R3, R3, #0
ADD R3, R0, #0 ;sets r0 equal to a bunch of registers 
ADD R6, R3, #0
AND R1, R1, #0 ; bit counter
AND R2, R2, #0 ;digit counter

ADD R2, R2, #-4 ;sets digit counnter to under 4
CHECKCOUNT BRzp DONE

;init digit and bit counter below 
AND R0, R0, #0  ;digit
ADD R1, R1, #-4

TESTER BRzp OVER4BIT
ADD R0, R0, R0
ADD R3, R3, #0 ;checks r3 MSB
BRzp JUMP
ADD R0, R0, #1
JUMP ADD R3, R3, R3 ;bitshift r3
ADD R1, R1, #1
BR TESTER
; This will be the false branch of got <4 bits from R3

OVER4BIT ADD R0, R0, #-9

BRnz ADD0
ADD R0, R0, #7
;these are all offsets for num and chars

ADD0 ADD R0, R0, #9
ADD R0, R0, XF  
ADD R0, R0, XF
ADD R0, R0, XF
ADD R0, R0, #3



OUT
ADD R2, R2, #1 ;adds 1 to hex digit counter
BR CHECKCOUNT

;STORE RESULT IN R5
DONE AND R5, R5, #0
ADD R5, R6, #0 ;stores result in R5 and stops
BR HALTING

;IS IT SPACE? 
MAYBESPACE
JSR SETUP ;sets up registers
LD R1, HEXSPACE  ;Loads hex of ' ' char into R1
JSR INVVAR ;2s compliment and adds R1 + R2
BRz READNEXT 

;IS IT '0-9'?
MAYBENUM
JSR SETUP ;sets up registers
LD R1, HEXNUM ;Loads hex of nums char into R1
JSR INVVAR ;2s compliment and adds R1 + R2
BRn MAYBEOP
ADD R2, R2, #-10 ;offset to make sure all digits are negative
BRzp MAYBEOP


;SUBTRACT 0
LD R1, HEXNUM ;Loads hex of '0' char into R1
NOT R1, R1
ADD R1, R1, #1
ADD R0, R1, R0 ;subtract 0 from r0

;PUSH ONTO STACK
JSR PUSH 
BR READNEXT ;pushes r0 onto stack (num)


;IS IT OPERATOR?
MAYBEOP
JSR SETUP ;sets up registers
LD R1, HEXADD ;Loads hex of '+' char into R1
JSR INVVAR ;2s compliment and adds R1 + R2
BRz DOADD

JSR SETUP
LD R1, HEXSUB ;Loads hex of '-' char into R1
JSR INVVAR ;2s compliment and adds R1 + R2
BRz DOSUB

JSR SETUP
LD R1, HEXMUL ; Loads hex of '*' char into R1
JSR INVVAR ;2s compliment and adds R1 + R2
BRz DOMUL

JSR SETUP
LD R1, HEXPWR ;Loads hex of '^' char into R1
JSR INVVAR ;2s compliment and adds R1 + R2
BRz DOPWR

JSR SETUP
LD R1, HEXDIV ;Loads hex of '/' char into R1
JSR INVVAR ;2s compliment and adds R1 + R2
BRnp INVALIDMESSAGE


;IS THERE 2 IN STACK/ PERF OPERATION
 
;AT 3FFF
JSR INSTACK2   ;These check if theres 2 in stack
JSR POP			;sets up registers for ops
ADD R4, R0, #0
JSR POP
ADD R3, R0, #0
JSR DIV
BR PUSHTIME

DOADD
JSR INSTACK2
JSR POP ;sets up registers for ops
ADD R4, R0, #0
JSR POP
ADD R3, R0, #0
JSR PLUS

BR PUSHTIME

DOSUB
JSR INSTACK2
JSR POP ;sets up registers for ops
ADD R4, R0, #0
JSR POP
ADD R3, R0, #0
JSR MIN
BR PUSHTIME

DOPWR
JSR INSTACK2
JSR POP ;sets up registers for ops
ADD R4, R0, #0
JSR POP
ADD R3, R0, #0
JSR EXP
BR PUSHTIME

DOMUL
JSR INSTACK2
JSR POP ;sets up registers for ops
ADD R4, R0, #0
JSR POP
ADD R3, R0, #0
JSR MUL
BR PUSHTIME




;PUSH ONTO STACK 
PUSHTIME JSR PUSH ;pushes to stack(new char)
BR READNEXT






;PRINT INVALID MESSAGE
INVALIDMESSAGE LEA R0, ERROR ;prints error message
 PUTS

HALTING HALT




;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;R3- value to print in hexadecimal
PRINT_HEX
;init digit and bit counter below 
RET

 

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;R0 - character input from keyboard
;R6 - current numerical output
;
;
EVALUATE

;your code goes here


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
PLUS	
;your code goes here
	ADD R0, R3, R4
	RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
MIN	
;your code goes here
	NOT R4, R4
	ADD R4, R4, #1
	ADD	R0, R3, R4
	RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
MUL	
	 ;multiplies r 3 and r4
	AND R0, R0, #0
	ADD R3, R3, #0
	BRz MULFIN 
	ADD R4, R4, #0
	brZ MULFIN
	BRn SECONDNEG
	BR MULSTART
	
	SECONDNEG ;logic to make sure second digit handles negative nums properly
	NOT R4, R4
	ADD R4, R4, #1
	AND R5, R5, #0
	ADD R5, R5, #1

	MULSTART 
	ADD R0, R3, R0
	ADD R4, R4, #-1
	BRp MULSTART

	ADD R5, R5, #0
	BRz MULFIN
	NOT R0, R0
	ADD R0, R0, #1

	MULFIN RET
	



;your code goes here
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
DIV	
;your code goes here
;methos for dividing r3 by r4
	;DIVIDE R3 BY R4 (R3/R4	)	
	AND R0, R0, #0
	;ADD R0, R3, #0
	NOT R4, R4	
	ADD R4, R4, #1 

	DIVSTART ADD R0, R0, #1 
	ADD R3, R3, R4
	BRp DIVSTART 
	BRn CORRECTDIV
	BR FINISHDIV
	
	CORRECTDIV ADD R0, R0, #-1 ;corrects incorrect divison
	FINISHDIV RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
EXP
;your code goes here
;R3 TO THE POWER OF R4
AND R0, R0, #0
ADD R4, R4, #0  ;checks to make sure r4 isnt 0
BRz R41
ADD R0, R3, #0
ADD R4, R4, #-1 ;checks if r4 is 0 
BRz EXPFIN 
AND R0, R0, #0
EXP2PLUS AND R1, R1, #0 ;loops and multiplies
ADD R1, R3, #0
EXPLOOP ADD R0, R0, R3
ADD R1, R1, #-1
BRp EXPLOOP

ADD R4, R4, #-1
BRz EXPFIN
BRp EXP2PLUS 


R41 ADD R0, R0, #1 ;if r4 = 0 
EXPFIN RET



;IN:R0, OUT:R5 (0-success, 1-fail/overflow)
;R3: STACK_END R4: STACK_TOP
;
PUSH	
	ST R3, PUSH_SaveR3	;save R3
	ST R4, PUSH_SaveR4	;save R4
	AND R5, R5, #0		;
	LD R3, STACK_END	;
	LD R4, STACk_TOP	;
	ADD R3, R3, #-1		;
	NOT R3, R3		;
	ADD R3, R3, #1		;
	ADD R3, R3, R4		;
	BRz OVERFLOW		;stack is full
	STR R0, R4, #0		;no overflow, store value in the stack
	ADD R4, R4, #-1		;move top of the stack
	ST R4, STACK_TOP	;store top of stack pointer
	BRnzp DONE_PUSH		;
OVERFLOW
	ADD R5, R5, #1		;
DONE_PUSH
	LD R3, PUSH_SaveR3	;
	LD R4, PUSH_SaveR4	;
	RET


PUSH_SaveR3	.BLKW #1	;
PUSH_SaveR4	.BLKW #1	;


;OUT: R0, OUT R5 (0-success, 1-fail/underflow)
;R3 STACK_START R4 STACK_TOP
;
POP	
	ST R3, POP_SaveR3	;save R3
	ST R4, POP_SaveR4	;save R3
	AND R5, R5, #0		;clear R5
	LD R3, STACK_START	;
	LD R4, STACK_TOP	;
	NOT R3, R3		;
	ADD R3, R3, #1		;
	ADD R3, R3, R4		;
	BRz UNDERFLOW		;
	ADD R4, R4, #1		;
	LDR R0, R4, #0		;
	ST R4, STACK_TOP	;
	BRnzp DONE_POP		;
UNDERFLOW
	ADD R5, R5, #1		;
DONE_POP
	LD R3, POP_SaveR3	;
	LD R4, POP_SaveR4	;
	RET

INSTACK2
	 
;AT 3FFE ;checksto see if theres 2 or more items in stack
LD R4, STACK_TOP
LD R1, CHECK42
NOT R4, R4
ADD R4, R4, #1
ADD R4, R4, R1


BRnz INVALIDMESSAGE

RET



INVVAR

NOT R1, R1 ;twos compliment aand combine r2 + r1
ADD R1, R1, #1
ADD R2, R2, R1



	RET


SETUP
	AND R2, R2, #0 ;sets up registers
	ADD R2, R0, #0
	RET

POP_SaveR3	.BLKW #1	;
POP_SaveR4	.BLKW #1	;
STACK_END	.FILL x3FF0	;
STACK_START	.FILL x4000	;
STACK_TOP	.FILL x4000	;
CHARPROMPT	.FILL x4100 ; 
HEXEQUALS	.FILL x003D
HEXSPACE	.FILL x0020
HEXNUM		.FILL x0030
HEXADD		.FILL x002B
HEXSUB		.FILL x002D
HEXMUL		.FILL x002A
HEXDIV		.FILL x002F
HEXPWR		.FILL x005E
CHECK42		.FILL x3FFF
ERROR 		.STRINGZ "Invalid Expression"
.END
=======
=======
>>>>>>> release/main
;
;
;
.ORIG x3000
	
;your code goes here
	











;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;R3- value to print in hexadecimal
PRINT_HEX

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;R0 - character input from keyboard
;R6 - current numerical output
;
;
EVALUATE

;your code goes here


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
PLUS	
;your code goes here
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
MIN	
;your code goes here
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
MUL	
;your code goes here
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
DIV	
;your code goes here
	
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
EXP
;your code goes here
	
;IN:R0, OUT:R5 (0-success, 1-fail/overflow)
;R3: STACK_END R4: STACK_TOP
;
PUSH	
	ST R3, PUSH_SaveR3	;save R3
	ST R4, PUSH_SaveR4	;save R4
	AND R5, R5, #0		;
	LD R3, STACK_END	;
	LD R4, STACk_TOP	;
	ADD R3, R3, #-1		;
	NOT R3, R3		;
	ADD R3, R3, #1		;
	ADD R3, R3, R4		;
	BRz OVERFLOW		;stack is full
	STR R0, R4, #0		;no overflow, store value in the stack
	ADD R4, R4, #-1		;move top of the stack
	ST R4, STACK_TOP	;store top of stack pointer
	BRnzp DONE_PUSH		;
OVERFLOW
	ADD R5, R5, #1		;
DONE_PUSH
	LD R3, PUSH_SaveR3	;
	LD R4, PUSH_SaveR4	;
	RET


PUSH_SaveR3	.BLKW #1	;
PUSH_SaveR4	.BLKW #1	;


;OUT: R0, OUT R5 (0-success, 1-fail/underflow)
;R3 STACK_START R4 STACK_TOP
;
POP	
	ST R3, POP_SaveR3	;save R3
	ST R4, POP_SaveR4	;save R3
	AND R5, R5, #0		;clear R5
	LD R3, STACK_START	;
	LD R4, STACK_TOP	;
	NOT R3, R3		;
	ADD R3, R3, #1		;
	ADD R3, R3, R4		;
	BRz UNDERFLOW		;
	ADD R4, R4, #1		;
	LDR R0, R4, #0		;
	ST R4, STACK_TOP	;
	BRnzp DONE_POP		;
UNDERFLOW
	ADD R5, R5, #1		;
DONE_POP
	LD R3, POP_SaveR3	;
	LD R4, POP_SaveR4	;
	RET


POP_SaveR3	.BLKW #1	;
POP_SaveR4	.BLKW #1	;
STACK_END	.FILL x3FF0	;
STACK_START	.FILL x4000	;
STACK_TOP	.FILL x4000	;


.END
<<<<<<< HEAD
>>>>>>> release/main
=======
>>>>>>> release/main
