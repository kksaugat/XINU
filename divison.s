	AREA  LAB2,CODE,READWRITE
	 EXPORT div_and_mod
	 
div_and_mod
                STMFD r13!, {r2-r12,r14}
                MOV r5,#0  ; setting r5 to 0 to keep track whether the dividend is pos or neg
                CMP r1,#0 ; comparing dividen with 0
 		        BLT complement ;if its less than 0 go to complement
initialize	    MOV r3,#15; set counter to 15
	            MOV r2,#0; set quotient to 0
	            MOV r0,r0,LSL#15 ; shift 15 places to left
	            MOV r4,r1; set remainder to dividend
		        B routine0
complement      MVN r1,r1 ; take one's complement
                ADD r1,r1,#1 ; add one for two's complement
                MOV r5,#1 ; r5 set to 1 since the dividend was negative				
			    B initialize ; branch to initialize

routine0        SUB r4,r4,r0; subtract divisor from remainder
                CMP r4,#0; compare remainder with 0
	            BLT routine; if its less than 0 go to routine
	            MOV r2,r2,LSL#1 ; shift quotient one place to left
	            ADD r2,r2,#1 ; add one for LSB =1
	            MOV r0,r0,LSR#1; shift divisor 1 places to right
	            B comparison  ; Branch to comparison
	 
routine         ADD r4,r4,r0; Add remainder with divisor
                MOV r2,r2,LSL#1; Shift quotient one place to left
		        MOV r0,r0,LSR#1 ; shift divisor one place to right
		        B comparison;  Branch to comparison
		
comparison      CMP r3,#0 ; compare counter to 0
                BGT decrement; if its greater decrement
		        B check; Branch to check if its less or equal
decrement      SUB r3,r3,#1; counter=counter-1
               B routine0; Branch to routine0
check               MOV r0,r4; Initialize the remainder to r0
               CMP r5,#0; Compare r5
			   BGT finalcomplement; if r5 is 1 then need to negate again
			   B finish; if its positive just branch to finish
			   
finalcomplement   MVN r2,r2 ; one's complement
                         ADD r2,r2,#1; add one for two's complement
                      B finish; done
               
finish		   MOV r1,r2; initialize quotient to r1
		       LDMFD r13!,{r2-r12,r14}
		       BX lr;
		   
		       END