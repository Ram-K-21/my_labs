global unint
global intt
global res
global va
global vb


section .bss

    res resb 4
    va resb 2
    vb resb 2

section .text
;(b+a)/(a-1) a>b
;23 a=b
;b*b/8 a<b
unint:
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx
    mov ax, [va]
    mov bx, [vb]
    cmp ax, bx
    je equal
    ja umore
    jb uless
    ret
intt:
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx
    mov ax, [va]
    mov bx, [vb]
    cmp ax, bx
    je equal
    jg more
    jl less
    ret

equal:
    mov dword [res], 23
    ret

umore:
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx
    mov ax, [vb]
    mov bx, [va]
    add eax, ebx
    dec ebx
    test ebx, ebx
    jz divz
    div ebx
    mov [res], eax
    ret
more:
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx
    mov ax, [vb]
    add ax, [va]
    cwde
    mov ecx, eax
    mov ax, [va]
    cwde
    dec eax
    jz divz
    mov ebx, eax
    mov eax, ecx
    cdq
    idiv ebx
    mov [res], eax
    ret

uless:
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx
    mov ax, [vb]
    mul eax
    mov bx, 8
    div ebx
    mov [res], eax
    ret
less:
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx
    mov ax, [vb]
    cwde
    imul eax
    mov bx, 8
    idiv ebx
    mov [res], eax
    ret

divz:
    mov dword [res], 0
    ret
