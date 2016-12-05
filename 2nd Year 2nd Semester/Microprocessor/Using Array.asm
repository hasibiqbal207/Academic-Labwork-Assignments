name "array"

org 100h
jmp start

array db 02,03,04,06,05
rev db 00,00,00,00,00

start:

mov al,0000h
mov ah,0000h
mov bx,0004h
mov cx,0005h
mov dl,0000h




X:
    mov al,array[bx] 
    mov rev[bx+4],al
    mov dl,rev[bx+4] 
    
    add ah,array[bx] 
    
    dec bx
    loop X 


int 21h 

ret