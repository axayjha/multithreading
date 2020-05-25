/*
 Thread creation using a non-static member function
*/

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;
class Base {
public:
    void func(int x) {
        while (x --> 0) {
            cout << x << endl;
        }
    }
};

int main() {
    Base b;
    std::thread t(&Base::func, &b, 11);
    t.join();
    return 0;
}
