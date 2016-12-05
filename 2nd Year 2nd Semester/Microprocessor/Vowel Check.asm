
org 100h

; add your code here
str db "hasib iqbal pranto"  
len equ ($-str)
mov bx,0000h 
mov cx,len
mov dl,00h
    
start:
    mov    al,str[bx]           
    cmp    al, 'a'     
    je     increment
    cmp    al, 'e'     
    je     increment
    cmp    al, 'i'     
    je     increment
    cmp    al, 'o'     
    je     increment
    cmp    al, 'u'     
    je     increment 
    jmp y
    increment:
        inc dl
    y:
    inc bx  
        
    loop start

   
int 21h
ret




