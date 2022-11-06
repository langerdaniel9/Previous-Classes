;
; ic_test.asm
;
; Created: 10/2/2022 4:23:17 PM
; Author : Daniel Langer
;

start:						; Configure I/O ports

	;; DIP Switches
	cbi VPORTE_DIR, 1		; Set PE1 as input
	cbi VPORTE_DIR, 2		; Set PE2 as input
	cbi VPORTE_DIR, 3		; Set PE3 as input

    ;; Input pins for DUT
	ldi r16, 0xFF			; Load r16 with all 1s
	out VPORTC_DIR, r16		; All port C pins set as output for the inputs of DUT
	
	;; Output pins for DUT
	cbi VPORTF_DIR, 2		; 4Y
	cbi VPORTF_DIR, 3		; 3Y
	cbi VPORTF_DIR, 4		; 2Y
	cbi VPORTF_DIR, 5		; 1Y

	;; LED Package (Active Low)
	sbi VPORTD_OUT, 0		; Start with LED's all off
	sbi VPORTD_OUT, 1
	sbi VPORTD_OUT, 2
	sbi VPORTD_DIR, 0		; Set up 3 LED's as outputs to reflect switch state
	sbi VPORTD_DIR, 1
	sbi VPORTD_DIR, 2

	;; Individual LED's (Active Low)
	sbi VPORTD_DIR, 3		; White LED (Test In Progress)
	sbi VPORTD_DIR, 4		; Green LED (Success)
	sbi VPORTD_DIR, 5		; Red LED (Failure)
	sbi VPORTD_OUT, 3		; Start with LED's all off
	sbi VPORTD_OUT, 4
	sbi VPORTD_OUT, 5

	;; Button and FF
	cbi VPORTE_DIR, 0		; PE0 is the output of the FF
	cbi VPORTD_DIR, 6		; PD6 is the output of the button
	sbi VPORTD_DIR, 7		; PD7 is CLR for the FF

	;; Delay
	clr r18					; clear r18 for the var_delay subroutine to use

	;; Registers
	; r24 used to store input from switches
	; r17, r18 are for the var_delay subroutine
	; r19 used for masks and logic in individual functions
	; r20 used to hold the outputs of the DUT
	; r21 used to keep track of errors
	; r16, r30, r31 are for one_sec_delay subroutine

post:						; Power on self test
	; turn on leds
	ldi r19, $C0
	out VPORTD_OUT, r19
	;cbi VPORTD_OUT, 0		
	;cbi VPORTD_OUT, 1		
	;cbi VPORTD_OUT, 2		
	;cbi VPORTD_OUT, 3		
	;cbi VPORTD_OUT, 4
	;cbi VPORTD_OUT, 5
	
	; wait one second
	rcall one_sec_delay

	; turn off leds
	ldi r19, $3F
	out VPORTD_OUT, r19
	;sbi VPORTD_OUT, 0		
	;sbi VPORTD_OUT, 1		
	;sbi VPORTD_OUT, 2		
	;sbi VPORTD_OUT, 3		
	;sbi VPORTD_OUT, 4
	;sbi VPORTD_OUT, 5

;; Clear flip flip
clr_ff:
	cbi VPORTD_OUT, 7		; Pulse FF to clear it
	sbi VPORTD_OUT, 7		;

;; wait for FF to show button press
	
wait_for_0:					
	sbic VPORTE_IN, 0		; loop unti FF becomes 0 (not pressed)
	rjmp wait_for_0			

wait_for_1:					
	sbis VPORTE_IN, 0		; loop until FF becomes 1 (pressed)
	rjmp wait_for_1			

valid:					
	;; read input from switches and decide which gate logic to use

	; Turn on TIP LED
	cbi VPORTD_OUT, 3		

	; Turn off success/fail LEDs
	sbi VPORTD_OUT, 4
	sbi VPORTD_OUT, 5

	; Reset switch values
	clr r24;

	; Read input from switches and output to LED package
	; Read in input from switches
	sbic VPORTE_IN, 1
	sbr r24, 4
	sbic VPORTE_IN, 2
	sbr r24, 2
	sbic VPORTE_IN, 3
	sbr r24, 1

	; Reset LED package
	sbi VPORTD_OUT, 0		
	sbi VPORTD_OUT, 1		
	sbi VPORTD_OUT, 2	

	; Output the switch states to LED package
	sbic VPORTE_IN, 1
	cbi VPORTD_OUT, 0
	sbic VPORTE_IN, 2
	cbi VPORTD_OUT, 1
	sbic VPORTE_IN, 3
	cbi VPORTD_OUT, 2

	clr r21					; Clear error counter before the next check

	; figure out which operation it wants
	; r24 is the input
	clr r22					; use as reference
	mov r25, r24			; Make 5 copies
	mov r26, r24
	mov r27, r24
	mov r28, r24
	mov r29, r24

	subi r25, 0x00
	cpse r25, r22			; NAND
	rjmp next1
	rjmp fcn_nand	

