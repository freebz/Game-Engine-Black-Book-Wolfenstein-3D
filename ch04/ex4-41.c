#define MAXVISIBLE  50

typedef struct {
  int  viewx,viewheight,shapenum;
} visobj_t;

visobj_t  vislist[MAXVISIBLE],*visptr,*visstep,*farthest;

void DrawScaleds (void) {
  int numvisable=0;
  visptr = &vislist[0];

  // spotvis []을 사용해 객체를 visptr에 추가한다. numvisable을 하나 증가시킨다

  // 먼 곳에서 시작해 가까운 곳으로 오면서 그린다
  for (i = 0; i<numvisable; i++){
    least = 32000;
    for (visstep=&vislist[0] ; visstep<visptr ; visstep++){
      height = visstep->viewheight;
      if (height < least){
        least = height;
        farthest = visstep;
      }
    }
    ScaleShape(farthest->x,farthest->id,farthest->height);
    farthest->viewheight = 32000;
  }
  
}