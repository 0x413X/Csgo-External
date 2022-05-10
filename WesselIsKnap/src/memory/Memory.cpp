#include "../framework.h"
#include <TlHelp32.h>

Memory::Memory()
{

}
Memory::Memory(std::string processName)
{
	PROCESSENTRY32 entry = { };
	entry.dwSize = sizeof(::PROCESSENTRY32);

	const auto snapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	while (::Process32Next(snapShot, &entry))
	{
		if (!processName.compare(entry.szExeFile))
		{
			procId = entry.th32ProcessID;
			procHandle = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, procId);
			break;
		}
	}

	if (snapShot)
		::CloseHandle(snapShot);
}
Memory::~Memory()
{
	if (procHandle)
	{
		CloseHandle(procHandle);
	}
}

template <typename t>
t Memory::Read(DWORD address)
{
	t buffer;
	ReadProcessMemory(procHandle, address, &buffer, sizeof(buffer), NULL);
	return buffer;
}

template <typename t>
void Memory::Write(DWORD address, t value)
{
	WriteProcessMemory(procHandle, address, &value, sizeof(value), NULL);
}