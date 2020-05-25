



#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

int amount = 0; // shared resource

std::mutex m;

void addMoney() {
    m.lock();
    ++amount; //critical section
    m.unlock();
}

int main() {
    std::thread t1(addMoney);
    std::thread t2(addMoney);

    t1.join();
    t2.join();

    cout << "Amount: " << amount << endl;

    return 0;
}