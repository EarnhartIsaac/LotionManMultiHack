#include "Trigger.h"
#include <stdlib.h>

Trigger::Trigger(Memory * memMgr)
{
	// Set the memory manager to the programs memory manager
	MemMgr = memMgr;
	ClientBaseAddr = MemMgr->ClientDLL_Base;
}

//Override to change the delay algorithm
int Trigger::FindDelay()
{
	return (rand() / RAND_MAX) /*between 0 and 1*/
		* RandomFactor
		+ Delay;
}

void Trigger::Run()
{
	//Get dat player info
	DWORD LocalPlayer_Base = MemMgr->Read<DWORD>(MemMgr->ClientDLL_Base + dwLocalPlayer);		//We use our offset knowledge to find the value at our offset address
	int LocalPlayer_inCross = MemMgr->Read<int>(LocalPlayer_Base + m_iCrosshairId);					//We use our offset knowledge to find the value of our crosshair
	int LocalPlayer_Team = MemMgr->Read<int>(LocalPlayer_Base + m_iTeamNum);							//We use our offset knowledge to find what team we on

	//Retrieve the EntityBase, using dwEntityList
	//When local player is given to us it falls between 1 and 10
	//In memory all player entities are stored in a list (m_dwEntityList) the first being at the start of this offset
	//in other words player 1 is at m_dwEntityList, player 2 is at m_dwEntityList + 0x10, etc.
	DWORD Trigger_EntityBase = MemMgr->Read<DWORD>(MemMgr->ClientDLL_Base + dwEntityList + ((LocalPlayer_inCross - 1) * 0x10));
	int Trigger_EntityTeam = MemMgr->Read<int>(Trigger_EntityBase + m_iTeamNum);

	int Trigger_EntityHealth = MemMgr->Read<bool>(Trigger_EntityBase + m_iHealth);

	//If the other player exists, is on the other team, and aint dead, shoot em
	if ((LocalPlayer_inCross > 0 && LocalPlayer_inCross <= 64) && (Trigger_EntityBase != NULL) && (Trigger_EntityTeam != LocalPlayer_Team) && (Trigger_EntityHealth > 0))
	{
		//Shoot here
		//External way, you can customize the delays

		Sleep(FindDelay()); //Delay before shooting
		mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, NULL, NULL);
		Sleep(10); //Delay between shots
		mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, NULL, NULL);
		Sleep(10); //Delay after shooting
	}
}

void Trigger::SetReaction(int delay)
{
	Delay = delay;
}

void Trigger::SetRandomFactor(int factor)
{
	RandomFactor = factor;
}

Trigger::~Trigger()
{

}