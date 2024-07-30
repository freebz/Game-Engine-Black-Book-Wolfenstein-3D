void VL_SetVGAPlaneMode (void) {
  // 0x13으로 19번째 인터럽트 벡터를 호출한다
  // (BIOS에 모드 13H로 VGA를 설정하기 요청한다)
  asm mov ax,0x13
  asm int 0x10

  // 체인 해제(엔진에서 deplane을 호출한다)
  VL_DePlaneVGA ();
  VGAMAPMASK(15);
  VL_SetLineWidth (40);
}