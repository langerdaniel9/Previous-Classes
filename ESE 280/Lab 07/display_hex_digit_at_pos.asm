;
; table_lookup_seg_test.asm
;
; Created: 10/11/2022 11:32:12 AM
; Author : Daniel Langer
;


start:					; Set up I/O pins
    
	; Set up VPORTD as outputs for the 7 segment display
	ldi r16, 0xFF		; 
	out VPORTD_DIR, r16	; All 1's means all outputs
	out VPORTD_OUT, r16	; All ones means all off since it is active low

	; Set up the needed VPORTA pins as outputs for the digit position selector
	; PA7 controls digit 4, PA6 controls digit 3, etc.
	ldi r16, 0xF0		; Want first four MSB of VPORTC 
	out VPORTA_DIR, r16	;
	
	ldi r16, 0xF0		; Set to ones since the transistor is essentially active low (turn all digits off)
	out VPORTA_OUT, r16	;

	; Set up DIP Switches as input
	ldi r16, 0xFF		; All 1's for output
	out VPORTC_DIR, r16	;

	; Set up flip flop & button i/o
	cbi	VPORTE_DIR, 0	; PE0 as Q, input of flip flop
	sbi	VPORTE_DIR, 1	; PE1 as CLR, active low clear signal
	cbi	VPORTE_DIR, 2	; PE2 is connected to button

	sbi VPORTE_OUT, 1	; Keep CLR signal high
	
	ser r26				; Turn all segments off by default for digit 1
	ser r27				; Turn all segments off by default for digit 2
	ser r28				; Turn all segments off by default for digit 3
	ser r29				; Turn all segments off by default for digit 4

	;;sbr r24, 1

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	; Registers
	;
	;
	; r16 - holds input from dip switch and also used in 'reverse_bits'
	; r17 - used in 'reverse_bits' subroutine (dont use for holding variables)
	; r18 - used in 'hex_to_7_seg' subroutine (dont use for holding variables)
	; r19 - used for button positions
	; r20 - 
	; r21 - var_delay (fixed)
	; r22 - var_delay (variable)
	; r23 - 
	; r24 - temp variable 
	; r25 - bit 0 holds bool value for clr_ff
	; r26 - holds output for digit 1
	; r27 - holds output for digit 2
	; r28 - holds output for digit 3
	; r29 - holds output for digit 4
	; r30 - Used by 'hex_to_7_seg' 
	; r31 - Used by 'hex_to_7_seg' 
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

main_loop:

clr_ff:					; Pulse the FF to clear it
	cbi VPORTE_OUT, 1		
	sbi VPORTE_OUT, 1
	;; Possibly add delay here to make sure ff is cleared

check_ff:
	cbr r25, 1;
	sbis VPORTE_IN, 0	; 
	rjmp display_digits	; If button wasnt pressed keep displaying current values

button_pressed:
	sbr r25, 1
	in r16, VPORTC_IN	; Read in from dip switches and save to r16
	rcall reverse_bits	; Call reverse_bits to reverse register r16
	mov r18, r16		; Copy register 16 to 18
	
	mov r19, r18		; Copy register 16 to 19
	andi r19, $C0		; Keep only first 2 
	lsr r19				;
	lsr r19				;
	lsr r19				;
	lsr r19				;
	lsr r19				;
	lsr r19				;

	rcall hex_to_7seg	; Get correct pattern for output

	;; r19 is now the digit selection and r18 is the output pattern

	cpi r19, 0			; If digit selection is 0 send output pattern to digit 1
	breq to_first		;

	cpi r19, 1			; If digit selection is 1 send output pattern to digit 2
	breq to_second		;

	cpi r19, 2			; If digit selection is 2 send output pattern to digit 3
	breq to_third		;

	cpi r19, 3			; If digit selection is 3 send output pattern to digit 4
	breq to_fourth		;


to_first:				; Send value from input to register that holds value for digit 1
	mov r26, r18		;
	rjmp display_digits	;

to_second:				; Send value from input to register that holds value for digit 2
	mov r27, r18		;
	rjmp display_digits	;

to_third: 				; Send value from input to register that holds value for digit 3
	mov r28, r18		;
	rjmp display_digits	;

to_fourth:				; Send value from input to register that holds value for digit 4
	mov r29, r18		;
	rjmp display_digits	;



display_digits:

display_first:
	; turn off all digit selectors
	ldi r24, $FF		;
	out VPORTA_OUT, r24	;
	; put correct output into output i/o register
	out VPORTD_OUT, r26	;
	; turn on correct digit selector
	cbi VPORTA_OUT, 4	;
	ldi r22, 62			; delay
	rcall var_delay		;
display_second:
	; turn off all digit selectors
	ldi r24, $FF		;
	out VPORTA_OUT, r24	;
	; put correct output into output i/o register
	out VPORTD_OUT, r27	;
	; turn on correct digit selector
	cbi VPORTA_OUT, 5	;
	ldi r22, 62			; delay
	rcall var_delay		;
