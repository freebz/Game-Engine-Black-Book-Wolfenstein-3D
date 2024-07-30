// 4.7.1 프레임의 수명

int lastTime = Timer_Gettime();

while (1){
  int currentTime = Timer_Gettime();
  int timeSlice = currentTime - lastTime;

  UpdateWorld(timeSlice);
  RenderWorld();

  lastTime = currentTime;
}