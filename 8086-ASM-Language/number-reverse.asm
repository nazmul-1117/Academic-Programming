  .MODEL SMALL
.STACK 100h

.DATA
    msg db "Enter digit: $"
    output_msg db "Your entired digit: $" 
    enter_msg db "You press enter.$"
    not_enter_msg db "You did not press enter.$" 
    reverse_msg db "Reverse digit is: $"
    
    result Db ?
    reverse db ?

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX


    lea dx, msg
    mov ah, 09h
    int 21h
    
    mov result, 0
    mov bl, 10
    
    loopX:
        mov ah, 01h
        int 21h
        
        cmp al, 13
        je enter_press
        
        sub al, 48
        mov cl, al
        mov al, result
        mul bl
        add al, cl
        mov result, al
        
        jmp loopX
        
        
        
    enter_press:
    
        lea dx, enter_msg
        mov ah, 09h
        int 21h
        
        mov dl, result
        mov ah, 02h
        int 21h
        
        jmp reverse_digit
        
        hlt
        
    
        mov cx, 3
        mov bl, 10
        mov dl, result
        
     reverse_digit:
        CMP CX, 0
        JE output_
        
        cmp cx, 3
        ja output_
    
        MOV AL, DL
        DIV BL
        MOV DL, AL
        MOV AL, AH
        MUL BL
        MOV reverse, AL
    
        DEC CX
        JMP reverse_digit
    
    output_:    
        lea dx, reverse_msg
        mov ah, 09h
        int 21h
        
        mov dl, reverse_digit
        mov ah, 02h
        int 21h
        
        hlt
        
        
                
                

    endX:
    
    MOV AH, 4Ch
    INT 21h

MAIN ENDP
END MAIN