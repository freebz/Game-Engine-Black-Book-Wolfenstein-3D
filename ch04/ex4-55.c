// 4.9 사운드 효과

// ///////////////////////////////////////////////
//
// MUSE Header for .SDM
// Created Thu Aug 27 07:12:39 1992
//
// ///////////////////////////////////////////////

#define STARTPCSOURDS      0
#define STARTADLIBSOUNDS  81
#define STARTDIGISOUNDS  162
#define STARTMUSIC       243

// 사운드 이름과 색인
typedef enum {
    HITWALLSND,       // 0
    MISSILEHITSND,    // 1
    [...]
    DEATHSCREAM1SND,  // 29
    GETMACHINESND,    // 30
    GETAMMOSND,       // 31
    SHOOTSND,         // 32
    HEALTH1SND,       // 33
    HEALTH2SND,       // 34
    BONUS1SND,        // 35
    BONUS2SND,        // 36
    BONUS3SND,        // 37
    /* */
    ANGELTIREDSND,    // 80
    LASTSOUND
} soundnames;

// 음악 이름과 색인
typedef enum {
    XFUNKIE_MUS,      // 0
    DUNGEON_MUS,      // 1
    XDEATH_MUS,       // 2
    [...]
    XTOWER2_MUS,      // 23
    LASTMUSIC
} musicnames;

}