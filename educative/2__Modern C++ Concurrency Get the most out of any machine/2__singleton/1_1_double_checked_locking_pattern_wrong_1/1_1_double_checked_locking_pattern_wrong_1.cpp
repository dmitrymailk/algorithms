#include <iostream>
#include <mutex>
#include <thread>

std::mutex myMutex;

class MySingleton
{
public:
    static MySingleton *getInstance()
    {
        std::lock_guard<std::mutex> myLock(myMutex);
        if (!instance)
            instance = new MySingleton();
        return instance;
    }

private:
    MySingleton() = default;
    ~MySingleton() = default;
    MySingleton(const MySingleton &) = delete;
    MySingleton &operator=(const MySingleton &) = delete;
    static MySingleton *instance;
};

MySingleton *MySingleton::instance = nullptr;

int main()
{

    std::cout << std::endl;

    std::cout << "MySingleton::getInstance(): " << MySingleton::getInstance() << std::endl;
    std::cout << "MySingleton::getInstance(): " << MySingleton::getInstance() << std::endl;

    std::cout << std::endl;
}