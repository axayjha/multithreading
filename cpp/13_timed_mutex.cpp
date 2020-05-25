

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

int myAmount = 0 ;
std::timed_mutex m;

void increment(int i) {
    if (m.try_lock_for(std::chrono::seconds(1))) {
        ++myAmount;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "Thread " << i << " entered" << endl;
        m.unlock();
    } else {
        cout << "Thread " << i << " couldnt be entered" << endl;
    }
}

void increment1(int i) {
    auto now = std::chrono::steady_clock::now();
    if (m.try_lock_until(now + std::chrono::seconds(1))) {
        ++myAmount;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "Thread " << i << " entered" << endl;
        m.unlock();
    } else {
        cout << "Thread " << i << " couldnt be entered" << endl;
    }
}

int main() {
    std::thread t1(increment1, 1);
    std::thread t2(increment1, 2);

    t1.join();
    t2.join();

    cout << myAmount << endl;

    return 0;
}