#pragma once

#include "Memory.h"
#include "Offsets.h"

class Glow
{
public:
	Glow(Memory * memMgr);
	void Run();
	void Glow::SetGlow(int, float, float, float, float);
	~Glow();

private:
	Memory *MemMgr;
	DWORD ClientBaseAddr;
};

