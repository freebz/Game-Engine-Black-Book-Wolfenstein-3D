int gameOn = 1;
int simulationTime = 0;

while (gameOn){
  int realTime = Gettime();

  while (simulationTime < realTime){
         simulationTime += 28; // 타임슬라이스는 항상 28ms다
         UpdateWorld(28);
  }

  RenderWorld();
}