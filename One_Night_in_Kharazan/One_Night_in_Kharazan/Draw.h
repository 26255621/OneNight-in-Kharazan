#pragma once

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32

class CDraw
{
public:
	void Draw_Title() const;
	void CursorView() const;
	int Control() const;
	int Draw_Arrow(int iX, int iY, int iMinY = 0, int iMaxY = 0);
	void gotoxy(int x, int y) const;
};

