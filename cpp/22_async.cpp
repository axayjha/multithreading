/*

std::async

* NOTES
1. It runs a function asynchronously (potentially in a new thread) and returns a std::future
that will hold the result.
2. There are three launch policies for creating task:
    a. std::launch::async
    b. std::launch::deferred
    c. std::launch::async | std::launch::deferred

* HOW IT WORKS:
1. It automatically creates a thread (or picks from internal thread pool)
   and creates a promise object for us.
2. It then passes the std::promise object to the thread function and returns the
   associated std::future object
3. When our passed argument function exists then its value will be set in this promise
object, so eventually return value will be available in std::future object.

* SIDE NOTES:
1. We can send functor and lambda functions as callbacks to std::async it will work the same.


*/
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <algorithm>
#include <future>

using namespace std;
using namespace std::chrono;


typedef unsigned long long ull;


ull findOdd(ull start, ull end) {
    ull oddSum = 0;
    for (ull i = start; i <= end; i++) {
        if (i & 1) {
            oddSum += i;
        }
    }
    return oddSum;
}


int main() {
    ull start = 0, end = 1900000000;

    cout << "Thread created if policy is std::launch::async \n";


    std::future<ull> oddSum = std::async(std::launch::deferred, findOdd, start, end);

    cout << "Waiting for result...\n";

    cout << "Odd sum: " << oddSum.get() << endl;

    cout << "Completed\n";

    return 0;
}
