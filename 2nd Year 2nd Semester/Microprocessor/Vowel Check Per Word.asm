org 100h

 


mov dx,0000h
mov si,offset str
mov di,offset vowel
mov cx,len1

start:
    mov    al,[si] 
    
    cmp    al,' '
    je     refine                 
                 
    cmp    al,'a'     
    je     increment
    
    cmp    al,'e'     
    je     increment
    
    cmp    al,'i'     
    je     increment 
    
    cmp    al,'o'     
    je     increment  
    
    cmp    al,'u'     
    je     increment        
    
    jmp check 
    
    increment:
        inc dx 
        jmp check
        
    refine:
        mov [di],dx
        inc di
        mov dx,0000h       
            
    
    check:
    inc si         
    loop start
    mov [di],dx
                
str db "pranto kuet"
len1 equ ($-str)

vowel db len1 dup(0)          
          
int 21h
ret
