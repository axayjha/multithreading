#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex m1;
int buffer = 0;

void task0(const char* threadNumber, int loopFor) {
    m1.lock();
    for (int i = 0; i < loopFor; ++i) {
        buffer++;
        cout << threadNumber << " " << buffer << "\n";
    }
    m1.unlock(); // everytime we have to unlock before going out of scope.
    // So why not make it automated by using lock_guard
}

void task(const char* threadNumber, int loopFor) {
    std::lock_guard<mutex> lock(m1); // wrapper for owning the mutex; automatically locks m1
    for (int i = 0; i < loopFor; ++i) {
        buffer++;
        cout << threadNumber << " " << buffer << "\n";
    }
}


int main() {
    thread t1(task, "T0 ", 10);
    thread t2(task, "T1 ", 10);
    t1.join();
    t2.join();
    return 0;
}