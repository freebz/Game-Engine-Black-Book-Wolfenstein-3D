// 4.7.2 3D 프레임의 수명

void StatusDrawPic (int x, int y, int picnum)
{
  unsigned temp;

  temp = bufferofs;
  bufferofs = 0;

  bufferofs = PAGE1START+(200-STATUSLINES)*SCREENWIDTH;
  LatchDrawPic (x,y,picnum);
  bufferofs = PAGE2START+(200-STATUSLINES)*SCREENWIDTH;
  LatchDrawPic (x,y,picnum);
  bufferofs = PAGE3START+(200-STATUSLINES)*SCREENWIDTH;
  LatchDrawPic (x,y,picnum);

  bufferofs = temp;
}