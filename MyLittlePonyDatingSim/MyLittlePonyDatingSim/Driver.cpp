#include <iostream>
#include "Memory.h" 
#include "Offsets.h"
#include "Glow.h"
#include "Trigger.h"
#include "Bhop.h"


//For those who are a little slow these are our global variables
Memory* HaxorTime;
Glow* Walls;
Trigger* TriggerBot;
Bhop* BunnyHop;
bool TriggerToggled = false;
bool WallToggled = false;
bool BhopToggled = false;


void Hack()
{
	bool running = true;
	while (running)
	{
		/*****************/
		/*KEY INPUT PHASE*/
		/*****************/

		if (GetAsyncKeyState(VK_F9))
		{
			running = false;
		}

		//Check for toggle on/off
		if (GetAsyncKeyState(VK_F6))
		{
			//Alright this is pretty clever double v but maybe it's just cause I'm not an experienced C++ programmer
			TriggerToggled = !TriggerToggled;
			if (TriggerToggled) std::cout << "Trigger On" << std::endl;
			else std::cout << "Trigger Off" << std::endl;
			Sleep(200);
		}

		if (GetAsyncKeyState(VK_F7))
		{
			WallToggled = !WallToggled;
			if (WallToggled) std::cout << "Walls On" << std::endl;
			else std::cout << "Walls Off" << std::endl;
			Sleep(200);
		}

		if (GetAsyncKeyState(VK_F8))
		{
			BhopToggled = !BhopToggled;
			if (BhopToggled) std::cout << "Bhop On" << std::endl;
			else std::cout << "Bhop Off" << std::endl;
			Sleep(200);
		}

		/**********************/
		/*HACK EXECUTION STAGE*/
		/**********************/

		if (TriggerToggled)
		{
			TriggerBot->Run();
		}

		if (WallToggled)
		{
			Walls->Run();
		}

		if (BhopToggled)
		{
			BunnyHop->Run();
		}
	}
}

void StartMenu()
{
	std::cout << "Welcome to my little pony dating simulator" << std::endl;
	std::cout << "\t<F6> Toggle Trigger Bot" << std::endl;
	std::cout << "\t<F7> Toggle Wall Hacks" << std::endl;
	std::cout << "\t<F8> Toggle Bhop" << std::endl;
}

int main()
{
	HaxorTime = new Memory(); //Build that puppy
	Walls = new Glow(HaxorTime);
	TriggerBot = new Trigger(HaxorTime);
	BunnyHop = new Bhop(HaxorTime);
	StartMenu();
	Hack();
}