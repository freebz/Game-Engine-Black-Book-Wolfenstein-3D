// 4.7.10 인공지능

typedef struct  statestruct
{
    boolean   rotate;
    int       shapenum;     // 화면에 렌더링할 스프라이트
    int       tictime;      // 이 상태에 머무는 기간
    void   (*think) (),(*action) ();
    struct   statestruct   *next;
} statetype;