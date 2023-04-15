// One_Night_in_Kharazan.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MainGame.h"

#ifndef DBG_NEW 

#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif


void main()
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif // _DEBUG

	srand((unsigned int)time(NULL));
	CMainGame MainGame;
	MainGame.Initialize();
	MainGame.Update();
	MainGame.Release();
}

