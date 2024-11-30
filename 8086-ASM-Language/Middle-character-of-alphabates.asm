
.MODEL SMALL
.STACK 100H

.DATA
    data1 DB "A"
    data2 DB "Z"
    output_msg DB "Your Output: $"
    result DB ?

.CODE
    MAIN PROC
        
        ;Load data from data segment
        MOV AX, @DATA
        MOV DS, AX 
        
        MOV dl, data1
        MOV ah, 02h
        INT 21h
        
        mov dl, data2
        mov ah, 02h
        int 21h
        
        mov bl, data1
        mov bh, data2
        SUB bh, bl
        mov result, bh
        
        ADD result, 48
        mov al, result
        mov cl, 2
        div cl 
        
        mov result, al
        
        lea dx, output_msg
        mov ah, 09h
        int 21h
        
        MOV dl, result
        ;ADD dl, 55
        MOV ah, 02h
        INT 21h
        
        MOV AH, 4CH
        INT 21H
     
    MAIN ENDP
END MAIN