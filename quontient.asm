extern APHORISM
extern PROVERB
extern RIDDLE


global Quotient
Quotient:
section .text
push rbp
mov rbp, rsp

    mov eax, [rdi]
    add eax, [rdi+4]
    shl eax, 1
    cvtsi2sd    xmm0, eax

leave
ret


global QuotientOfPhrases
QuotientOfPhrases:
section .text
push rbp
mov rbp, rsp

    mov eax, [rdi]
    cmp eax, [APHORISM]
    je .aphQuotient
    cmp eax, [PROVERB]
    je .provQuotient
    cmp eax, [RIDDLE]
    je .ridQuotient
    xor eax, eax
    cvtsi2sd    xmm0, eax
    jmp     .return
 .aphQuotient:
    add     rdi, 4
    call    Quotient
    jmp     .return
 .provQuotient:
    add     rdi, 4
    call    Quotient
    jmp     .return
 .ridQuotient:
    add     rdi, 4
    call    Quotient
.return:
leave
ret


global ArithmeticMeanOfQuotients
ArithmeticMeanOfQuotients:
section .data
    .sum    dq  0.0
section .text
push rbp
mov rbp, rsp

    mov rbx, rsi            
    xor rcx, rcx            
    movsd xmm1, [.sum]      
.loop:
    cmp rcx, rbx            
    jge .return             

    mov r10, rdi            
    call QuotientOfPhrases     
    addsd xmm1, xmm0        
    inc rcx                 
    add r10, 16             
    mov rdi, r10            
    jmp .loop
.return:
    movsd xmm0, xmm1
leave
ret
