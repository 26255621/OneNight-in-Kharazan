#include "stdafx.h"
#include "Cards.h"


CCards::CCards() : m_pStat(nullptr), m_pNext(nullptr)
{
}


CCards::~CCards()
{
	Release();
}

void CCards::Initialize()
{
	m_pStat = new Stat;
	Set_Stat();
}

void CCards::Update()
{
}

void CCards::Release()
{
	if (m_pStat) {
		delete m_pStat;
		m_pStat = nullptr;
	}
	if (m_pNext) {
		delete m_pNext;
		m_pNext = nullptr;
	}
}

void CCards::Set_Next_Card(CCards* _Next)
{
	m_pNext = _Next;
}

void CCards::Set_Stat()
{
	switch (rand() % 9)
	{
	case À§½À:
		strcpy_s(m_pStat->szName, "À§½À");
		m_pStat->iAttack = 1;
		m_pStat->iHp = 1;
		m_pStat->iCost = 0;
		break;
	case ¾Ç¾î:
		strcpy_s(m_pStat->szName, "¾Ç¾î");
		m_pStat->iAttack = 2;
		m_pStat->iHp = 3;
		m_pStat->iCost = 2;
		break;
	case ·¦ÅÍ:
		strcpy_s(m_pStat->szName, "·¦ÅÍ");
		m_pStat->iAttack = 3;
		m_pStat->iHp = 2;
		m_pStat->iCost = 2;
		break;
	case °«°«°«°«°«:
		strcpy_s(m_pStat->szName, "°«°«°«°«°«");
		m_pStat->iAttack = 5;
		m_pStat->iHp = 1;
		m_pStat->iCost = 3;
		break;
	case ´©´©:
		strcpy_s(m_pStat->szName, "´©´©");
		m_pStat->iAttack = 4;
		m_pStat->iHp = 5;
		m_pStat->iCost = 4;
		break;
	case ÅÎ°ÅºÏ:
		strcpy_s(m_pStat->szName, "ÅÎ°ÅºÏ");
		m_pStat->iAttack = 2;
		m_pStat->iHp = 7;
		m_pStat->iCost = 4;
		break;
	case ¿À¿ì°Å:
		strcpy_s(m_pStat->szName, "¿À¿ì°Å");
		m_pStat->iAttack = 6;
		m_pStat->iHp = 7;
		m_pStat->iCost = 6;
		break;
	case »ç³É°³:
		strcpy_s(m_pStat->szName, "»ç³É°³");
		m_pStat->iAttack = 9;
		m_pStat->iHp = 5;
		m_pStat->iCost = 7;
		break;
	case ÇÐ»çºÕ:
		strcpy_s(m_pStat->szName, "ÇÐ»çºÕ");
		m_pStat->iAttack = 7;
		m_pStat->iHp = 7;
		m_pStat->iCost = 7;
		break;
	default:
		break;
	}
}

PStat CCards::Get_Stat()
{
	return m_pStat;
}

CCards * CCards::Get_Next_Card()
{
	return m_pNext;
}
