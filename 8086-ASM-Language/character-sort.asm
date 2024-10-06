
;show input message 1
mov ah, 9h
mov dx, offset msg1
int 21h

;input character 1
mov ah, 01h
int 21h
   
;save character to bl resistor
mov bl, al

;new line print
mov ah, 09h
mov dx, offset newline
int 21h  


;show input message 2
mov ah, 9h
mov dx, offset msg2
int 21h

;input character 2
mov ah, 01h
int 21h
  
;save character to bh resistor
mov bh, al 

;new line
mov ah, 09h
mov dx, offset newline
int 21h

;show output message
mov ah, 9h
mov dx, offset output
int 21h

;show a single character
mov ah, 02h

cmp bl, bh
jae large 

    mov dl, bl
    int 21h
    
    mov dl, bh
    int 21h 
    
    jmp end

large:
    mov dl, bh
    int 21h
    
    mov dl, bl
    int 21h
          
             
end:
    mov ah, 4ch
    int 21h          
          
msg1 db "Enter First Character: $"
msg2 db "Enter Second Character: $"
output db "Sorted List: $" 
newline db 0dh, 0ah, "$"
