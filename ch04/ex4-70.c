// 4.11.3 팔레트

/*
=================
= VL_SetPalette
= 빠른 팔레트 설정을 테스트하고, 이를 사용한다
= (몇몇 카드는 outsb 팔레트 설정을 좋아하지 않는다)
=================
*/

void VL_SetPalette (byte far *palette) {
  asm mov dx,PEL_WRITE_ADR
  asm mov al,0
  asm out dx,al
  asm mov dx,PEL_DATA
  asm lds si,[palette]

  asm test [ss:fastpalette],1
  asm jz slowset
// 받아들일 수 있는 카드를 위해 팔레트를 빠르게 설정한다
  asm mov cx,768
  asm rep outsb
  asm jmp done

// 몇몇 비디오 카드를 위해 팔레트를 천천히 설정한다
slowset:
  asm mov cx,256
setloop:
  asm lodsb
  asm out dx,al
  asm lodsh
  asm out dx,al
  asm lodsb
  asm out dx,al
  asm loop  setloop

done:
  asm mov ax,ss
  asm mov ds,ax
}