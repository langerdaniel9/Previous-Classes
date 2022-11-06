;
; segment_and_digit_test.asm
;
; Created: 10/10/2022 8:50:32 PM
; Author : Daniel Langer
;


start:
    ;; Set up I/O pins
	; Set up VPORTD as outputs for the 7 segment display
	ldi r16, 0xFF		; 
	out VPORTD_DIR, r16	; All 1's means all outputs

	; Start with segments preset to all off
	out VPORTD_OUT, r16	; All ones means all off since it is active low

	; Set up the needed VPORTA pins as outputs for the digit position selector
	ldi r16, 0xF0		; Want first four MSB of VPORTC 
	out VPORTA_DIR, r16	;
	; PA7 controls digit 4, PA6 controls digit 3, etc.

	; Start with all digits unselected
	ldi r16, 0xF0		; Set to ones since the transistor is essentially active low
	out VPORTA_OUT, r16	;


test_four:
	;; Turn on all segments
	ldi r16, 0x00		;
	out VPORTD_OUT, r16	;

	;; Select the rightmost digit (digit 4)
	cbi VPORTA_OUT, 7	;

	;; Wait for one second
	rcall one_sec_delay	;

	;; Turn off all segments
	ldi r16, 0xFF		;
	out VPORTD_OUT, r16	;

	;; Unselect the rightmost digit (digit 4)
	sbi VPORTA_OUT, 7	;

test_three:
	;; Turn on all segments
	ldi r16, 0x00		;
	out VPORTD_OUT, r16	;

	;; Select the rightmost digit (digit 3)
	cbi VPORTA_OUT, 6	;

	;; Wait for one second
	rcall one_sec_delay	;

	;; Turn off all segments
	ldi r16, 0xFF		;
	out VPORTD_OUT, r16	;

	;; Unselect the rightmost digit (digit 3)
	sbi VPORTA_OUT, 6	;

test_two:
	;; Turn on all segments
	ldi r16, 0x00		;
	out VPORTD_OUT, r16	;

	;; Select the rightmost digit (digit 2)
	cbi VPORTA_OUT, 5	;

	;; Wait for one second
	rcall one_sec_delay	;

	;; Turn off all segments
	ldi r16, 0xFF		;
	out VPORTD_OUT, r16	;

	;; Unselect the rightmost digit (digit 2)
	sbi VPORTA_OUT, 5	;

test_one:
	;; Turn on all segments
	ldi r16, 0x00		;
	out VPORTD_OUT, r16	;

	;; Select the rightmost digit (digit 1)
	cbi VPORTA_OUT, 4	;

	;; Wait for one second
	rcall one_sec_delay	;

	;; Turn off all segments
	ldi r16, 0xFF		;
	out VPORTD_OUT, r16	;

	;; Unselect the rightmost digit (digit 1)
	sbi VPORTA_OUT, 4	;

	rjmp test_four		;


; 1.00008575 seconds @ 4 MHz system clock, 192 us resolution
one_sec_delay:
	ldi r30, LOW(5202)	; outer loop 16- bit iteration count
	ldi r31, HIGH(5202)	; 16-bit value in r31:r30
outer_loop:
	ldi r16, $FF		; inner loop 8-bit iteration count
inner_loop:
	dec r16				; subtract 1 from inner loop count
brne inner_loop
	sbiw r31:r30, 1		; subtract 1 from outer loop count
brne outer_loop
	ret