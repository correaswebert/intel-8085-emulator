MOV E,B         ; 2100H 
XRA A 
ADD D           ; 2103H 
DCR E 
JNZ 2102H 
MOV D,A 
RET 