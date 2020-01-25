
std::optional http://occamsrazr.net/tt/entry/C17-%ED%91%9C%EC%A4%80-%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC%EC%9D%98-stdoptional-%EC%86%8C%EA%B0%9C

``` cpp
std::pair<bool, Something> get_option(const std::string& name);
```

실패시에도 Something을 만들어야함..
std::optional<Something>이 있음



std::string_view
https://openmynotepad.tistory.com/47?category=853099

void println(const string_view& str)
{
    cout << str << endl;
}

using namespace std::literals
"Hello, world!"sv



==== 애매한데...
std::variant https://openmynotepad.tistory.com/50 - 타입 안전 공용체
std::visit

std::bitset
https://en.cppreference.com/w/cpp/utility/bitset