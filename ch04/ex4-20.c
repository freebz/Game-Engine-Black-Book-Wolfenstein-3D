void DrawMainMenu(void)
{
  ClearMScreen();                    // 화면을 빨간색으로 바꾼다
  VWB_DrawPic(112,184,C_MOUSELBACKPIC ); // 아래 이미지
  DrawStripes(10);                     // 검정색 띠를 그린다
  VWB_DrawPic(84,0,C_OPTIONSPIC);        // 옵션 이미지
  DrawWindow(MENU_X-8,MENU_Y-3,MENU_W,MENU_M,BKGDCOLOR);
    [...]
  DrawMenu(&MainItems,&MainMenu[0]);
  VM_UpdateScreen();
}