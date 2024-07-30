// 4.7.4 화면 지우기

void VGAClearScreen (void)
{
  unsigned ceiling=vgaCeiling[gamestate.episode*10+mapon];

  asm  mov  dx,SC_INDEX
  asm  mov  ax,SC_MAPMASK+15*256   // 모든 평면에 쓰기
  asm  out  dx,ax

  asm  mov  dx,80
  asm  mov  ax,[viewwidth]
  asm  shr  ax,2
  asm  sub  dx,ax       // dx = 40 - viewwidth / 2

  asm  mov  bx,[viewwidth]
  asm  shr  bx,3        // bl = viewwidth / 8
  asm  mov  bh,BYTE PTR[viewheight]
  asm  shr  bh,1        // 절반 높이

  asm  mov  es,[screenseg]
  asm  mov  di,[bufferofs]
  asm  mov  ax,[ceiling]

  toploop:              // 상단 루프. 한 행/순회
  asm  mov  cl,bl
  asm  rep  stosw
  asm  add  di,dx
  asm  dec  bh
  asm  jnz  toploop

  asm  mov  bh,BYTE PTR [viewheight]
  asm  shr  bh,1        // 절반 높이
  asm  mov  ax,0x1919

  bottomloop:           // 하단 루프. 한 행/순회
  asm  mov  cl,bl
  asm  rep  stosw
  asm  add  di,dx
  asm  dec  bh
  asm  jnz  bottomloop
}