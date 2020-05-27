/*
Producer Consumer Problem or Bounded Buffer Problem

PROBLEM STATEMENT:
    1. Procuer will produce and consumer will consume with synchronization of a common buffer
    2. Until producer thread produces any data, consumer thread can't consume.
    3. Threads will use condition_variable to notify each other
    4. We need mutex if we use condition_variable because CV waits on mutex.
    5. This is just one of the examples of producer consumer among many possible scenarios.

PRODUCERS thread steps:
    1. lock mutex, if success then go ahead otherwise wait for mutex to get free.
    2. check if buffer is full and if it is full then unlock mutex and sleep, if not then go ahead and produce.
    3. insert item in buffer
    4. unlock mutex.
    4. notify consumer

CONSUMER thread steps:
    1. lock mutex, if success then go ahead otherwise wait for mutex to get free.        
    2. check if buffer is empty and if it is, then unlock the mutex and sleep, if not then go ahead and consume.
    3. consume item from buffer.
    4. unlock mutex.
    5. notify producer
    
*/

#include <iostream>
#include <thread>
#include <queue>
#include <algorithm>
#include <chrono>
#include <mutex>
using namespace std;

std::mutex mu;
std::condition_variable cond;
deque<int> buffer;
const unsigned int maxBufferSize = 50;

void producer(int val) {
    while (val) {
        std::unique_lock<std::mutex> locker(mu);
        cond.wait(locker, [](){ return buffer.size() < maxBufferSize; });
        buffer.push_back(val);
        cout << "Produced : " << val << endl;
        --val;
        locker.unlock();
        cond.notify_one();
    }
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> locker(mu);
        cond.wait(locker, [](){ return buffer.size() > 0; });
        int val = buffer.back();
        buffer.pop_back();
        cout << "Consumed: " << val << endl;
        locker.unlock();
        cond.notify_one();
    }
}

int main() {
    std::thread t1(producer, 100);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}