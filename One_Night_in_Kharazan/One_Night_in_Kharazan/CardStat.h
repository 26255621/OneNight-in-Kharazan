#pragma once

#define ���� 0
#define �Ǿ� 1
#define ���� 2
#define ���������� 3
#define ���� 4
#define �ΰź� 5
#define ����� 6
#define ��ɰ� 7
#define �л�� 8


typedef struct Stat {
	char szName[16];
	int iCost;
	int iAttack;
	int iHp;
public:
	Stat() { memset(this, NULL, sizeof(Stat)); };
}Stat, *PStat;