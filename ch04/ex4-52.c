// 4.8.4 오디오 시스템

void    SD_Startup(void);
void    SD_Shutdown(void);

[...]
[...]

boolean SD_PlaySound(soundnames sound);
boolean SD_PositionSound(int leftvol,int rightvol);
void    SD_SetPosition(int leftvol,int rightvol);
void    SD_StopSound(void);
void    SD_WaitSoundDone(void);
word    SD_SoundPlaying(void);
word    SD_SetSoundMode(SDMode mode);

void    SD_StartMusic(SDMode mode);

void    SD_StartMusic(MusicGroup far *music);
void    SD_MusicOn(void);
void    SD_MusicOff(void);
void    SD_FadeOutMusic(void);
boolean SD_MusicPlaying(void);
boolean SD_SetMusicMode(Smmode mode);