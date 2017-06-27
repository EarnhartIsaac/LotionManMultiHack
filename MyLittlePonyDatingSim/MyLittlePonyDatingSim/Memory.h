#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <Windows.h>
#include <TlHelp32.h>

//NOTE:
//If your are getting compiler errors saying that CHAR* cannot be converted to wchar_t,
//go into your project properties and change your character set to unicode
//The reason for this is that TlHelp32.h will define our PROCESSENTRY32 as
//a PROCESSENTRY32W if our character set is 0, 
//changing szExeFile from an array of CHARs to an array of WCHARs

//WINAPI TlHelp32.h Documentation
//The link below brings you straight to a list of pages each explaining 
//the algorithms used in these methods. After reading it you should move over 
//to the tool help reference and learn exactly what the code is doing
//https://msdn.microsoft.com/en-us/library/windows/desktop/ms681926(v=vs.85).aspx

class Memory
{
private:
	DWORD dwPID;
	HANDLE hProcess;
public:

	//If you want to hack something other than csgo, you will want to add its necessary dlls
	//to the classes Modules and initialize them in your cumstructor
	MODULEENTRY32 ClientDLL;
	MODULEENTRY32 EngineDLL;
	DWORD ClientDLL_Base, ClientDLL_Size;
	DWORD EngineDLL_Base, EngineDLL_Size;

	bool AttachProcess(char* ProcessName);
	MODULEENTRY32 GetModule(char* ModuleName);
	
	/* R E A D P R O C E S S M E M O R Y
	*  Say hello to your new best friend ReadProcessMemory
	*  Just make sure he isnt detected by the anti cheat of your game
	*  before you implement him
	*  ReadProcessMemory magically takes the HANDLE and Address we have on our process
	*  and then uses it to find the value stored at that address. The value will
	*  be stored in an object(or primative) designated by c. You will probably want to
	*  ensure that the value you are reading is indeed the same size as c so that the value
	*  you retreive is actually its own identity and not a mutant value from multiple unrelated address
	*  or a fraction of the full piece of data you want
	*
	*  Here is the documentation for ReadProcessMemory which you will
	*  now read to understand what the hell is going on with this function
	*  https://msdn.microsoft.com/en-us/library/windows/desktop/ms680553(v=vs.85).aspx
	*/
	template<class c>
	c Read(DWORD dwAddress)
	{
		c val;
		ReadProcessMemory(hProcess, (LPVOID)dwAddress, &val, sizeof(c), NULL);
		return val;
	}

	/* W R I T E P R O C E S S M E M O R Y
	*  You will 100% want to make sure that c is the correct size for the address you are writing to.
	*  Definately stay away from using this until you know what you are doing
	*  While petty anti cheat programs like VAC aren't going to notice your handle on the program
	*  or that you are reading the memory, if you write something to the memory that is obviously not
	*  feasable in game then VAC is gonna have a fun time banning your ass
	*
	*  Another page to read if you really can't navigate webpages and didn't find it from the last link
	*  https://msdn.microsoft.com/en-us/library/windows/desktop/ms681674(v=vs.85).aspx
	*/
	template<class c>
	BOOL Write(DWORD dwAddress, c ValueToWrite)
	{
		return WriteProcessMemory(hProcess, (LPVOID)dwAddress, &ValueToWrite, sizeof(c), NULL);
	}

	DWORD GetProcID();
	HANDLE GetProcHandle();

	
	Memory();
	Memory(char* ProcessName);
	~Memory();
	
};



#endif

