;
; unconditional_input.asm
;
; Created: 9/26/2022 11:32:55 PM
; Author : Daniel Langer
;


start:
    ; Configure I/O ports
	ldi r16, 0xFF		; load r16 with all 1s
	out VPORTD_DIR, r16	; PORTD - all pins configured as outputs for LED's
	ldi r16, 0x00		; load r16 with all 0's to reset
	out VPORTC_DIR, r16	; All port C pins set as input for DIP switches

loop:			
	in r16, VPORTC_in	; Input switch values from DIP switch
	com r16				; complement because LED's are active low
	out VPORTD_OUT, r16	; Output count to bargraph 
	rjmp loop			; loop