display_third:
	; turn off all digit selectors
	ldi r24, $FF		;
	out VPORTA_OUT, r24	;
	; put correct output into output i/o register
	out VPORTD_OUT, r28	;
	; turn on correct digit selector
	cbi VPORTA_OUT, 6	;
	ldi r22, 62			; delay
	rcall var_delay		;
display_fourth:
	; turn off all digit selectors
	ldi r24, $FF		;
	out VPORTA_OUT, r24	;
	; put correct output into output i/o register
	out VPORTD_OUT, r29	;
	; turn on correct digit selector
	cbi VPORTA_OUT, 7	;
	ldi r22, 62			; delay
	rcall var_delay		;

fin:

	ldi r24, $00
	cpse r25, r24		;
	rjmp main_loop		; clr_ff set to true
	rjmp check_ff		; clr_ff set to false




; delay for AVR 128DB48 @ 4.00 MHz = r18 * 0.100475 ms
var_delay:
outer_loop_2:
ldi r21, 133
inner_loop_2:
dec r21
brne inner_loop_2
dec r22
brne outer_loop_2
ret



;***************************************************************************
;* 
;* "reverse_bits" - Reverse Bits
;*
;* Description: Reverse the bits held in register 16
;*
;* Author: Daniel Langer
;* Version: 0
;* Last updated: 10/11/2022
;* Target: AVR128DB48
;* Number of words:
;* Number of cycles:
;* Low registers modified:
;* High registers modified:
;*
;* Parameters: r16: register to be reversed
;*
;* Returns: r16: reversed register
;*
;* Notes: 
;*
;***************************************************************************
reverse_bits: 
	clr r17			; Default to 0
	
	sbrc r16, 0		; If bit 0 is set, set bit 7
	sbr r17, $80	;
	sbrc r16, 1		; If bit 1 is set, set bit 6
	sbr r17, $40	;
	sbrc r16, 2		; If bit 2 is set, set bit 5
	sbr r17, $20	;
	sbrc r16, 3		; If bit 3 is set, set bit 4
	sbr r17, $10	;
	sbrc r16, 4		; If bit 4 is set, set bit 3
	sbr r17, $08	;
	sbrc r16, 5		; If bit 5 is set, set bit 2
	sbr r17, $04	;
	sbrc r16, 6		; If bit 6 is set, set bit 1
	sbr r17, $02	;
	sbrc r16, 7		; If bit 7 is set, set bit 0
	sbr r17, $01	;
	
	mov r16, r17	; Copy r17 to r16
	clr r17			; clear back to 0
	ret


;***************************************************************************
;* 
;* "hex_to_7seg" - Hexadecimal to Seven Segment Conversion
;*
;* Description: Converts a right justified hexadecimal digit to the seven
;* segment pattern required to display it. Pattern is right justified a
;* through g. Pattern uses 0s to turn segments on ON.
;*
;* Author:			Ken Short
;* Version:			0.1						
;* Last updated:		100322
;* Target:			AVR128DB48
;* Number of words:
;* Number of cycles:
;* Low registers modified:
;* High registers modified:
;*
;* Parameters: r18: hex digit to be converted
;* Returns: r18: seven segment pattern. 0 turns segment ON
;*
;* Notes: 
;*
;***************************************************************************
hex_to_7seg:
    ldi ZH, HIGH(hextable * 2)  ;set Z to point to start of table
    ldi ZL, LOW(hextable * 2)
    ldi r16, $00                ;add offset to Z pointer
	andi r18, 0x0F				;mask for low nibble
    add ZL, r18
    adc ZH, r16
    lpm r18, Z                  ;load byte from table pointed to by Z
	ret

    ;Table of segment values to display digits 0 - F
    ;!!! seven values must be added
;hextable: .db $01, $4F, $12, $06, $4C, $24, $20, $0F, $00, $04, $08, $60, $31, $42, $30, $38 ; Decimal always on
hextable: .db $81, $CF, $92, $86, $CC, $A4, $A0, $8F, $80, $84, $88, $E0, $B1, $C2, $B0, $B8 ; Decimal off

; is the decimal point meant to be always on?

;hex -  binary   = displays
; 01 - 0000 0001 = 0
; 4f - 0100 1111 = 1
; 12 - 0001 0010 = 2
; 06 - 0000 0110 = 3
; 4C - 0100 1100 = 4
; 24 - 0010 0100 = 5
; 20 - 0010 0000 = 6
; 0F - 0000 1111 = 7
; 00 - 0000 0000 = 8
; ------------------
; 04 - 0000 0100 = 9
; 08 - 0000 1000 = A
; 60 - 0110 0000 = B
; 31 - 0011 0001 = C
; 42 - 0100 0010 = D
; 30 - 0011 0000 = E
; 38 - 0011 1000 = F

; DP A B C D E F G ; section
;  7 6 5 4 3 2 1 0 ; bit number
;  0 0 1 1 1 0 0 0 
