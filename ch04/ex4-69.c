// 4.11.2 피즐페이드

boolean FizzleFade {
  long rndval = 1;
  int x,y;
  do{
    // 난수값을 x/y 쌍으로 분리
    asm mov ax,[WORD PTR rndval]
    asm mov dx,[WORD PTR rndval+2]
    asm mov bx,ax
    asm dec bl
    asm mov [BYTE PTR y],bl // 하위 8 bits - 1 = y
    asm mov bx,ax
    asm mov cx,dx
    asm mov [BYTE PTR x],ah // 다음 9 bits = x
    asm mov [BYTE PTR x+1],dl

    // 다음 난수 항목으로 이동
    asm shr dx,1
    asm rcr ax,1
    asm jnc noxor
    asm xor dx,0x0001
    asm xor ax,0x2000
noxor:
    asm mov [WORD PTR rndval],ax
    asm mov [WORD PTR rndval+2],dx

    if (x>width || y>height) continue;

    copy_screen_pixel(x,y);

    if (rndval == 1) return false;  // 마지막 순서
  } while (1)
}