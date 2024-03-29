section .data


section .text
global process



process:
    push rbp
    mov rbp, rsp
    
    ; Initialize loop variables
    mov r8, 3           ; r8 = start
    mov r9, rsi         ; r9 = size
    xorpd xmm0, xmm0    ; result = 0
    
loop:
    cmp r8, r9          ; Compare iteration with size
    jg end             ; If iteration > size, end loop
    
    ; Check if any index is out of bounds
    mov rax, r8
    sub rax, 3
    jl out_of_bounds
    
    mov rax, r8
    add rax, 3
    cmp rax, r9
    jg out_of_bounds
    
    ; Calculate the result
    mov rax, r8
    movsd xmm1, [rcx + rax * 2 - 16] ; Load num[i - 3] to xmm1
    movsd xmm2, [rcx + rax * 2 - 8]  ; Load num[i - 2] to xmm2
    movsd xmm3, [rcx + rax * 2]      ; Load num[i - 1] to xmm3
    movsd xmm4, [rcx + rax * 2 + 8]  ; Load num[i] to xmm4
    movsd xmm5, [rcx + rax * 2 + 16] ; Load num[i + 1] to xmm5
    movsd xmm6, [rcx + rax * 4 + 8]  ; Load num[i + 2] to xmm6
    movsd xmm7, [rcx + rax * 4 + 16] ; Load num[i + 3] to xmm7
    addsd xmm0, xmm1    ; xmm0 = xmm0 + xmm1
    addsd xmm0, xmm2    ; xmm0 = xmm0 + xmm2
    addsd xmm0, xmm3    ; xmm0 = xmm0 + xmm3
    addsd xmm0, xmm4    ; xmm0 = xmm0 + xmm4
    addsd xmm0, xmm5    ; xmm0 = xmm0 + xmm5
    addsd xmm0, xmm6    ; xmm0 = xmm0 + xmm6
    addsd xmm0, xmm7    ; xmm0 = xmm0 + xmm7
    
    
    
    inc r8              ; Increment iteration
    jmp loop
    
out_of_bounds:
    ; Print 0 if out of bounds
  
    
    inc r8              ; Increment iteration
    jmp loop
 
end:
    ;cvtsd2si rax, xmm0      ; Move result to rax for return
   ; pop rbp
    ret