next1:
	subi r26, 0x01
	cpse r26, r22			; AND
	rjmp next2
	rjmp fcn_and

next2:
	subi r27, 0x02
	cpse r27, r22			; OR
	rjmp next3
	rjmp fcn_or	

next3:
	subi r28, 0x03
	cpse r28, r22			; XOR
	rjmp next4
	rjmp fcn_xor

next4:
	subi r29, 0x04
	cpse r29, r22			; NAND OCO
	rjmp incorrect_code
	rjmp fcn_nand_oco

incorrect_code:
	inc r21					; increment error counter since the input did not match any of the possible cases

finished:
	sbi VPORTD_OUT, 3		; turn off TIP LED
	cpi r21, 0x00			; Compare error count to zero
	breq no_err
err:
	cbi VPORTD_OUT, 5		; Turn on error LED
	rjmp wait_for_0_up
no_err:
	cbi VPORTD_OUT, 4		; Turn on success LED

;; Button debounce
wait_for_0_up:				
	sbic VPORTD_IN, 6		; Make sure its still 0, stuck here if not
	rjmp wait_for_0_up	

delay:					
	ldi r18, 100			; Use a multiplier of 100 for delay to get approximately 10ms
	rcall var_delay			; Call delay subroutine

check_if_still_1:			; Step 8
	sbic VPORTD_IN, 6		; Make sure its still 0, go back to step 6 if not
	rjmp wait_for_0_up	
	rjmp clr_ff				; Back to beginning	

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

fcn_nand: ; 000 74HC00 Quadruple 2-Input Positive NAND Gates
	rcall zero_zero
	ldi r19, 0x3C			; Expected result 00 11 11 00
	cpse r20, r19			; If output = expected output skip incrementing error counter
	inc r21					; increment error counter
	
	; Try 01 for all four gates
	rcall one_zero
	ldi r19, 0x3C			; Expected result 00 11 11 00
	cpse r20, r19			; If output = expected output skip incrementing error counter
	inc r21					; increment error counter

	; Try 10 for all four gates
	rcall one_zero
	ldi r19, 0x3C			; Expected result 00 11 11 00
	cpse r20, r19			; If output = expected output skip incrementing error counter
	inc r21					; increment error counter

	; Try 11 for all four gates
	rcall one_one
	ldi r19, 0x00			; Expected result 00 00 00 00
	cpse r20, r19			; If output = expected output skip incrementing error counter
	inc r21					; increment error counter

	rjmp finished

fcn_and: ; 001 74HC08 Quadruple 2-Input Positive AND Gates
	rcall zero_zero
	ldi r19, 0x00			; Expected result 00 00 00 00
	cpse r20, r19			; If output = expected output skip incrementing error counter
	inc r21					; increment error counter
	
	; Try 01 for all four gates
	rcall one_zero
	ldi r19, 0x00			; Expected result 00 00 00 00
	cpse r20, r19			; If output = expected output skip incrementing error counter
	inc r21					; increment error counter

	; Try 10 for all four gates
	rcall one_zero
	ldi r19, 0x00			; Expected result 00 00 00 00
	cpse r20, r19			; If output = expected output skip incrementing error counter
	inc r21					; increment error counter

	; Try 11 for all four gates
	rcall one_one
	ldi r19, 0x3c			; Expected result 00 11 11 00
	cpse r20, r19			; If output = expected output skip incrementing error counter
	inc r21					; increment error counter

	rjmp finished

fcn_or: ; 010 74HC32 Quadruple 2-Input Positive OR Gates
	rcall zero_zero
	ldi r19, 0x00			; Expected result 00 00 00 00
	cpse r20, r19			; If output = expected output skip incrementing error counter
	inc r21					; increment error counter
	
	; Try 01 for all four gates
	rcall one_zero
	ldi r19, 0x3C			; Expected result 00 11 11 00
	cpse r20, r19			; If output = expected output skip incrementing error counter
	inc r21					; increment error counter

	; Try 10 for all four gates
	rcall one_zero
	ldi r19, 0x3C			; Expected result 00 11 11 00
	cpse r20, r19			; If output = expected output skip incrementing error counter
	inc r21					; increment error counter

	; Try 11 for all four gates
	rcall one_one
	ldi r19, 0x3C			; Expected result 00 11 11 00
	cpse r20, r19			; If output = expected output skip incrementing error counter
	inc r21					; increment error counter

	rjmp finished

