
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <algorithm>
#include <future>

using namespace std;
using namespace std::chrono;


typedef unsigned long long ull;


void findOdd(std::promise<ull>&& oddSumPromise, ull start, ull end) {
    ull oddSum = 0;
    for (ull i = start; i <= end; i++) {
        if (i & 1) {
            oddSum += i;
        }
    }

    oddSumPromise.set_value(oddSum);
}


int main() {
    ull start = 0, end = 1900000000;
    std::promise<ull> oddSum;
    std::future<ull> oddFuture = oddSum.get_future();

    cout << "Thread created.\n";

    std::thread t1(findOdd, std::move(oddSum), start, end);

    cout << "Waiting for result...\n";

    cout << "Odd sum: " << oddFuture.get() << endl;

    cout << "Completed\n";

    t1.join();
    return 0;
}
