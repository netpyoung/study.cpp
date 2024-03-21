

learn opengl 번역
https://heinleinsgame.tistory.com/category/?page=2


bloom
2패스 가우시안 블러 https://blog.naver.com/PostList.nhn?blogId=oovqiss&from=postList&categoryNo=13

SSS
1 http://blog.naver.com/mnpshino/221442188568
3 https://blog.naver.com/mnpshino/221442210257

https://www.alanzucconi.com/2017/08/30/fast-subsurface-scattering-1/


FSS https://www.alanzucconi.com/2017/08/30/fast-subsurface-scattering-2/



# extension method. cpp n4174
https://mariusbancila.ro/blog/2014/10/15/extension-methods-in-cpp/
http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4165.pdf
http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4174.pdf

c++17까지도 통과 안됨.

함수 포인터
https://stackoverflow.com/questions/30748919/modern-c-alternative-to-function-pointers

https://github.com/netpyoung/netpyoung.Notes/tree/master/notes/c


c++11 - Uniform Initialization
https://modoocode.com/286
``` cpp
#include <iostream>

class A {
 public:
  A() { std::cout << "A 의 생성자 호출!" << std::endl; }
};

int main() {
  A a();  // ? 아무것도 출력되지 않음.
}
```

``` cpp
#include <iostream>

class A {
 public:
  A() { std::cout << "A 의 생성자 호출!" << std::endl; }
};

int main() {
  A a{};  // 균일한 초기화!
}
```

``` cpp
#include <iostream>

class A
{
 public:
  A(int x) { std::cout << "A 의 생성자 호출!" << std::endl; }
};

int main()
{
  A a(3.5);  // Narrow-conversion 가능
  A b{3.5};  // Narrow-conversion 불가
}
```



클래스 사용 시 재정의( 오버라이드 ) 를 해야하는 경우가 많이 생긴다.

하지만 재정의를 하는데 인자를 더 넣는다거나 반환형이 다르게 만든다거나

하는 실수를 컴파일러가 걸러주지는 않는다.

이런 실수를 막기 위해 사용되는 키워드로 재정의 하고자 하는 클래스에 함수 선언시 override를 붙여 주면 되며

가독성도 좋아진다. 이 함수가 재정의 된 함수인지 아닌지 한 눈에 들어온다.



출처: https://wnsgp.tistory.com/62 [전역하고 공부 하려고 만든 블로그]