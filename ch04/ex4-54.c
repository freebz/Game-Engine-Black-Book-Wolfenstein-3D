struct music_packet {
    char reg;    // 레지스터 포트로 전송
    char data;   // 데이터 포트로 전송
    int delay;   // 대기 시간
}