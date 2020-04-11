	.arch	msp430g2553
	.p2align 1,0

	.data
switch_state:
	.word -1

	.text
jt:
	.word fi0
	.word fi1
	.word fi2
	.word fi3
	.word fi4
button_press:

fi0:
	push r4 	; push to register 4
	mov r1, r4 	; set pc to register 4
	add #2, r4	
	sub #2, r1
	mov &switch_state, r14 ; move switch state to register 14
	mov #-1, &switch_state ; set a -1 to switch state
	mov top_1(r14), r15    ;move top_1 from r14 to r15
	cmp #1, top_1 	; if (top_1 == 1)
	jnz fi1 	;jump to next state
	mov #1, &switch_state ; move a 1 to switch state (left)
	jmp done ; jump if not button press
fi1:
	mov top_2(r14), r15 ; move top_2 r14 to r15
	cmp #1, top_2 ; if (top_2 ==1)
	jnz fi2 ; if not jump to next state
	mov #2, &switch_state ;move a 2 to switch state (down) 
	jmp done ; jump if not button press
fi2:
	mov top_3(r14), r15 ; move top_3 r14 to r15
	cmp #1, top_3 ; if (top_3 ==1)
	jnz fi3  ;jump to next state 
	mov #3, &switch_state ; move a 3 to switch state (up) 
	jmp done ; jump if no button press
fi3:
	mov top_4(r14), r15 ; move top_4 r14 to r15
	cmp #1, top_4  ;if (top_4 ==1)
	jnz fi4 ;jump if to next state
	mov #4, &switch_state ; set a 4 to switch state (right)
	jmp done
fi4:
	mov #-1, &switch_state ; no button press move -1 to switch state
done:
	mov -4(r4), r1  ;move r4 from r1
	pop r4  ;pop from stack 
	;;ret ; return value
	pop r0; pop program counter  
