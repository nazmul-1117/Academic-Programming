
.MODEL SMALL
  .STACK 100H
  
  .DATA
  
  .CODE
    MAIN PROC 
        
        MOV ah, 01H  ;take input and it will automatically save in AL resistor
        int 21H
        
        MOV dl, al  ;print dl register value
        MOV ah, 02H
        int 21H
    
    MAIN ENDP
  END MAIN