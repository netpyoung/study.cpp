/MP : 멀티프로세스 컴파일
/Gm : 미니말 리빌드

MP/Gm 서로 충돌
## TODO

- <https://github.com/dattanchu/bprinter>



vcpkg install sfml:x64-windows
vcpkg install imgui-sfml:x64-windows


https://github.com/eliasdaler/imgui-sfml
https://tgui.eu/


c++17
https://en.cppreference.com/w/cpp/types/byte
A numeric value n can be converted to a byte value using std::byte{n}, due to C++17 relaxed enum class initialization rules.



c++20부터네...
https://en.cppreference.com/w/cpp/container/unordered_set/contains


typename
https://stackoverflow.com/a/613132


delete - https://github.com/netpyoung/netpyoung.Notes/blob/master/dev/tool_info/Cmake.md


c++14: binary literal, digit seperator
int i = 0b0011;
int j = 0B01101001;
int k = 0B0101'0111'1100;


https://docs.microsoft.com/en-us/cpp/preprocessor/optimize?view=msvc-170
#pragma optimize("gpsy", off)
#pragma optimize("gpsy", on)

g Enable global optimizations.
s Specify short or fast sequences of machine code.
y Generate frame pointers on the program stack.

#pragma optimize( "", off )
/* unoptimized code section */
#pragma optimize( "", on )