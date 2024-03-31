section .data
msg db "%.1lf",10,0

section .text
extern printf
bits 64
Default rel
global process


process:
    mov r10, rcx  ;have to use rcx for printing
    xor ebx, ebx  ; Counter initialization
loop:
    

    ;cmp ebx, edx
    ;jge end
    ;cmp qword [r10 + rax * 2 - 16], 0
    ;jl end
    ;add r10, 8

    movsd xmm1, [r10 + rax * 2 - 16] ; Load num[i - 3] to xmm1
    movsd xmm2, [r10 + rax * 2 - 8]  ; Load num[i - 2] to xmm2
    movsd xmm3, [r10 + rax * 2]      ; Load num[i - 1] to xmm3
    movsd xmm4, [r10 + rax * 2 + 8]  ; Load num[i] to xmm4
    movsd xmm5, [r10 + rax * 2 + 16] ; Load num[i + 1] to xmm5
    movsd xmm6, [r10 + rax * 4 + 8]  ; Load num[i + 2] to xmm6
    movsd xmm7, [r10 + rax * 4 + 16] ; Load num[i + 3] to xmm7
    
    xorps xmm0, xmm0

    addsd xmm0, xmm1    ; xmm0 = xmm0 + xmm1
    addsd xmm0, xmm2    ; xmm0 = xmm0 + xmm2
    addsd xmm0, xmm3    ; xmm0 = xmm0 + xmm3
    addsd xmm0, xmm4    ; xmm0 = xmm0 + xmm4
    addsd xmm0, xmm5    ; xmm0 = xmm0 + xmm5
    addsd xmm0, xmm6    ; xmm0 = xmm0 + xmm6
    addsd xmm0, xmm7    ; xmm0 = xmm0 + xmm7

    
    sub rsp, 8*7

    lea rcx, [msg]
    movq rdx, xmm0
    call printf

    add rsp, 8*7
    

    ;inc ebx

    ;jmp loop

end:

    
    ret
