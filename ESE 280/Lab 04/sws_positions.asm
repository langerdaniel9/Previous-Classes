;
; sws_positions.asm
;
; Created: 9/21/2022 9:34:24 AM
; Author : Daniel Langer
;


start:
    ; Configure I/O ports
	ldi r16, 0xFF		; load r16 with all 1s
	out VPORTD_DIR, r16	; PORTD - all pins configured as outputs
	ldi r16, 0x00		; load r16 with all 0s
	out VPORTC_DIR, r16	; PORTC - all pins configured as inputs

	; Continually input switch values and output to LEDs
again: 
	in r16, VPORTC_IN	; read switch values
	com r16				; complement switch values to drive LEDs
	out VPORTD_OUT, r16	; output to LEDs to complement input from switches
	rjmp again			; continually repeat previous three instructions