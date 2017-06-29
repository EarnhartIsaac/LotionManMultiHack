#include <Windows.h>
#include <iostream>

#include "Bhop.h"

Bhop::Bhop(Memory * memMgr)
{
	// Set the memory manager to the programs memory manager
	MemMgr = memMgr;
	ClientBaseAddr = MemMgr->ClientDLL_Base;
}

void Bhop::Run()
{
	DWORD m_dwLocalPlayer = MemMgr->Read<DWORD>(MemMgr->ClientDLL_Base + dwLocalPlayer);
	BYTE fFlags = MemMgr->Read<BYTE>(m_dwLocalPlayer + m_fFlags);

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		
		if (fFlags & (1 << 0))
		{
			MemMgr->Write<int>(MemMgr->ClientDLL_Base + dwForceJump, 6);
			/*
			MemMgr->Write<int>(MemMgr->ClientDLL_Base + dwForceJump, 5);
			Sleep(20);
			MemMgr->Write<int>(MemMgr->ClientDLL_Base + dwForceJump, 4);
			*/
		}
	}
}

Bhop::~Bhop()
{

}