fcn_xor: ; 011 74HC86 Quadruple 2-Input Exclusive OR Gates
	rcall zero_zero
	ldi r19, 0x00			; Expected result 00 00 00 00
	cpse r20, r19			; If output = expected output skip incrementing error counter
	inc r21					; increment error counter
	
	; Try 01 for all four gates
	rcall one_zero
	ldi r19, 0x3C			; Expected result 00 11 11 00
	cpse r20, r19			; If output = expected output skip incrementing error counter
	inc r21					; increment error counter

	; Try 10 for all four gates
	rcall one_zero
	ldi r19, 0x3C			; Expected result 00 11 11 00
	cpse r20, r19			; If output = expected output skip incrementing error counter
	inc r21					; increment error counter

	; Try 11 for all four gates
	rcall one_one
	ldi r19, 0x00			; Expected result 00 00 00 00
	cpse r20, r19			; If output = expected output skip incrementing error counter
	inc r21					; increment error counter

	rjmp finished

fcn_nand_oco: ; 100 74LS03 Quadruple 2-Input Positive NAND Gates Open-Collector Outputs
	;; Turn on internal pull up resistors
	ldi r19, 0x08			
	sts PORTF_PIN2CTRL, r19	
	sts PORTF_PIN3CTRL, r19
	sts PORTF_PIN4CTRL, r19
	sts PORTF_PIN5CTRL, r19	

	rcall zero_zero
	ldi r19, 0x3C			; Expected result 00 11 11 00
	cpse r20, r19			; If output = expected output skip incrementing error counter
	inc r21					; increment error counter
	; Try 01 for all four gates
	rcall one_zero
	ldi r19, 0x3C			; Expected result 00 11 11 00
	cpse r20, r19			; If output = expected output skip incrementing error counter
	inc r21					; increment error counter
	; Try 10 for all four gates
	rcall one_zero
	ldi r19, 0x3C			; Expected result 00 11 11 00
	cpse r20, r19			; If output = expected output skip incrementing error counter
	inc r21					; increment error counter
	; Try 11 for all four gates
	rcall one_one
	ldi r19, 0x00			; Expected result 00 00 00 00
	cpse r20, r19			; If output = expected output skip incrementing error counter
	inc r21					; Increment error counter
	
	;; Turn off pull up resistors
	ldi r19, 0x00			
	sts PORTF_PIN2CTRL, r19	
	sts PORTF_PIN3CTRL, r19
	sts PORTF_PIN4CTRL, r19
	sts PORTF_PIN5CTRL, r19	

	rjmp finished

zero_zero:
	; Try 00 for all four gates
	ldi r19, 0x00			; Set test case as 00 00 00 00
	out VPORTC_OUT, r19		; Output test case
	;; delay
	nop
	nop
	nop
	nop
	nop
	;; 
	in r20, VPORTF_IN		; Take in results from the output of the DUT
	ldi r19, 0x3C			; Necessary bits 00 11 11 00
	and r20, r19			; Only keep necessary bits
	ret

zero_one:
	ldi r19, 0x55			; Set test case as 01 01 01 01
	out VPORTC_OUT, r19		; Output test case
	;; delay
	nop
	nop
	nop
	nop
	nop
	;; 
	in r20, VPORTF_IN		; Take in results from the output of the DUT
	ldi r19, 0x3C			; Necessary bits 00 11 11 00
	and r20, r19			; Only keep necessary bits
	ret

one_zero:
	ldi r19, 0xAA			; Set test case as 10 10 10 10
	out VPORTC_OUT, r19		; Output test case
	;; delay
	nop
	nop
	nop
	nop
	nop
	;; 
	in r20, VPORTF_IN		; Take in results from the output of the DUT
	ldi r19, 0x3C			; Necessary bits 00 11 11 00
	and r20, r19			; Only keep necessary bits
	ret

one_one:
	ldi r19, 0xFF			; Set test case as 11 11 11 11
	out VPORTC_OUT, r19		; Output test case
	;; delay
	nop
	nop
	nop
	nop
	nop
	;; 
	in r20, VPORTF_IN		; Take in results from the output of the DUT
	ldi r19, 0x3C			; Necessary bits 00 11 11 00
	and r20, r19			; Only keep necessary bits
	ret

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

; delay for AVR 128DB48 @ 4.00 MHz = r18 * 0.100475 ms
var_delay:					
outer_loop_2:	
	ldi r17, 133			
inner_loop_2:
	dec r17
	brne inner_loop_2
	dec r18
	brne outer_loop_2
	ret