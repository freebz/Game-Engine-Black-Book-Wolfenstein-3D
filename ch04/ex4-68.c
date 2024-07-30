// 4.11 속도 높이는 기법

// 4.11.1 cos/sin 테이블 참조

#define ANGLES    360
fixed far sintable[ANGLES+ANGLES/4];
far *costable = sintable+(ANGLES/4);