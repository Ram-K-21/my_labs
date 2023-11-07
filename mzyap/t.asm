%include "io64.inc"

section .data
    mas dw 12, 2, 7, 3, 2, 0, 21, 9, 0, 16
    len dw $-mas
    va dw 3
    vb dw 10
    ;va dw -31000
    ;vb dw -30000
    ;vd dw 1
    
section .bss
    res resb 4
    ;divd resb 4
    ;divr resb 4   

section .text
;(b+a)/(a-1) a>b
;23 a=b
;b*b/8 a<b
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    jmp intt
intt:
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx
    lea esi, mas
    mov cx, [len]
    shr cx, 1
    mov bx, [va]
    mov dx, [vb]
    jmp cikl
cikl: 
    mov ax, [esi]
    cmp ax, bx
    jg more
    jl no
more:
    cmp ax, dx
    jl less
    jg no
less:
    mov eax, [res]
    add eax, [esi]
    mov [res], eax
    add esi, 2
    loop cikl
no:
    add esi, 2
    loop cikl
    
    