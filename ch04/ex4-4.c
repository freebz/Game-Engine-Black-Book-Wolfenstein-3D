void DemoLoop() {
    StartCPMusic(INTROSONG);
    PG13(); // '엄청난 대학살' 심의 등급 화면을 보여줌
    while (1) {
        CA_CacheScreen (TITLEPIC);
        CA_CacheScreen (CREDITSPIC);
        DrawHighScores ();
        PlayDemo (0);
        GameLoop (); // 2D 랜더러(메뉴)
        SetupGameLevel ();
        StartMusic ();
        PM_CheckMainMem ();
        PreloadGraphics ();
        DrawLevel ();
        PlayLoop () ; // 3D 랜더러(게임)
        StopMusic ();
    }
    Quit("Demo loop exited???");
}