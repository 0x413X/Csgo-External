#include "../framework.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void menu::Startup()
{
	SetConsoleTitle("Wessel Is Knap - Loading");
	system("cls");
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << " _______  _______  _______ _________ _       __________________ _______  " << std::endl;
	Sleep(100);
	std::cout << "(  ____ \\(  ___  )(  ____ )\\__   __/( (    /|\\__   __/\\__   __/(  ____ \\ " << std::endl;
	Sleep(100);
	std::cout << "| (    \\/| (   ) || (    )|   ) (   |  \\  ( |   ) (      ) (   | (    \\/ " << std::endl;
	Sleep(100);
	std::cout << "| (__    | |   | || (____)|   | |   |   \\ | |   | |      | |   | (__     " << std::endl;
	Sleep(100);
	std::cout << "|  __)   | |   | ||     __)   | |   | (\\ \\) |   | |      | |   |  __)    " << std::endl;
	Sleep(100);
	std::cout << "| (      | |   | || (\\ (      | |   | | \\   |   | |      | |   | (       " << std::endl;
	Sleep(100);
	std::cout << "| )      | (___) || ) \\ \\__   | |   | )  \\  |___) (___   | |   | (____/\\ " << std::endl;
	Sleep(100);
	std::cout << "|/       (_______)|/   \\__/   )_(   |/    )_)\\_______/   )_(   (_______/ " << std::endl;
	Sleep(100);
	std::cout << "_________________________________________________________________________" << std::endl;
	Sleep(500);

	float progress = 0.0;
	int barwidth = 50;
	int pos;
	bool finished = false;
	while (!finished)
	{
		pos = barwidth * progress;

		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "[";
		for (int i = 0; i < barwidth; ++i) {
			if (i < pos) std::cout << "=";
			else if (i == pos) std::cout << ">";
			else std::cout << " ";
		}

		std::cout << "] " << int(progress * 100.0) << " %\r";
		std::cout.flush();

		progress += static_cast <float> (rand()) / static_cast <float> (RAND_MAX * 4);
		//clamping progress to 1
		if (progress > 1.0) {
			progress = 1.0;
			finished = true;
			SetConsoleTextAttribute(hConsole, 10);
			std::cout << "[";
			for (int i = 0; i < barwidth; i++)
			{
				if (i < pos) std::cout << "=";
				else if (i == pos) std::cout << ">";
				else std::cout << " ";
			}
			std::cout << "] SUCCESS!\r";
			std::cout.flush();
		}

		Sleep(250);
	}
	std::cout << std::endl; 
	Sleep(1000);
	UpdateConsole();
}

void menu::UpdateConsole()
{
	SetConsoleTitle("Fortniting");
	system("cls");
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << " _______  _______  _______ _________ _       __________________ _______  " << std::endl;
	std::cout << "(  ____ \\(  ___  )(  ____ )\\__   __/( (    /|\\__   __/\\__   __/(  ____ \\ " << std::endl;
	std::cout << "| (    \\/| (   ) || (    )|   ) (   |  \\  ( |   ) (      ) (   | (    \\/ " << std::endl;
	std::cout << "| (__    | |   | || (____)|   | |   |   \\ | |   | |      | |   | (__     " << std::endl;
	std::cout << "|  __)   | |   | ||     __)   | |   | (\\ \\) |   | |      | |   |  __)    " << std::endl;
	std::cout << "| (      | |   | || (\\ (      | |   | | \\   |   | |      | |   | (       " << std::endl;
	std::cout << "| )      | (___) || ) \\ \\__   | |   | )  \\  |___) (___   | |   | (____/\\ " << std::endl;
	std::cout << "|/       (_______)|/   \\__/   )_(   |/    )_)\\_______/   )_(   (_______/ " << std::endl;
	std::cout << "_________________________________________________________________________" << std::endl;

	SetConsoleTextAttribute(hConsole, 9);
	std::cout << "\nGLOW ESP - [WIP]" << std::endl;
	std::cout << "AIMBOT     - [WIP]" << std::endl;
	std::cout << "TRIGGERBOT - [WIP]" << std::endl;
}


