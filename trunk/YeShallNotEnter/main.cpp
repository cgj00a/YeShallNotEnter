#include "YeShallNotEnter.h"

int __stdcall YeShallNotEnter::Load(IAshitaCore* mAshitaCore, DWORD ExtensionID)
{
		this->m_AshitaCore = mAshitaCore;
		this->m_ExtensionId = ExtensionID;

		return 1;
}

void __stdcall YeShallNotEnter::Unload()
{
}

ExtensionInterfaceData __stdcall YeShallNotEnter::GetExtensionData()
{
	return *ModuleData;
}

bool __stdcall YeShallNotEnter::HandleNewChatLine(short sMode, char* szText)
{
	char* substr = strstr(szText+1, "\x7F\x31");
	while (substr != NULL)
	{
		memset(substr, '\x20', 3);
		substr = strstr(substr, "\x7F\x31");
	}
	return false;
}

__declspec( dllexport ) void __stdcall CreateExtensionData(ExtensionInterfaceData* Data)
{
	ModuleData = Data;
	ModuleData->ExtensionVersion		=		1.01;
	ModuleData->InterfaceVersion		=		INTERFACEVERSION;
	ModuleData->RequiresValadation		=		false;
	ModuleData->AutoloadConfiguration	=		true;
	ModuleData->AutoloadLanguage		=		false;

	strncpy_s(ModuleData->Name,"YeShallNotEnter", 256);
	strncpy_s(ModuleData->Author,"bluekirby0", 256);
}

__declspec( dllexport ) IExtension* __stdcall CreateExtension(char* szText)
{
	return (IExtension*)new YeShallNotEnter();
}