global res
global va
global vb
global shrt_int
global mas
global len

section .bss
    res resb 4
    va resb 2
    vb resb 2
    mas resb 20
    len resb 1

section .text
shrt_int:
    push rbx
    xor rax, rax
    xor rbx, rbx
    xor rcx, rcx
    xor rdx, rdx
    mov cl, [len]
    shl rcx, 1
    movsx rsi, word [va]
    movsx rdi, word [vb]
    jmp cikl
cikl: 
    cmp rcx, rbx
    je end
    movsx rdx, word [mas + rbx]
    add rbx, 2
    cmp rdx, rsi
    jge more
    jmp cikl
more:
    cmp rdx, rdi
    jle less
    jmp cikl
less:
    add rax, rdx
    jmp cikl
end:
    mov [res], rax
    pop rbx
    ret