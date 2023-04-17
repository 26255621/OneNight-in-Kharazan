#pragma once
#include "CardStat.h"

class CCards
{
public:
	CCards();
	~CCards();

public:
	void Initialize();
	void Update();
	void Release();


public:
	void Set_Can_Attack(bool _bCan);
	bool Get_Can_Attack();
	void Set_Next_Card(CCards* _Next);
	void Set_Stat();
	PStat Get_Stat();
	CCards* Get_Next_Card();

private:

	bool bCan_Attack;
	PStat m_pStat;
	CCards* m_pNext;
};

