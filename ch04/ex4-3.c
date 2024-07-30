void InitGame () {
    MM_Startup ();      // 메모리 관리자

    SignonScreen ();    // 시스템 구성을 보여줌

    VW_Startup ();      // 비디오 관리자
    IN_Startup ();      // 입력 관리자
    PM_Startup ();      // 페이지 관리자
    PM_UnlockMainMem ();
    SD_Startup ();      // 사운드 관리자
    CA_Startup ();      // 캐시 관리자
    US_Startup ();      // 폰트 관리자
    InitDigiMap ();
    ReadConfig ();
    CA_CacheGrChunk(STARTFONT); // 폰트 로드
    MM_SetLock (&grsegs[STARTFONT],true); // 폰트 잠그기
    LoadLatchMem ();    // 그림 자원을 VRAM에 로드
    BuildTables ();     // sin/cos/view 참조 테이블
    SetupWalls ();      // 벽 텍스처 참조 테이블
}