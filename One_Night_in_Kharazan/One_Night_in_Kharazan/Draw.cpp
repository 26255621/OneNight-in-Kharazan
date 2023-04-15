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
	cout << "\t��! �� �ʴ����� �����̱���." << endl;
	cout << "\t��Ƽ�� ���� �� ȯ���մϴ�!\n" << endl;
	PlaySound(TEXT("Data/VO_INNKEEPER_INTRO_02.wav"), 0, SND_FILENAME | SND_ASYNC);
}

void CDraw::CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
	cursorInfo.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int CDraw::Control() {
	int Key(0);
	while (true) {
		// ȭ��ǥ Ű�� ������ 224�� ���⿡ ���� ���� �Է� �ǹǷ� �ѹ��� _getch()�� �Ѵ�.
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


// Ŀ�� ��ġ �̵� �Լ�
void CDraw::gotoxy(int x, int y) {
	COORD posXY = { (short)x, (short)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posXY);
}

