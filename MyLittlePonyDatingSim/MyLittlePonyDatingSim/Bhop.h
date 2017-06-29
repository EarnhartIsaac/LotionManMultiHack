#ifndef _BHOP_H
#define _BHOP_H

#include "Memory.h"
#include "Offsets.h"

class Bhop
{
public:
	Bhop(Memory * memMgr);
	void Run();
	~Bhop();

private:
	Memory *MemMgr;
	DWORD ClientBaseAddr;
};

#endif