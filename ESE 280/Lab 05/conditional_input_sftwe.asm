;
; conditional_input_sftwe.asm
;
; Created: 9/26/2022 11:48:07 PM
; Author : Daniel Langer
;


start:
    ; Configure I/O ports
	ldi r16, 0xFF			; Load r16 with all 1s
	out VPORTD_DIR, r16		; PORTD - all pins configured as outputs for LED's
	out VPORTD_OUT, r16		; Start with LED's all off
	ldi r16, 0x00			; Load r16 with all 0's
	clr r18					; set r18 to all 0's to use for delay loop (multiplier for delay)
	out VPORTC_DIR, r16		; All port C pins set as input for DIP switches
	cbi VPORTE_DIR, 0		; Set PE0 as input (output of flip flop)
	sbi VPORTE_DIR, 1		; Set PE1 as output (clear signal for flip flop)
	sbi VPORTE_OUT, 1		; Set to logic 1
	cbi VPORTE_DIR, 2		; Set PE2 as input (button output)
	
clr_ff:
	cbi VPORTE_OUT, 1		; Pulse the FF to clear it
	sbi VPORTE_OUT, 1

wait_for_ff:
	sbis VPORTE_IN, 0		; Wait for flip flop to output 1
	rjmp wait_for_ff		;

valid:						; Step 5								
	in r16, VPORTC_IN		; Input switch values from DIP switch
	com r16					; Complement because LED's are active low
	out VPORTD_OUT, r16		; Output count to bargraph 

wait_for_0:					; Step 6
	sbic VPORTE_IN, 2		; Wait until button is released
	rjmp wait_for_0	

delay:						; Step 7
	ldi r18, 100			; Use a multiplier of 100 for delay to get approximately 10ms
	rcall var_delay			; Call delay subroutine

check_if_still_0:			; Step 8
	sbic VPORTE_IN, 2		; Make sure its still 0, go back to step 6 if not
	rjmp wait_for_0	

	cbi VPORTE_OUT, 1		; Pulse the FF to clear it
	sbi VPORTE_OUT, 1	

	rjmp wait_for_ff		; Back to step 1	

var_delay:					; delay for AVR 128DB48 @ 4.00 MHz = r15 * 0.100475 ms
outer_loop:	
	ldi r17, 133			
inner_loop:
	dec r17
	brne inner_loop
	dec r18
	brne outer_loop
	ret
	
