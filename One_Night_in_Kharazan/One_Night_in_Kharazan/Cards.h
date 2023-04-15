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

	void Set_Next_Card(CCards* _Next);

	void Set_Stat();
	PStat Get_Stat();
	CCards* Get_Next_Card();

private:
	PStat m_pStat;
	CCards* m_pNext;
};

