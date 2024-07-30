// 4.9.6 PC 스피커: PCM

void SDL_PlayDigiSegment(memptr addr,word len) {
    switch (DigiMode)
    {
    case sds_PC:  // 결코 사용되지 않음 :(
        SDL_PCPlaySample(addr,len);  break;
    case sds_SoundSource:
        SDL_SSPlaySample(addr,len);  break;
    case sds_SoundBlaster:
        SDL_SBPlaySample(addr,len);  break;
    }
}