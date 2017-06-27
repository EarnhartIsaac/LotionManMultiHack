#include "Memory.h"

/*
* This function finds the process ID (dwPID) for a string literal of a process name and
* then opens a handle for that given process (hProcess)
*/
bool Memory::AttachProcess(char* ProcessName)
{
	HANDLE hPID = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);	//Handle to all processes running on the system
	PROCESSENTRY32 procEntry;											//Temp variable for iterating processes
	procEntry.dwSize = sizeof(procEntry);								//PROCESSENTRY32 number of bytes must be initialized manually

	/*
	* MultiByteToWideChar Documentation
	* https://msdn.microsoft.com/en-us/library/windows/desktop/dd319072(v=vs.85).aspx
	* wcscmp Documentation
	* https://msdn.microsoft.com/en-us/library/e0z9k731.aspx
	*/

	/* EXPLAINATION FOR THE MULTIBYTETOWIDECHAR
	*  In C++ Unicode characters need to be stored as wide chars (wchar_t)
	*  which are 2 byte characters rather than ascii's 1 byte.
	*  having a parameter of type char* lets us directly pass string arguments
	*  of what exe we want instead of creating a WCHAR* or wchar_t*
	*  and initializing it to L"<ASSHOLE RETARD FUCKFACE or any other string you can think of>"
	*  MultiByteToWideChar simply takes our string and turns it into a wchar_t* for us
	*/

	do
		if (!strcmp(procEntry.szExeFile, ProcessName))					//Checks to see if the string comparison between our desired exe and the current exe 
			//is zero using wcscmp (string are equal)
		{
			this->dwPID = procEntry.th32ProcessID;									//Our Process ID is set to the ID of the current Process 
			this->hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, this->dwPID);	//Setting our handle to our exe using its known Process ID
			CloseHandle(hPID);														//Closing our handle to our process list
			return true;
		}
	while (Process32Next(hPID, &procEntry));	//Iterate through processes in hPID using procEntry

	CloseHandle(hPID);	//Close handle if the process was not found
	return false;
}

/*
* Very Similar to the AttachProcess function only we iterate through the modules of out process instead
* of iterating through the processes in our memory snapshot
*/
MODULEENTRY32 Memory::GetModule(char* ModuleName)
{
	HANDLE hModule = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwPID);		//Create a snapshot of our process using its process ID
	MODULEENTRY32 mEntry;														//Temp variable to store Modules during iteration
	mEntry.dwSize = sizeof(mEntry);												//Initialize the size of mEntry manually

	//I'm giving up the hyper in depth documentation here
	//If you can't get it on your own you are shit out of luck and brains too

	do
		if (!strcmp(mEntry.szModule, ModuleName))
		{
			CloseHandle(hModule);
			return mEntry;						//When we find the module return its entry
		}
	while (Module32Next(hModule, &mEntry));

	CloseHandle(hModule);						//In case we do not find the given module
	mEntry.modBaseAddr = 0x0;
	return mEntry;
}

//Congrats you've run through the necessary process of creating handles on your victim


//Setters and Getters
//If you don't know what these are you should go read about good programming practices
//While understanding how things work in C++ is one thing, how people actually program with it
//is another and it's very important if you want to actually do something with programming
//outside of your basement that you learn to write readable and convention following code
DWORD Memory::GetProcID() { return this->dwPID; }
HANDLE Memory::GetProcHandle(){ return this->hProcess; }

// CUMSTRUCTOR
Memory::Memory()
{
	this->hProcess = NULL;
	this->dwPID = NULL;
	try{
		if (!AttachProcess("csgo.exe")) throw 1;		//Get the scoop on csgo.exe

		this->ClientDLL = GetModule("client.dll");		//Get the scoop on csgo.exe's client.dll
		this->ClientDLL_Base = (DWORD)this->ClientDLL.modBaseAddr;		//This gives us the base address of these dlls in memory
		if (this->ClientDLL_Base == 0x0) throw 2;						//Checks to see that these modules actually exist
		this->ClientDLL_Size = this->ClientDLL.dwSize;					//Gives us the size of the memory space allocated by these dlls

		this->EngineDLL = GetModule("engine.dll");		//Get the scoop on csgo.exe's engine.dll
		this->EngineDLL_Base = (DWORD)this->EngineDLL.modBaseAddr;
		if (this->EngineDLL_Base == 0x0) throw 3;
		this->EngineDLL_Size = this->EngineDLL.dwSize;
	}
	catch (int iEx) {
		switch (iEx)
		{
		case 1: MessageBoxA(NULL, "CS:GO must be running", "ERROR", MB_ICONSTOP | MB_OK); exit(0); break;
		case 2: MessageBoxA(NULL, "Couldn't find Client.dll", "ERROR", MB_ICONSTOP | MB_OK); exit(0); break;
		case 3: MessageBoxA(NULL, "Couldn't find Engine.dll", "ERROR", MB_ICONSTOP | MB_OK); exit(0); break;
		default: throw;
		}
	}
	catch (...) {
		MessageBoxA(NULL, "Unhandled exception thrown", "ERROR", MB_ICONSTOP | MB_OK);
		exit(0);
	}
}

//DECUMSTRUCTOR
//Always make one of these puppies
Memory::~Memory()
{
	CloseHandle(this->hProcess);
}

//Congrats now you understand how almost every programmer interfaces with memory when programming their hacks
//Feel proud of yourself