#include "stdafx.h"
#include "Draw.h"

void CDraw::Draw_Title()
{
	cout << "\n\n" << endl;
	cout << "\t#######                  #     #                                      #    #                                                  " << endl;
	cout << "\t#     # #    # ######    ##    # #  ####  #    # #####    # #    #    #   #    ##   #####    ##   ###### #    #   ##   #    # " << endl;
	cout << "\t#     # ##   # #         # #   # # #    # #    #   #      # ##   #    #  #    #  #  #    #  #  #      #  #    #  #  #  ##   # " << endl;
	cout << "\t#     # # #  # #####     #  #  # # #      ######   #      # # #  #    ###    #    # #    # #    #    #   ###### #    # # #  # " << endl;
	cout << "\t#     # #  # # #         #   # # # #  ### #    #   #      # #  # #    #  #   ###### #####  ######   #    #    # ###### #  # # " << endl;
	cout << "\t#     # #   ## #         #    ## # #    # #    #   #      # #   ##    #   #  #    # #   #  #    #  #     #    # #    # #   ## " << endl;
	cout << "\t####### #    # ######    #     # #  ####  #    #   #      # #    #    #    # #    # #    # #    # ###### #    # #    # #    # " << endl;

	cout << "\n\n" << endl;
	cout << "\t오! 제 초대장을 받으셨군요." << endl;
	cout << "\t파티에 오신 걸 환영합니다!\n" << endl;
	PlaySound(TEXT("Data/VO_INNKEEPER_INTRO_02.wav"), 0, SND_FILENAME | SND_ASYNC);
}

void CDraw::CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int CDraw::Control() {
	int Key(0);
	while (true) {
		// 화살표 키를 누르면 224와 방향에 따른 수가 입력 되므로 한번더 _getch()를 한다.
		Key = _getch();
		if (224 == Key) {
			Key = _getch();
			return Key;
		}
		else if (SPACE == Key)
			return Key;
	}
}

int CDraw::Draw_Arrow(int iX, int iY, int iMinY, int iMaxY) {
	gotoxy(iX, iY);
	cout << ">";
	while (true) {
		int Key = Control();

		switch (Key)
		{
		case UP:
			if (iMinY < iY) {
				gotoxy(iX, iY);
				cout << " ";
				--iY;
				gotoxy(iX, iY);
				cout << ">";
			}
			break;
		case DOWN:
			if (iMaxY > iY) {
				gotoxy(iX, iY);
				cout << " ";
				++iY;
				gotoxy(iX, iY);
				cout << ">";
			}
			break;
		case SPACE:
			return (iY - iMinY);
		default:
			break;
		}

	}
}


// 커서 위치 이동 함수
void CDraw::gotoxy(int x, int y) {
	COORD posXY = { (short)x, (short)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posXY);
}

