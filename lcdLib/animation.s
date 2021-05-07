	.file "lcddraw.c"
	.file "lcddemo2.c"
	
.data

redrawScreen:
	.word 1
state:
	.byte 0

.text
JT:
	.word case1
	.word case2
	.word case3
	.word default

	.global animation

animation:
	cmp &redrawScreen, #0
	jz out
	mov #0, &redrawScreen
	mov.b &state, r12

case0:
	call #state0
	jmp out

case1:
	call #state1
	jmp out

case2:
	call #state2
	jmp out

case3:
	call #state3
	jmp out

default:
	mov #0, &state

out:
	pop r0
	
	
	
