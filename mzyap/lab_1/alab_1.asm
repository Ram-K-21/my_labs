global unint
global unch
global snch
global res
global divd
global divr
global va
global vb
global vd


section .bss

    res resb 4
    divd resb 4
    divr resb 4
    va resb 2
    vb resb 2
    vd resb 2

section .text
;(2*d-96/a)/(34/b-a+1)
snch:
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx
    mov al, [vd]
    mov ah, 2
    imul ah
    cwd
    mov bx, ax
    mov ax, 96
    mov cl, [va]
    test cl, cl
    jz divz
    idiv cl
    cbw
    sub bx, ax
    mov [divd], bx
    mov ax, 34
    mov bl, [vb]
    test bl, bl
    jz divz
    idiv bl
    cbw
    mov bx, ax
    mov al, [va]
    cbw
    sub bx, ax
    add bx, 1
    mov [divr], bx
    jz divz
    mov ax, [divd]
    cwd
    idiv bx
    mov [res], ax
    ret

unch:
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx
    mov al, [vd]
    shl ax, 1
    mov bx, ax
    mov ax, 96
    mov cl, [va]
    test cl, cl
    jz divz
    div cl
    xor ah, ah
    sub bx, ax
    mov [divd], bx
    mov ax, 34
    mov cl, [vb]
    test cl, cl
    jz divz
    div cl
    xor ah, ah
    mov cl, [va]
    sub ax, cx
    add ax, 1
    mov [divr], ax
    jz divz
    mov bx, ax
    mov ax, [divd]
    cwd
    idiv bx
    mov [res], ax
    ret

unint:
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx
    mov ax, [vd]
    shl eax, 1
    mov ebx, eax
    mov eax, 96
    mov cx, [va]
    test cx, cx
    jz divz
    div ecx
    xor edx, edx
    sub ebx, eax
    mov [divd], ebx
    mov eax, 34
    mov cx, [vb]
    test cx, cx
    jz divz
    div ecx
    xor edx, edx
    mov cx, [va]
    sub eax, ecx
    add eax, 1
    mov [divr], eax
    jz divz
    mov ecx, eax
    mov eax, [divd]
    cdq
    idiv ecx 
    mov [res], eax
    ret
    
divz:
    mov dword [res], 0
    ret
