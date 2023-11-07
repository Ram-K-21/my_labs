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
    mas resb 10
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
    movsx rax, word [mas + ebx]
    cmp rax, rsi
    jge more
    jl no
more:
    cmp rax, rdi
    jle less
    jg no
less:
    mov rax, [res]
    add rax, [mas + ebx]
    mov [res], rax
    add rbx, 2
    loop cikl
no:
    add rbx, 2
    loop cikl
end:
    pop rax
    ret