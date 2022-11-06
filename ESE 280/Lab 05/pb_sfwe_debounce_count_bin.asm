;
; pb_sfwe_debounce_count_bin.asm
;
; Created: 9/26/2022 10:09:34 PM
; Author : Daniel Langer
;


start:
    ; Configure I/O ports
	ldi r16, 0xFF			; load r16 with all 1s
	out VPORTD_DIR, r16		; PORTD - all pins configured as outputs
	out VPORTD_OUT, r16		; Start with LED's all off
	clr r18					; set r15 to all 0's to use for delay loop
	cbi VPORTE_DIR, 2		; Pin PE0 set as input for pushbutton

wait_for_1:					; Step 1
	sbis VPORTE_IN, 2		; loop unti PE0 becomes a 1
	rjmp wait_for_1			

wait_for_0:					; Step 2
	sbic VPORTE_IN, 2		; loop unti PE0 becomes a 0
	rjmp wait_for_0			

delay:						; Step 3
	ldi r18, 100			; Use a multiplier of 100 for delay to get approximately 10ms
	rcall var_delay			; Call delay subroutine

check_if_still_0:			; Step 4
	sbic VPORTE_IN, 2		; if still 0 skip, else go back to step 1
	rjmp wait_for_1			; back to step 1

valid:						; Step 5
	dec r16					; was a valid keypress, increment counter
	out VPORTD_OUT, r16		; Output count to bargraph 

wait_for_1_up:				; Step 6
	sbis VPORTE_IN, 2		; Make sure its still 1, stuck here if not
	rjmp wait_for_1_up	

delay_2:					; Step 7
	ldi r18, 100			; Use a multiplier of 100 for delay to get approximately 10ms
	rcall var_delay			; Call delay subroutine

check_if_still_1:			; Step 8
	sbis VPORTE_IN, 2		; Make sure its still 0, go back to step 6 if not
	rjmp wait_for_1_up	
	rjmp wait_for_1			; Back to step 1	

var_delay:					; delay for AVR 128DB48 @ 4.00 MHz = r15 * 0.100475 ms
outer_loop:	
	ldi r17, 133			
inner_loop:
	dec r17
	brne inner_loop
	dec r15
	brne outer_loop
	ret