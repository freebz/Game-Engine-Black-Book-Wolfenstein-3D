// 4.10 사용자 입력

// 4.10.1 키보드

#define KeyInt    9 // 키보드 ISR 번호

static void INL_StartKbd(void) {
  INL_KeyHook = NULL;   // 키 후크 루틴 없음

  IN_ClearKeyDown();

  OldKeyect = getvect(KeyInt);
  setvect(KeyInt,INL_KeyService);
}

static void interrupt INL_KeyService(void) {
  byte  k;
  k = inportb(0x60);  // 스캔 코드를 얻는다

  // XT 키보드 컨트롤러에게 키를 지우도록 요청한다
  outportb(0x61,(temp = inportb(0x61)) | 0x80);
  outportb(0x61,temp);

  [...] // 스캔 코드를 처리한다
  Keyboard[k] = XXX;

  outportb(0x20,0x20); // 시스템을 인터럽트하기 위한 인터럽트 ACK
}