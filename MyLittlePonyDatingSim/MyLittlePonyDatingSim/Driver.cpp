#include <iostream>
#include "Memory.h" 
#include "Offsets.h"
#include "Glow.h"


//For those who are a little slow these are our global variables
Memory* HaxorTime;
Glow* Walls;
bool TriggerToggled = false;
bool WallToggled = false;


void Hack()
{
	bool running = true;
	while (running)
	{
		if (GetAsyncKeyState(VK_F5))
		{
			running = false;
		}

		//Check for toggle on/off
		if (GetAsyncKeyState(VK_F3))
		{
			//Alright this is pretty clever double v but maybe it's just cause I'm not an experienced C++ programmer
			TriggerToggled = !TriggerToggled;
			if (TriggerToggled) std::cout << "Trigger Inbound" << std::endl;
			else std::cout << "Trigger has landed" << std::endl;
			Sleep(200);
		}

		if (GetAsyncKeyState(VK_F4))
		{
			WallToggled = !WallToggled;
			if (WallToggled) std::cout << "Walls Inbound" << std::endl;
			else std::cout << "Walls has landed" << std::endl;
			Sleep(200);
		}

		if (TriggerToggled)
		{
			//Get dat player info
			DWORD LocalPlayer_Base = HaxorTime->Read<DWORD>(HaxorTime->ClientDLL_Base + dwLocalPlayer );		//We use our offset knowledge to find the value at our offset address
			int LocalPlayer_inCross = HaxorTime->Read<int>(LocalPlayer_Base + m_iCrosshairId );					//We use our offset knowledge to find the value of our crosshair
			int LocalPlayer_Team = HaxorTime->Read<int>(LocalPlayer_Base + m_iTeamNum );							//We use our offset knowledge to find what team we on

			//Retrieve the EntityBase, using dwEntityList
			//When local player is given to us it falls between 1 and 10
			//In memory all player entities are stored in a list (m_dwEntityList) the first being at the start of this offset
			//in other words player 1 is at m_dwEntityList, player 2 is at m_dwEntityList + 0x10, etc.
			DWORD Trigger_EntityBase = HaxorTime->Read<DWORD>(HaxorTime->ClientDLL_Base + dwEntityList + ((LocalPlayer_inCross - 1) * 0x10));
			int Trigger_EntityTeam = HaxorTime->Read<int>(Trigger_EntityBase + m_iTeamNum);

			//bDormant is a boolean value, the offset is 0xE9
			bool Trigger_EntityHealth = HaxorTime->Read<bool>(Trigger_EntityBase + m_iHealth);

			//If the other player exists, is on the other team, and aint dead, shoot em
			if ((LocalPlayer_inCross > 0 && LocalPlayer_inCross <= 64) && (Trigger_EntityBase != NULL) && (Trigger_EntityTeam != LocalPlayer_Team) && (Trigger_EntityHealth > 0))
			{
				//Shoot here
				//External way, you can customize the delays
				Sleep(10); //Delay before shooting
				mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, NULL, NULL);
				Sleep(10); //Delay between shots
				mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, NULL, NULL);
				Sleep(10); //Delay after shooting
			}
		}

		if (WallToggled)
		{
			Walls->Run();
		}
	}
}



int main()
{
	HaxorTime = new Memory(); //Build that puppy
	Walls = new Glow(HaxorTime);
	std::cout << "Im Camming" << std::endl;
	Hack();
}