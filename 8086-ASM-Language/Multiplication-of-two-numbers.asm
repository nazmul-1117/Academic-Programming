
.MODEL SMALL
.STACK 100H

.DATA
    input_msg1 DB "Enter First Number: $"
    input_msg2 DB "Enter Second Number: $"
    output_msg DB "The Multiplication is: $"

.CODE
    MAIN PROC
        
        ;Load data from data segment
        MOV AX, @DATA
        MOV DS, AX
        
        ;Display first message
        LEA dx, input_msg1
        MOV ah,  09H
        int 21H
        
        ;take first input from users
        MOV ah, 01h
        int 21h
        
        ;Convert character to integers
        SUB al, 48
        MOV bl, al
        
        
        ;New Line 
        MOV ah, 02h
        MOV dl, 0dh
        int 21h
        
        MOV dl, 0ah
        int 21h
        
        ;Display second message
        LEA dx, input_msg2
        MOV ah, 09h
        int 21h 
        
        ; Take second data from user
        MOV ah, 01h
        int 21h
        
        ;Convert character to integer
        SUB al, 48
        MOV bh, al 
        
        MOV al, bl
        MUL bh
        MOV bl, al
        
        ;Covert integers to character
        ;ADD bl, 2
        ADD bl, 48
        ;ADD bh, 48
        
        ;New Line
        MOV ah, 02h
        MOV dl, 0dh
        int 21h
        
        MOV dl, 0ah
        int 21h
        
        ;Output Message
        LEA dx, output_msg
        MOV ah, 09h
        int 21h
        
        ;simple output
        MOV dl, bl
        MOV ah, 02h
        int 21h
        
        
        
        MOV AH, 4CH
        INT 21H
     
    MAIN ENDP
END MAIN