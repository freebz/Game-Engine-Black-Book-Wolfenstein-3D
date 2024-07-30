// 4.7.5.7 세로선 높이 계산

int CalcHeight (void)
{
  fixed gxt,gyt,nx,ny;
  long  gx,gy;

  gx = xintercept-viewx;
  gyt = FixedByFrac(gy,viewsin);

  gy = yintercept-viewy;
  gyt = FixedByFrac(gy,viewsin);

  nx = gxt-gyt;

  //
  // 원근 비율을 계산함(heightnumerator/(nx>>8))
  //
  if (nx<mindist)
    nx=mindist;         // 나누기 오버플로를 허용하지 않는다

    asm mov ax,[WORD PTR heightnumerator]
    asm mov dx,[WORD PTR heightnumerator+2]
    asm idiv  [WORD PTR nx+1]      // nx>>8
}