/*
 Thread creation using a static member function
*/

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;
class Base {
public:
    static void func(int x) {
        while (x --> 0) {
            cout << x << endl;
        }
    }
};

int main() {
    std::thread t(&Base::func, 11);
    t.join();
    return 0;
}
