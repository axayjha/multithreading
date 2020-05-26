#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

std::condition_variable cv;
std::mutex m;

long balance = 600;

void addMoney(int money) {
    std::lock_guard<mutex> lg(m);
    balance += money;
    cout << "Amount added. Current balance: " << balance << endl;
    cv.notify_one();
}

void withdrawMoney(int money) {
    std::unique_lock<mutex> ul(m);
    cv.wait(ul, [money]{ return (balance-money >= 0) ? true : false; });
    if (balance >= money) {
        balance -= money;
        cout << "Amount deducted: " << money << "\n";
    } else {
        cout << "Amount can't be deducted. Current balance is less than " << money << endl;
    }
    cout << "Current balance is " << balance << "\n";
}

int main() {
    thread t2(addMoney, 500);

    thread t1(withdrawMoney, 500);
    t1.join();
    t2.join();
    return 0;

}