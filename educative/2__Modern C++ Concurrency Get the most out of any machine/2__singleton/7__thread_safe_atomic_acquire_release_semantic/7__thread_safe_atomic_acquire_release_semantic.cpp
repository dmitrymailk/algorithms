// singletonAcquireRelease.cpp

#include <atomic>
#include <iostream>
#include <future>
#include <mutex>
#include <thread>

constexpr auto tenMill = 10000000;

class MySingleton
{
public:
    static MySingleton *getInstance()
    {
        MySingleton *sin = instance.load(std::memory_order_acquire);
        if (!sin)
        {
            std::lock_guard<std::mutex> myLock(myMutex);
            sin = instance.load(std::memory_order_relaxed);
            if (!sin)
            {
                sin = new MySingleton();
                instance.store(sin, std::memory_order_release);
            }
        }
        volatile int dummy{};
        return sin;
    }

private:
    MySingleton() = default;
    ~MySingleton() = default;
    MySingleton(const MySingleton &) = delete;
    MySingleton &operator=(const MySingleton &) = delete;

    static std::atomic<MySingleton *> instance;
    static std::mutex myMutex;
};

std::atomic<MySingleton *> MySingleton::instance;
std::mutex MySingleton::myMutex;

int main()
{

    constexpr auto fourtyMill = 4 * tenMill;

    const auto begin = std::chrono::system_clock::now();

    for (size_t i = 0; i <= fourtyMill; ++i)
    {
        MySingleton::getInstance();
    }

    const auto end = std::chrono::system_clock::now() - begin;

    std::cout << std::chrono::duration<double>(end).count() << std::endl;
}