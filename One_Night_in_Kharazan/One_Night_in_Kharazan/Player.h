#pragma once
class CCards;

class CPlayer
{
public:
	CPlayer();
	~CPlayer();

public:
	void Initialize();
	void Update();
	void Release();

	void Player_Damage(int _iDamage);
	void Add_Card();
	void Show_Hand_Card();
	void Show_Field_Card();
	int Do_Select(bool bCom = false);
	CCards* Search_Card(CCards* _Head, int _iSelect);
	void Put_Card(bool bCom = false);

public:
	int Get_Player_Hp();
	int Get_Player_Cost();
	CCards* Get_Hand_Head();
	CCards* Get_Field_Head();
private:
	int iPlayer_Hp;
	int iPlayer_Cost;
	int iHave_Cost;
	int iHand_Count;
	int iField_Count;
	CCards* m_pHand_Head;
	CCards* m_pField_Head;
};

