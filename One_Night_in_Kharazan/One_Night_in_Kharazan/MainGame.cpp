#include "stdafx.h"
#include "MainGame.h"
#include "Player.h"
#include "Cards.h"

CMainGame::CMainGame()
{
	m_pUser = nullptr;
	m_pUser = nullptr;
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_pUser = new CPlayer;
	m_pUser->Initialize();

	m_p12Hour = new CPlayer;
	m_p12Hour->Initialize();
}

void CMainGame::Update()
{
	system(" mode  con lines=50   cols=150 ");
	m_Draw.Draw_Title();
	system("pause");
	PlaySound(TEXT("Data/Hearthstone-Main.wav"), 0, SND_FILENAME | SND_ASYNC);
	system("cls");
	Hand_Out();
	while (true) {
		if (0 >= m_p12Hour->Get_Player_Hp()) {
			system("cls");
			cout << "승리!" << endl;
		}
		else if (0 >= m_pUser->Get_Player_Hp()) {
			system("cls");
			cout << "게임 조까치 하네!" << endl;
		}
		if (4 == m_pUser->Do_Select())
			return;

	}
}

void CMainGame::Release()
{
	if (m_pUser) {
		delete m_pUser;
		m_pUser = nullptr;
	}
	if (m_p12Hour) {
		delete m_p12Hour;
		m_p12Hour = nullptr;
	}
}

void CMainGame::Hand_Out()
{
	for (int i = 0; i < 3; ++i) {
		m_pUser->Add_Card();
		m_p12Hour->Add_Card();
	}
}

