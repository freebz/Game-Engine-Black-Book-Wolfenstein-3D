void   near ScalePost (void)  // VGA 버전
{
    ...
    // 벽의 바이트 너비 조각을 확대
    asm mov  bx,[postx]             // posx = x 좌표
    asm mov  di,bx                  // 그릴 장소
    asm shr  di,2                   // X(바이트 단위)
    asm add  di,[bufferofs]

    asm and  bx,3
    asm shl  bx,3                   // bx = pixel * 8 + postwidth
    asm add  bx,[postwidth]

    // 1단계
    asm mov  al,BYTE PTR [mapmasks1-1+bx]
    asm mov  dx,SC_INDEX+1
    asm out  dx,al                  // VGA 뱅크 마스크를 설정함
    asm lds  si,DWORD PTR [postsource]
    asm call DWORD PTR [bp]

    // 2단계
    asm mov  al,BYTE PTR [ss:mapmasks2-1+bx]
    asm or   al,al
    asm jz   nomore
    asm inc  di
    asm out  dx,al                  // VGA 뱅크 마스크를 설정함
    asm call DWORD PTR [bp]         // 컴파일된 스케일러를 호출함

    [...]

    // 3단계
nomore:
}