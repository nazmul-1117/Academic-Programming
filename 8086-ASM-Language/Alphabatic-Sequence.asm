.model small
.stack 100h

.data
    msg1 db "Enter first character: $"
    msg2 db "Enter second character: $"
    display_msg db "The input sequence: $"
    output_msg db "The alphabatic sequence: $"
    
    first_char db ?
    second_char db ?
    
.code
    main proc
        
        mov ax, @data
        mov ds, ax
           
           
        ;message for take first character
        lea dx, msg1
        mov ah, 09h
        int 21h
        
        
        ;take first input
        mov ah, 01h
        int 21h
        
        ;save character
        mov first_char, al
        
        
        ;new line print
        mov ah, 02h
        mov dl, 0dh
        int 21h
        
        mov dl, 0ah
        int 21h
        
        
        ;message for take second character
        lea dx, msg2
        mov ah, 09h
        int 21h
        
        ;take second input
        mov ah, 01h
        int 21h
        
        ;save second character
        mov second_char, al
        
        ;new line print
        mov ah, 02h
        mov dl, 0dh
        int 21h
        
        mov dl, 0ah
        int 21h
                           
                           
        ;message for output
        lea dx, display_msg
        mov ah, 09h
        int 21h 
              
              
        ;output charcter
        mov dl, first_char
        mov ah, 02h
        int 21h
        
        mov dl, second_char
        mov ah, 02h
        int 21h
        
        
        ;new line
        mov ah, 02h
        mov dl, 0dh
        int 21h
        
        mov dl, 0ah
        int 21h
        
        
        ;output message
        lea dx, output_msg
        mov ah, 09h
        int 21h
        
        
        ;compare both character 
        
        mov bl, first_char
        mov bh, second_char
        
        cmp bl, bh
            jae larger_
            mov dl, bl
            mov ah, 02h
            int 21h
            
            mov dl, bh
            mov ah, 02h
            int 21h
            
            jmp end_
            
            larger_:
                 mov dl, bh
                 mov ah, 02h
                 int 21h
                 
                 mov dl, bl
                 mov ah, 02h
                 int 21h
            
            end_:
               mov ah, 4ch
               int 21h
               

    main endp
end main