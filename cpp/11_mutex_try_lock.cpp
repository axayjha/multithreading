



#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

int counter = 0;
std::mutex mtx;

void increase() {
    for (int i = 0; i < 100000; i++) {
        if (mtx.try_lock()) {
            ++counter;
            mtx.unlock();
        }
    }
}



int main() {

    std::thread t1(increase);
    std::thread t2(increase);

    t1.join();
    t2.join();

    cout << "Counter value: " << counter << endl;


}