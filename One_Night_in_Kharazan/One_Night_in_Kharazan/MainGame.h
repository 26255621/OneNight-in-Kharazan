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

	void Hand_Out();	// ī�� ó���� �����ֱ�

private:
	CDraw m_Draw;
	CPlayer* m_pUser;
	CPlayer* m_p12Hour;
};

