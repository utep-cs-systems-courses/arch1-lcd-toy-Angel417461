	.arch msp430g2553
	.p2align 1,0
	
	
	.data
state:
	.byte 0

	.text
jt:
	.word default
	.word case0
	.word case1
	.word case2
	.word case3

	.global animation

animation:
	cmp #0, &redrawScreen
	jz out
	mov #0, &redrawScreen


	cmp #5, &state
	jhs default

	mov &state, r12
	add #3, r12
	mov jt(r12), r0

case0:
	call #state0
	add #1, &state
	jmp out

case1:
	call #state1
	add #1, &state
	jmp out

case2:
	call #state2
	add #1, &state
	jmp out

case3:
	call #state3
	add #1, &state
	jmp out

default:
	mov #0, &state

out:
	pop r0
