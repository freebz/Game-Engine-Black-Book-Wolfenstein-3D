// 4.4.1 메모리 관리자(MM)

typedef struct mmblockstruct
{
  unsigned  start, length;
  unsigned  attributes;
  memptr    *useptr;
  struct mmblockstruct far *next;
} mmblocktype;