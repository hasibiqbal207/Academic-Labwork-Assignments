org 100h

; add your code here      
str1 db "kuetandkuetkuet"
len1 equ ($-str1)

str2 db "kuet"
len2 equ ($-str2)


cld
mov cx,len2 
MOV DX,LEN1
mov ax,0000h

mov si,offset str1
mov di,offset str2

start: 
    add ax,cx   
    repe cmpsb          
    je MATCH 
    JMP NOTM     
    
    MATCH:
    INC BX
    
    
    
    
    NOTM:
    sub ax,cx
    MOV DI,OFFSET STR2
    MOV CX,LEN2     
    cmp ax,DX
    jne start
      

ret




      