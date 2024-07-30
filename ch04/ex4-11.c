#define SC_INDEX        0x03c4
#define SC_DATA         0x03c5

#define CRTC_INDEX      0x03d4
#define CRTC_DATA       0x03d5

#define MEMORY_MODE     0x04
#define CRTC_UNDERLINE  0x14
#define CRTC_MODE       0x17

void VL_DePlaneVGA() {
  // VRAM 기록 방식을 변경한다(제친-4를 비활성화한다)
  outp(SC_INDEX, MEMORY_MODE);
  outp(SC_DATA, (inp(SC_DATA)&~8));

  // 모드 13h를 설정할 때 BIOS가 개별 뱅크의 첫 16K만 정리했기에
  // 모든 네 뱅크를 정리한다
  VL_ClearVideo (0);

  // VRAM을 CRTC가 읽는 방식을 변경한다
  // 주소 지정 모드는 CRTC_MODE 레지스터로 선택된다
  outp(CRTC_INDEX, CRTC_UNDERLINE);
  outp(CRTC_DATA, 0x00);
  // CRTC 주소 지정 모드는 바이트로 지정한다
  outp(CRTC_INDEX, CRTC_MODE);
  outp(CRTC_DATA, 0xa3);
}