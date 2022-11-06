;
; blink_LED_no_delay.asm
;
; Created: 8/31/2022 9:33:06 AM
; Author : Daniel Langer
;


; Replace with your application code
start:
    sbi VPORTB_DIR, 3		; set direction of PB3 as output
	sbi VPORTB_OUT, 3		; set output value to 1

; Turn LED ON and OFF
loop:
	cbi VPORTB_OUT, 3		; clear output value 0, turn LED ON  1 clock AVRxt
	nop						;									 1 clock
	nop						;									 1 clock
	sbi VPORTB_OUT, 3		; set output value 1, turn LED off   1 clock
	rjmp loop				;									 2 clocks