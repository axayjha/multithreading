// Thread creation using function pointer

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void fun(int x) {
    while (x --> 0) {
        cout << x << endl;
    }
}

int main() {
    thread t1(fun, 10);
    thread t2(fun, 12);
    t1.join();
    t2.join();

    return 0;
}