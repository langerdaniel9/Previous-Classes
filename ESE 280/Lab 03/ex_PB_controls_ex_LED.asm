;
; ex_PB_controls_ex_LED.asm
;
; Created: 9/11/2022 5:30:54 PM
; Author : Daniel Langer
;

;; Task 2 

; LED is connected to PD7 
; Button is connected to PA7
start:
	sbi VPORTD_DIR, 7	; set direction of PB3 as output
	sbi VPORTD_OUT, 7	; set output value to 1;
	cbi VPORTA_DIR, 7	; set direction of PB2 to input (default)

; Read switch position to control LED
loop:
	sbis VPORTA_IN, 7	; skip next instruction if PB2 is 1
	sbi VPORTD_OUT, 7	; set output PB3 to 1, turn LED OFF
	sbic VPORTA_IN, 7	; skip next instruction if PB2 is 0
	cbi VPORTD_OUT, 7	; clear output PB3 to 0, turn LED ON
	rjmp loop			; jump back to loop


;; Task 4

;; I used a different pin for task 4 so that I could switch between the circuits 
;; for task 2 and task 4 with minimal effort, since the TA's were busy and I did 
;; not have my task 2 checked yet.


; LED is connected to PD7 
; Button is connected to PB1
;start:
;	sbi VPORTD_DIR, 7	; set direction of PB3 as output
;	sbi VPORTD_OUT, 7	; set output value to 1;
;	cbi VPORTB_DIR, 1	; set direction of PB2 to input (default)
;
; Read switch position to control LED
;loop:
;	sbis VPORTB_IN, 1	; skip next instruction if PB2 is 1
;	cbi VPORTD_OUT, 7	; clear output PB3 to 0, turn LED ON
;	sbic VPORTB_IN, 1	; skip next instruction if PB2 is 0
;	sbi VPORTD_OUT, 7	; set output PB3 to 1, turn LED OFF
;	rjmp loop			; jump back to loop