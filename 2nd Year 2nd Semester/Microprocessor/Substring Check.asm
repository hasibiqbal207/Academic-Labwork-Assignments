
org 100h

str1 db "kuetabskuet"
len1 equ ($-str1)

str2 db "kuet"
len2 equ ($-str2)

mov si,offset str1
mov di,offset str2

mov cx,len1

start:
    
    cld
    repe 