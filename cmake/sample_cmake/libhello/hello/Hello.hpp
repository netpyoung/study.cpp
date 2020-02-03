#pragma warning(push, 0)
#include <cstdint>
#pragma warning(pop)

namespace hello
{
    class Hello final
    {
    public:
        Hello() = default;
        Hello(Hello const& other) = delete;
        virtual ~Hello() = default;
        Hello& operator=(Hello const& other) = delete;
    public:
        int32_t Add(int32_t const a, int32_t const b) const;
    };
}
