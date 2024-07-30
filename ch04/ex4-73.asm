; =================================================
;
;
; int US_RndT (void)
; 0부터 255까지 난수값을 반환
; 반환 : AX = 값
;
;
; =================================================
PROC  US_RndT
  public  US_RndT

  mov ax, SEG rndtable
  mov es,ax
  mov bx,[es:rndindex]
  inc bx
  and bx,0ffh
  mov [es:rndindex],bx
  mov al,[es:rndtable+BX]
  xor ah,ah
  ret

ENDP