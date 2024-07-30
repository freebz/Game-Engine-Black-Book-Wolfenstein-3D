// 4.7.7.2 지연된 세로선 그리기

for (int x=0 ; x< 320 ; x++) {
  castRay();
  height = CalculateWallHeight();
  drawColumn(x, height);
}