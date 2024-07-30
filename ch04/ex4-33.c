// 다음으로 호출한다
// DS:SI  확장을 위한 출발지
// ES:DI  확장을 위한 목적지
unsigned BuildCompScale (int height, byte far *code)
  [...]
  work = (t_compscale far *)code;
  code = &work->code[0];
  [...]
  for (src=0;src<=64;src++) {

    if (not_result_in_written_pixel)
      continue;
    
    // mov al,[si+src]   (src를 레지스터 al로 읽는다)
    *code++ = 0x8a;
    *code++ = 0x44;
    *code++ = src;

    for (magnification_size) {
      // mov [es:di + heightofs].,al   (al을 목적지에 기록한다)
      *code ++ = 0x26;
      *code ++ = 0x88;
      *code ++ = 0x85;
      *((unsigned far *)code)++ = startpix*SCREENBWIDE;
    }
  }
  // retf
  *code++ = 0xcb;
}