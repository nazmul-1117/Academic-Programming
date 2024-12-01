  .MODEL SMALL
.STACK 100h

.DATA
    msg db "Enter digit: $"
    output_msg db "Your entired digit: $" 
    enter_msg db "You press enter.$"
    not_enter_msg db "You did not press enter.$"
    
    result Db ?

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
        
        jmp endX
                

    endX:
    
    MOV AH, 4Ch
    INT 21h

MAIN ENDP
END MAIN