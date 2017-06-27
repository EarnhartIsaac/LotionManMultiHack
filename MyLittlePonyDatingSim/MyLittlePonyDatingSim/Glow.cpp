#include "Glow.h"


#include <Windows.h>
#include <ctime>
#include <thread>

Glow::Glow(Memory * memMgr)
{
	// Initialize the Memory Manager
	MemMgr = memMgr;
	ClientBaseAddr = MemMgr->ClientDLL_Base;
}

void Glow::Run() {
	size_t pLocalPlayer = MemMgr->Read<size_t>(ClientBaseAddr + dwLocalPlayer);
			for (int i = 1; i <= 64; i++)
			{
				DWORD dwEntity = MemMgr->Read<DWORD>(ClientBaseAddr + dwEntityList + (i - 1) * 0x10);
				if (!dwEntity)
					continue;
				int iEntityTeam = MemMgr->Read<int>(dwEntity + m_iTeamNum);
				int iTargetHealth = MemMgr->Read<int>(dwEntity + m_iHealth);
				int iLocalPlayerTeam = MemMgr->Read<int>(pLocalPlayer + m_iTeamNum);

				if (iTargetHealth > 0)
				{
					//O_M_I_GLOW_IDX index of the glow manager offset pointer owned by the entity for its spectator glow
					int iGlowIndex = MemMgr->Read<int>(dwEntity + m_iGlowIndex);
					//Chose color based on entities team
					if (iEntityTeam == iLocalPlayerTeam)
						SetGlow(iGlowIndex, 0, 0, 1, 0.8);
					else 
						SetGlow(iGlowIndex, 1, 0, 0, 0.8);
				}
			}
		std::this_thread::sleep_for(std::chrono::milliseconds(25));

}

void inline Glow::SetGlow(int iEntityGlowIndex, float r, float g, float b, float a)
{
	//dwGlowObjectManager is a pointer to the location of the glow objects
	size_t ldwGlowObjectManager = MemMgr->Read<size_t>(ClientBaseAddr + dwGlowObjectManager);
	MemMgr->Write(ldwGlowObjectManager + ((iEntityGlowIndex * 0x38) + 0x4), r);
	MemMgr->Write(ldwGlowObjectManager + ((iEntityGlowIndex * 0x38) + 0x8), g);
	MemMgr->Write(ldwGlowObjectManager + ((iEntityGlowIndex * 0x38) + 0xC), b);
	MemMgr->Write(ldwGlowObjectManager + ((iEntityGlowIndex * 0x38) + 0x10), a);

	MemMgr->Write(ldwGlowObjectManager + ((iEntityGlowIndex * 0x38) + 0x24), true);
	MemMgr->Write(ldwGlowObjectManager + ((iEntityGlowIndex * 0x38) + 0x25), false);
}

Glow::~Glow()
{
}
