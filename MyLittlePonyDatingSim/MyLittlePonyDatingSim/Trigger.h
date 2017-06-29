#ifndef _TRIGGER_H
#define _TRIGGER_H

#include "Memory.h"
#include "Offsets.h"

class Trigger
{
public:
	Trigger(Memory * memMgr);
	Trigger(Memory * memMgr, int delay, int randomFactor);
	void Run();
	void SetReaction(int);
	void SetRandomFactor(int);
	~Trigger();

private:
	const int DEFAULT_RANDOM_FACTOR = 10;
	const int DEFAULT_DELAY = 50;

	Memory *MemMgr;
	DWORD ClientBaseAddr;
	int RandomFactor;
	int Delay;

	int FindDelay();
};

#endif