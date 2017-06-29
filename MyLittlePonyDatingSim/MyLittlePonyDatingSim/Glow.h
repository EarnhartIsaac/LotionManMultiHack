#ifndef _GLOW_H
#define _GLOW_H

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

#endif

