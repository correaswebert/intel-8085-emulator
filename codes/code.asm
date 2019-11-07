LXI H, 8000H ;location of the first number 
MOV B,M      ;store that number in B 
INX H        ;location of the second number 
XRA A        ;clear A 
MOV C,A      ; 
ADD M        ; 
JNC f00cH    ; 
INR C        ; 
DCR B        ; 
JNZ f007H    ; 
LXI H, 8050H ; 
MOV M,C      ; 
INX H        ; 
MOV M,A      ; 
HLT          ; 