PROC    SDL_t0ExtreamAsmService
PUBLIC  SDL_t0ExtreamAsmService
    ...

    les di,[pcSound]       ; 바이트를 얻기 위한 준비
    mov ax,es
    or  ax,di
    jz  00donereg          ; 널 포인터

    mov bl,[es:di]         ; PCM 바이트 얻기
    inc [WORD PTR pcSound] ; 포인터 증가

    and bl,1110000b        ; 정밀도를 줄이기 이해 폭격
                           ; ( DEBUG: 테이블로 이런 작업을 수행)
    xor bh,bh
    mov ah,[pcdtab+bx]     ; 바이트 변환

    in al,pcSpeaker
    and al,11111100b
    or  al,ah
    out pcSpeaker,al