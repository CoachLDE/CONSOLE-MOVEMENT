#include <Windows.h>	//Header for drawing
#include <iostream>		//Header for Input/Output
#include <chrono>		//Header for Time
#include <thread>
#include <string>

using namespace std;

BOOL SetCursorPosition(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;

	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

bool isVirtualKeyPressed(int virtKey)
{
	return GetAsyncKeyState(virtKey) & 0x8000;
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

int main()
{
	int moveX = 0;
	int moveY = 0;

	ShowConsoleCursor(false);


	while (true)		
	{

		if (isVirtualKeyPressed(VK_LEFT))
			--moveX;
		else if (isVirtualKeyPressed(VK_RIGHT))
			++moveX;
		else if (isVirtualKeyPressed(VK_UP))
			--moveY;
		else if (isVirtualKeyPressed(VK_DOWN))
			++moveY;
		else if (isVirtualKeyPressed(VK_ESCAPE))
			break;

		std::this_thread::sleep_for(std::chrono::milliseconds(5));

		LockWindowUpdate(GetConsoleWindow());
		system("cls");

		SetCursorPosition(10 + moveX, 10 + moveY);
		cout << "A";
		LockWindowUpdate(NULL);
	}

	

	return 0;
}