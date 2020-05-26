#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex m1;
std::mutex m2;

void task_a() {
    while (1) {
        std::lock(m1, m2);
        cout << "Task A \n";
        m1.unlock();
        m2.unlock();
    }
}

void task_b() {
    while (1) {
        std::lock(m2, m1);
        cout << "Task B \n";
        m2.unlock();
        m1.unlock();
    }
}


int main() {
    thread t1(task_a);
    thread t2(task_b);

    t1.join();
    t2.join();

    return 0;
}