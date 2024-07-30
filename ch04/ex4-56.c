// 4.9.4 사운드 블라스터 프로 시스템: 스테레오 PCM

#define    sbOut(n, b)    outportb((n) + sbLocation,b)

#define    sbpMixerAddr    0x204
#define    sbpMixerData    0x205

//  사운드 블라스터 프로 믹서 주소
#define    sbpmVoiceVol    0x04

static void SDL_PositionSBP(int leftpos,int rightpos) {
    byte    v;

    if (!SBProPresent)
        return;

    leftpos = 15 - leftpos;
    rightpos = 15 - rightpos;
    v = ((leftpos & 0x0f) << 4) | (rightpos & 0x0f);

    asm    pushf
    asm    cli

    sbOut(sbpMixerAddr,sbpmVoiceVol);
    sbOut(sbpMixerData,v);

    asm    popf
}