asm  mov  cx, startScanOffset

asm  mov  dx,0x3d4  ; 3d4h는 CRTC 레지스터

asm  mov  al,0x0c   ; CRTC에 업데이트를 원한다고 알려줌
asm  out  dx,al     ; 시작 주소 상위 레지스터
asm  inc  dx
asm  mov  al,ch
asm  out  dx,al     ; 상위 바이트 설정

;*********** CRTC SCAN은 여기서 시작한다 !!!!!!!!!            *******
;*********** 그리고 일부 내용만 담긴 두 프레임 버퍼를 보여준다 *******


asm  mov  al,0xd    ; CRTC에 업데이트를 원한다고 알려줌
asm  out  dx,al     ; 시작 주소 하위 레지스터
asm  inc  dx
asm mov  al,cl
asm out  dx,al      ; 하위 바이트 설정