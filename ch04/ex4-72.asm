; =================================================
;
;
; void US_InitRndT (boolean randomize)
; RND 생성기에 기반하여 테이블을 초기화
; randomize가 false면 카운터를 0으로 설정
;
;
; =================================================

PROC US_InitRndT randomize:word

  uses si,di
  public US_InitRndT

  mov ax,SEG rndtable
  mov es,ax

  mov ax,[randomize]
  or ax,ax
  jne @@timeit  ; randomize가 true면 진짜 난수

  mov dx,0     ; 확실한 값으로 설정
  jmp @@setit

@@itmeit:
  mov ah,2ch
  int 21h      ; GetSystemTime
  and dx,0ffh

@@setit:
  mov [es:rndindex],dx
  ret

ENDP