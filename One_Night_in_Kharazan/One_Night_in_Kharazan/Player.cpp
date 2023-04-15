#include "stdafx.h"
#include "Player.h"
#include "Cards.h"


CPlayer::CPlayer() : iPlayer_Hp(30), iHave_Cost(0), iPlayer_Cost(0), iHand_Count(0), iField_Count(0)
{
	m_pHand_Head = nullptr;
	m_pField_Head = nullptr;
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_pHand_Head = new CCards;
	m_pField_Head = new CCards;
}

void CPlayer::Update()
{
}

void CPlayer::Release()
{
	if (m_pHand_Head) {
		delete m_pHand_Head;
		m_pHand_Head = nullptr;
	}
	if (m_pField_Head) {
		delete m_pField_Head;
		m_pField_Head = nullptr;
	}
}



void CPlayer::Player_Damage(int _iDamage)
{
	iPlayer_Hp -= _iDamage;
}

void CPlayer::Add_Card()
{
	if (10 <= iHand_Count) {
		cout << "ī�尡 �ʹ� ����!" << endl;
		system("pause");
		return;
	}
	CCards* Card = new CCards;
	Card->Initialize();
	Card->Set_Next_Card(m_pHand_Head->Get_Next_Card());
	m_pHand_Head->Set_Next_Card(Card);
	++iHand_Count;
}

void CPlayer::Show_Hand_Card()
{
	int iCount(0);
	CCards* Cursor(nullptr);
	Cursor = m_pHand_Head->Get_Next_Card();
	if (Cursor)
		cout << "�տ� �ִ� ī�� (���� ����: " << iHave_Cost << " / " << iPlayer_Cost << ')' << endl;
	while (Cursor) {
		++iCount;
		cout << "=================================================" << endl;
		cout << iCount << " �� ī�� �̸�: " << setw(5) << Cursor->Get_Stat()->szName << endl;
		cout << "��: " << Cursor->Get_Stat()->iAttack << "\tü: " << Cursor->Get_Stat()->iHp << "\t�ڽ�Ʈ: " << Cursor->Get_Stat()->iCost << '\n' << endl;
		Cursor = Cursor->Get_Next_Card();
	}
	cout << endl;
}

void CPlayer::Show_Field_Card()
{
	int iCount(0);
	CCards* Cursor(nullptr);
	Cursor = m_pField_Head->Get_Next_Card();
	if (Cursor)
		cout << "���忡 ���� ī��" << endl;
	while (Cursor) {
		++iCount;
		cout << "-------------------------------------------------" << endl;
		cout << iCount << " �� ī�� �̸�: " << setw(5) << Cursor->Get_Stat()->szName << endl;
		cout << "��: " << Cursor->Get_Stat()->iAttack << "\tü: " << Cursor->Get_Stat()->iHp << "\t�ڽ�Ʈ: " << Cursor->Get_Stat()->iCost << '\n' << endl;
		Cursor = Cursor->Get_Next_Card();
	}
	cout << endl;
}

int CPlayer::Do_Select(bool bCom)
{
	int iSelect(0);
	if (10 != iPlayer_Cost) {
		++iPlayer_Cost;
	}
	iHave_Cost = iPlayer_Cost;
	while (true) {
		system("cls");
		Show_Field_Card();
		Show_Hand_Card();
		cout << "������ �Ͻðڽ��ϱ�?" << endl;
		cout << "1. ī�� ���� 2. ���忡 ���� ī�� ����ϱ�(�̿ϼ�) 3. �� ���� 4. ���� ����" << endl;
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			Put_Card();
			break;
		case 2:
			break;
		case 3:
			Add_Card();
			return iSelect;
		case 4:
			return iSelect;
		default:
			break;
		}
	}
}

CCards* CPlayer::Search_Card(CCards* _Head, int _iSelect)
{
	CCards* Cursor(nullptr);
	Cursor = _Head;
	for (int i = 0; i < _iSelect; ++i) {
		if (!(Cursor->Get_Next_Card()))
			return Cursor;
		Cursor = Cursor->Get_Next_Card();
	}
	return Cursor;
}

void CPlayer::Put_Card(bool bCom)
{
	CCards* Pre_Cursor(nullptr);
	CCards* Cursor(nullptr);
	int iSelect(0);
	while (true) {
		system("cls");
		Show_Field_Card();
		Show_Hand_Card();
		cout << "�� �� ī�带 �����ðڽ��ϱ�? (���ư���: 0)" << endl;
		cin >> iSelect;
		if (!iSelect)
			return;
		Pre_Cursor = Search_Card(m_pHand_Head, --iSelect);
		Cursor = Pre_Cursor->Get_Next_Card();
		if (!Cursor || 0 > iSelect) {
			cout << "��! �׷� ī�� ���ܴ�!" << endl;
			system("pause");
			continue;
		}
		if (iHave_Cost < Cursor->Get_Stat()->iCost) {
			cout << iHave_Cost - Cursor->Get_Stat()->iCost << "�� �Ȱ����մϴ�" << endl;
			system("pause");
			continue;
		}

		if (7 <= iField_Count) {
			cout << "�� ������ ���� á��" << endl;
			system("pause");
			return;
		}

		Pre_Cursor->Set_Next_Card(Cursor->Get_Next_Card());
		Cursor->Set_Next_Card(m_pField_Head->Get_Next_Card());
		m_pField_Head->Set_Next_Card(Cursor);

		iHave_Cost -= Cursor->Get_Stat()->iCost;
		--iHand_Count;
		++iField_Count;
	}
}

int CPlayer::Get_Player_Hp()
{
	return iPlayer_Hp;
}

int CPlayer::Get_Player_Cost()
{
	return iPlayer_Cost;
}

CCards* CPlayer::Get_Hand_Head()
{
	return m_pHand_Head;
}

CCards* CPlayer::Get_Field_Head()
{
	return m_pField_Head;
}
