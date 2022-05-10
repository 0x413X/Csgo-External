#pragma once
class Memory
{
public:
	Memory();
	Memory(std::string processname);
	~Memory();

	template <typename t>
	t Read(DWORD address);

	template <typename t>
	void Write(DWORD address, t value);
private:
	HANDLE procHandle;
	int procId;
};


