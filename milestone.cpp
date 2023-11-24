//===========================================================================
// Name        : Week 7 Portfolio Milestone
// Author      : Colleen Ammons
// Description : A C++ multithreaded program with 2 thraeds counting up
//               and down to 20.
// Pseudocode  : count(direction) {
//                  mutex
//                  var += direction }
//               main() {
//                  thread t1 = count(1)
//                  thread t2 = count(-1) }
//============================================================================
#include <thread>
#include <mutex>
#include <iostream>

std::mutex mtx;
int counter = 0;

void count(int direction, const std::string& threadName) {
    while (true) {
        // std::lock_guard locks and unlocks object automatically when it is constructed and destroyed
        std::lock_guard<std::mutex> lock(mtx); 
        if (counter == 20 && direction == 1) break;
        if (counter == -20 && direction == -1) break;
        counter += direction;
        std::cout << threadName << " Counter: " << counter << std::endl;
    }
}

int main() {
    std::thread t1(count, 1, "Thread 1");
    std::thread t2(count, -1, "Thread 2");

    t1.join();
    t2.join();

    return 0;
}
