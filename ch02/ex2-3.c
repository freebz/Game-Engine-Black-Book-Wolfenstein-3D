char far *VGA = (byte far*)0xA00000000L;

void ClearScreen (void){
    asm mov a, 0x13
    asm int 0x10
    for (int i = 0; i < 320*200; i++) {
        VGA[i] = 0x00;
    }
}