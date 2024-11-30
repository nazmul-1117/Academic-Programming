
.MODEL SMALL
  .STACK 100H
  
  .DATA
    input_msg db "Enter Your Message: $"
    output_msg db "Your Entered Message is: $"
  
  .CODE
    MAIN PROC
        
        MOV ax, @data
        MOV ds, ax 
        
        LEA dx, input_msg   
        MOV ah, 09h
        int 21h
        
        MOV ah, 01H  ;take input and it will automatically save in AL resistor
        int 21H
        
        
        ;i use ah in line 18, when i use AH then AL will be erase. that's why i store it into another resisteer
        MOV bl, al
        
        ;new line print
        MOV ah, 02h
        MOV dl, 0dh
        int 21H
        
        MOV dl, 0ah
        int 21h
        ;new line end
        
        ;output message
        LEA dx, output_msg   
        MOV ah, 09h
        int 21h
        
        MOV dl, bl  ;print dl register value
        MOV ah, 02H
        int 21H 
        
        MOV AH, 4CH
        INT 21H
    
    MAIN ENDP
  END MAIN