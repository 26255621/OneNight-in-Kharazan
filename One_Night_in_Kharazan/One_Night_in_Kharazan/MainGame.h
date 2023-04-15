#pragma once
#include "Draw.h"

class CPlayer;

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void Initialize();
	void Update();
	void Release();

	void Hand_Out();	// 카드 처음에 나눠주기

private:
	CDraw m_Draw;
	CPlayer* m_pUser;
	CPlayer* m_p12Hour;
};

