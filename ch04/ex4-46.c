asm mov bx,[ds:bp]           ; 패치할 rtl 테이블 위치
asm or  bx,bx
asm jz  linedone             ; 0은 세그먼트 목록의 끝을 알림
asm mov bx,[es:bx]
asm mov dl,[es:bx]           ; 예전 값을 저장
asm mov BYTE PTR es:[bx],OP_RETF  ; RETF를 패치
asm mov si,[ds:bp+4]         ; 테이블 위치 또는 진입점
asm mov ax,[es:si]
asm mov WORD PTR ss:[linescale],ax  ; 스케일링을 시작하기 위해 여기를 호출
asm mov si,[ds:bp+2]         ; 이 세그먼트를 위한 형상의 교정된 상단
asm add bp,6                 ; 다음 세그먼트 목록

asm mov ax,SCREENSEG
asm mov es,ax
asm call ss:[linescale]      ; 픽셀의 세그먼트 확대

asm mov es,cs                ; 스케일러의 세그먼트
asm mov BYTE PTR es:[bx],dt  ; RETF 패치 해제
asm jmp scalesingle          ; 다음 세그먼트를 수행