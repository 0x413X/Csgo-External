#include "framework.h"

menu Menu;

int main()
{
	Menu.Startup();

	while (true)
	{
		//input
		
		//run cheats

		//updatemenu
		Menu.UpdateConsole();
		Sleep(1);
	}

	std::cin.get();
}
