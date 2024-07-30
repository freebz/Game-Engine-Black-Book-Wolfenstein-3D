// 4.10.3 조이스틱

word INL_GetJoyButtons(word joy){
  register  word  result;

  result = inportb(0x201); // 모든 조이스틱 버튼을 얻는다
  result >>= joy? 6 : 4;   // 조이스틱 A와 B에 맞춰 비트를 시프트한다
  result &= 3;             // 불필요한 비트를 가린다
  result ^= 3;
  return(result);
}