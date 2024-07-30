void PlayLoop () {
    PollControll ();        // 게임에 필요한 입력을 받음

    MoveDoors ();           // 문 이동
    MovePWalls ();          // 비밀 벽 이동
    for (obj = player; obj; obj = obj->next)
      DoActor (obj);        // 적에게 생각할 기회를 줌
    
    ThreeDRefresh () {      // 3D 뷰를 렌더링
      VGAClearScreen ();    // 마루/천장을 그림
      WallRefresh ();       // 벽을 그림
      DrawScaleds ();       // 확대한 스프라이트를 그림
      DrawPlayerWeapon ();  // 무기를 그림
      [...]                 // CRT 컨트롤러를 통해 프레임 버퍼를 뒤집음
    }
    UpdateSoundLoc ();      // 스테레오 사운드 위치 갱신
}