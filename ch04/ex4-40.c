asm mov ax,ds
asm mov ex,ax
asm mov di.OFFSET spotvis // 초기화할 배열
asm xor ax,ax    // ax에 0을 넣는다
asm mov cx,2048  // 다음 명령어를 64*64/2만큼 수행한다
asm rep stosw    // ax를 es:di에 저장한다