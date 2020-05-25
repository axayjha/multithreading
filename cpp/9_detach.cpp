



#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void run(int count) {
    while (count --> 0) {
        cout << count << " test" << endl;
    }
    std::this_thread::sleep_for(chrono::seconds(5));
}

int main() {
    std::thread t1(run, 11);

    cout << "start" << endl;

    t1.detach();
    
    if (t1.joinable()) 
        t1.detach();

    cout << "end" << endl;
    return 0;       
}