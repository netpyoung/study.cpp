calling convention

__cdecl https://docs.microsoft.com/en-us/cpp/cpp/cdecl?view=vs-2019
c declaration
__cdecl   caller가 stack을 정리
__stdcall callee가 stack을 정리

__stdcall https://docs.microsoft.com/en-us/cpp/cpp/stdcall?view=vs-2019

__declspec(dllimport)
__declspec(dllexport)

https://www.sysnet.pe.kr/2/0/11132

#ifdef CALLEE_EXPORT
#define CALLEE_API __declspec(dllexport)
#else
#define CALLEE_API __declspec(dllimport)
#endif

