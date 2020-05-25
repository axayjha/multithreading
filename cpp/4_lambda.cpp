// Thread creation using lambda function

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

int main() {
    // auto fun = [] (int x) {
    //     while (x --> 0) {
    //         cout << x << endl;
    //     }
    // };

    // std::thread t1(fun, 11);
    // t1.join();

    /* OR */

    std::thread t2([] (int x) {
        while (x --> 0) {
            cout << x << endl;
        }
    }, 15);
    t2.join();

    return 0;
}