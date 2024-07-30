MACRO DOFX
  les di,[pcSound]       ; PC 사운드 효과
  mov ax,es
  or ax,di
  jz @@nopc              ; PC 사운드 효과 없음

  mov bl,[es:di]         ; 바이트 얻기
  inc [WORD PTR pcSound] ; 포인터 증가
  cmp [pcLastSample],bl  ; 이 샘플이 마지막과 동일한가?
  jz @@pcsame            ; 그렇다면 아무 일도 하지 않는다
  mov [pcLastSample],bl  ; 아니라면 다음을 위해 저장

  or bl,bl
  jz @@pcoff             ; 0이면 사운드 끄기
  xor bh,bh
  shl bx,1
  mov bx,[pcSoundLookup+bx] ; 참조로 바이트 사용

  mov al,ob6h            ; 채널 2 (스피커) 타이머 선택
  out pcTAccess,al
  mov al,bl
  out pcTimer,al         ; 하위 바이트
  mov al,bh
  out pcTimer,al         ; 상위 바이트

  in al , pcSpeaker      ; 스피커와 게이트 켜기
  or al ,3
  out pcSpeaker ,al