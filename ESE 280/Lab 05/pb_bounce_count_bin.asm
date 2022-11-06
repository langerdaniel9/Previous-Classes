;
; pb_bounce_count_bin.asm
;
; Created: 9/26/2022 7:16:05 PM
; Author : Daniel Langer
;


start:
    ; Configure I/O ports
	ldi r16, 0xFF		; load r16 with all 1s
	out VPORTD_DIR, r16	; PORTD - all pins configured as outputs
	out VPORTD_OUT, r16	; Start with LED's all off
	cbi VPORTE_DIR, 2	; Pin PE0 set as input for pushbutton



wait_for_1:				; Step 1
	sbis VPORTE_IN, 2	; loop unti PE0 becomes a 1
	rjmp wait_for_1		;

wait_for_0:				; Step 2
	sbic VPORTE_IN, 2	; loop until PE0 becomes a 0
	rjmp wait_for_0		;

valid:					; Step 5
	dec r16				; was a valid keypress, increment counter
	out VPORTD_OUT, r16	; Output count to bargraph 
	rjmp wait_for_1		; Back to step 1	


