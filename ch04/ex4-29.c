// 4.7.5.5 광선 투사: DDA 알고리즘

void AsmRefresh() {

    for (int i=0; i < pixx; i++) {
        short angle=midangle+pixelangle[pixx];
        // 각도에 기반해 xstep과 ystep을 설정
        do {
            if (needed)
                goto testhorizontal;

testvertical:
            move_vertically()
            if (hitdoor)
                HitVertDoor();
            if (hitwall)
                HitVertWall();
        } while (1);

        continue;

        do {
            if (needed)
                goto testvertical ;

testhorizontal :
            move_horizontaly()
            if (hitdoor)
                HitHorizDoor();
            if (hitwall)
                HitHorizWall();

        } while (1);
    }
}