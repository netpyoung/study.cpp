https://github.com/kerryjiang/SuperSocket/blob/46014a876cfd94731f89412e6f2fb6be413ca5c8/src/SuperSocket.WebSocket/FramePartReader/PayloadDataReader.cs
https://github.com/jacking75/SuperSocketLite/blob/master/SocketEngine/AsyncSocket/SocketAsyncEventArgsProxy.cs

[e-book] Boost.Asio를 이용한 네트워크 프로그래밍(한빛미디어)
[e-book] Boost.Asio C++ Network Programming Cookbook(Packt)

리틀엔디안 인텔x86/x64 애플 ios
빅엔디안  IBM PowerPC, Xbox360, Playstation3

https://github.com/galaxywiz/RoseServer


``` cpp
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "Winmm.lib")
#pragma comment(lib, "mswsock.lib")

#include <W2tcpip.h>
#include <winsock2.h>
#include <mswsock.h>
#include <Mmsystem.h>
```

CONTEXT_SWITCH Sleep(1); / ::SwitchToThread();

// mersenne twister random
uint64_t rand(int32_t max)
{
	std::mt19937 mt(static_cast<uint32_t>(time(nullptr)) + static_cast<uint32_t>(std::this_thread::get_id().hash()));
	std::uniform_int_distribution<uint64_t> distribution(0, UINT64_MAX);
	auto generator = bind(distribution, engine);
	return static_cast<uint64_t>(generator() % max);
}



malloc 동작 - http://egloos.zum.com/minjang/v/1232908


데드락 감지를 위해 락클래스를 래핑하는것도 좋다. vector tracer를 넣어서.

88 Logger
94
ASSERT(condition, comment);
condition, comment, __FILE__, __LINE__

98p minidump

http://www.softstack.com/freesmtp.html
telnet 127.0.0.1 25

104 threadjobqueue
106 HashSet<T>
107 Dictionary<TKey,TValue>
111, 112 VisualLeakDetector - https://kinddragon.github.io/vld/
vld.ini
114 : ref: https://docs.microsoft.com/en-us/windows/win32/memory/low-fragmentation-heap

#include <vld.h> // VisualLeakDetector

# malloc
|douglea malloc|
|dlmalloc|
|hoard|
|JEMalloc|
|TCMalloc   - google| Thread Caching memory allocation
|TBB malloc - intel|

Windows LFH
linux tcmalloc

# parser
- CSV
- XML
- JSON
- YAML

- csv-parser-cplusplus




125p 스케쥴러
131 monitoring - cpu reporter

https://jacking75.github.io/Learning_Boost_Asio/
https://www.slideshare.net/jacking/kgc-2012boostasio

132 네트워크 구조

241 databse http://egloos.zum.com/itbaby/v/4612805
309 인증서버



# 라이센스
BSD
MIT


GNU GPLv3
GNU LGPLv3
GNU AGPLv3


Boost Software License 1.0
Apache License 2.0
Mozilla Public License 2.0
