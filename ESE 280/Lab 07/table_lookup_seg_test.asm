;
; table_lookup_seg_test.asm
;
; Created: 10/11/2022 11:32:12 AM
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
	ldi r16, 0xF0		; Set to ones since the transistor is essentially active low (turn all digits off)
	out VPORTA_OUT, r16	;

	; Set up DIP Switches as input
	ldi r16, 0xFF		; All 1's for output
	out VPORTC_DIR, r16	;

	clr r16				; Clear register

	cbi VPORTA_OUT, 7	; turn on the 4th digit on 7-seg display

main: 
	in r16, VPORTC_IN	; Read in from dip switches and save to r16

	rcall reverse_bits	; Call reverse_bits to reverse register r16

	mov r18, r16		; Copy register 16 to 18

	rcall hex_to_7seg	;

	out VPORTD_OUT, r18	; Output to 7 seg display

	rjmp main			; loop


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
	
	mov r16, r17		; Copy r17 to r16
	clr r17			; Default to 0
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
