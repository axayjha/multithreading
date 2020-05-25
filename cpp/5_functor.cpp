/*
 Thread creation using Functor (function object)
*/

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

class Base {
public:
    void operator()(int x) {
        while (x --> 0) {
            cout << x << endl;
        }
    }
};

int main() {
    std::thread t1((Base()), 10);
    t1.join();

    return 0;
}