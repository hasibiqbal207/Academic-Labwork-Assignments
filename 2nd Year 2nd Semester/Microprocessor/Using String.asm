name "string"

org 100h
jmp start
array db 00,00,00,00,00,00,00,00,00 
str1  db 'Safial 41'
len1 equ ($-str1)
str2  db 'Safila 14' 
len2 equ ($-str2)

start: 

    mov al,len1
    mov ah,len2
    mov bx,0000h
    mov cx,len1
    mov dl,0000h
    cmp al,ah
    je X 
    ;cmp al,ah
    jne exit
X: 
    mov al,str1[bx]
    mov dl,str2[bx]
    cmp al,dl
    je Z
    ;cmp al,dl
    jne Y
    Y:
        ;jmp exit 
        inc bx
        LOOP X
    Z: 
        mov array[bx],01h
        inc bx
        loop X
exit:
     nop
     
end 