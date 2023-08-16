//编译：g++ hh_test.cpp -o hh_test.out -lpthread
#include<iostream>
#include<string.h>
#include<thread>

class Singleton
{
    protected:
    Singleton(const std::string value):value_(value){}

    static Singleton* singleton_;
    std::string value_;

    public:
    Singleton(Singleton &other) = delete;

    void operator=(const Singleton&) = delete;

    static Singleton *GetInstance(const std::string& value);

    void SomeBusinessLogic()
    {
        //......
    }
    std::string value() const{
        return value_;
    }
};

Singleton* Singleton::singleton_ = nullptr;

Singleton *Singleton::GetInstance(const std::string& value)
{
    if(singleton_ == nullptr)
    {
        singleton_ = new Singleton(value);
    }
    return singleton_;
}

void ThreadFoo(){
    //sleep_for()阻塞当前线程一段时间
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));//阻塞当前线程1000毫秒
    Singleton* singleton = Singleton::GetInstance("FOO");
    std::cout << singleton->value() << "\n";
}

void ThreadBar(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("BAR");
    std::cout << singleton->value() << "\n";
}


int main()
{

    std::cout << "result:" << std::endl;
    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();

    return 0;
}
