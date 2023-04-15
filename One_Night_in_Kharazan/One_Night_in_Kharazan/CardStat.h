#pragma once

#define À§½À 0
#define ¾Ç¾î 1
#define ·¦ÅÍ 2
#define °«°«°«°«°« 3
#define ´©´© 4
#define ÅÎ°ÅºÏ 5
#define ¿À¿ì°Å 6
#define »ç³É°³ 7
#define ÇÐ»çºÕ 8


typedef struct Stat {
	char szName[16];
	int iCost;
	int iAttack;
	int iHp;
public:
	Stat() { memset(this, NULL, sizeof(Stat)); };
}Stat, *PStat;