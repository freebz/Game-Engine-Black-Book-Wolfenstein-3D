fixed FixedByFrac (fixed a, fixed b) {
asm mov si,[WORD PTR b+2]   // 결과의 부효 =
                            // 분수의 부호
asm mov ax,[WORD PTR a]
asm mov cx,[WORD PTR a+2]

asm or  cx,cx
asm jns aok:         // 음수?
asm neg cx
asm neg ax
asm sbb cx,0
asm xor si,0x8000       // 결과 부호를 뒤집기
aok:

// cx:ax와 bx를 곱하기
asm mov bx,[WORD PTR b]
asm mul bx           // 분수*분수
asm mov di,dx        // di는 결과의 하위 워드
asm mov ax,cx        //
asm mul bx           // 단위 * 분수
asm add ax,di
asm adc dx,0

// 결과를 2의 보수로 dx:ax에 넣기
asm test  si,0x8000   // 결과가 음수인가?
asm jz  ansok:
asm neg dx
asm neg ax
asm sbb dx,0

ansok :;   // ASM으로 반환값을 고정
}