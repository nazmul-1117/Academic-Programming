
.MODEL SMALL
.STACK 100H

.DATA
    data1 DB 5
    data2 DB 3
    result DB ?

.CODE
    MAIN PROC
        
        ;Load data from data segment
        MOV AX, @DATA
        MOV DS, AX 
        
        MOV al, data1
        MUL data2
        MOV result, al 
        
        MOV dl, result
        ;ADD dl, 55
        MOV ah, 02h
        INT 21h
        
        MOV AH, 4CH
        INT 21H
     
    MAIN ENDP
END MAIN