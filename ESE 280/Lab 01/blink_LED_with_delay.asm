;
; blink_LED_with_delay.asm
;
; Created: 8/31/2022 10:04:05 AM
; Author : Daniel Langer
;


; Replace with your application code
start:
    sbi VPORTB_DIR, 3	; set direction of PB3 as output
	sbi VPORTB_OUT, 3	; set output value 

; Turn LED ON and OFF
loop:
	cbi VPORTB_OUT, 3	; clear output value 0, turn LED ON		1 clock AVRxt
	nop					;										1 clock
	nop					;										1 clock
	rcall delay_500ms
	sbi VPORTB_OUT, 3	; set output value 1, turn LED OFF		1 clock
	rcall delay_500ms
	rjmp loop			;										2 clocks

; Delay subroutine tuned to create a 1 Hz waveform when called by the code above
delay_500ms:
	ldi r30, LOW(2595)	; values determined experimentally using scope
	ldi r31, HIGH(2595)
outer_loop:
	ldi r16, $FF
inner_loop:
	dec r16
brne inner_loop
	sbiw r31:r30, 1
brne outer_loop
	ret					; return to caller