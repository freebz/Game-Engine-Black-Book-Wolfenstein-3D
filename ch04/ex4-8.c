// 4.5.1 사인온

// GAMEPAL.OBJ의 내용:
// 256 * 3 = 768바이트를 차지
extern byte far gamepal;

// SIGNON.OBJ의 내용
// 320x200 = 64,000바이트를 차지
extern char far introscn;

void SignonScreen (void)
{
  unsigned  segment,seglength;

  VL_SetVGAPlaneMode ();
  VL_TestPaletteSet ();
  VL_SetPalette (&gamepal);

  if (!virtualreality)
  {
    VW_SetScreen(0x8000,0);
    VL_MungePic(&introscn,320,200);
    VL_MemToScreen(&introscn,320,200,0,0);
    VW_SetScreen(0,0);
  }

  // 링크된 사인온 화면으로부터 메모리를 회수
  segstart = FP_SEG(&introscn);
  seglength = 64000/16;
  if (FP_OFF(&introscn)){
    segstart++;
    seglength--;
  }
  MML_UseSpace (segstart,seglength);
}