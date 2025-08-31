#include"woker.h"
#include <chrono>
#include <thread>

void Worker::run()
{
    auto start = std::chrono::steady_clock::now();
    int lastSec = 0;
    long long min = 0;

    while (!QThread::currentThread()->isInterruptionRequested()) {
        auto now = std::chrono::steady_clock::now();
        long long sec = std::chrono::duration_cast<std::chrono::seconds>(now - start).count();

        if (sec != lastSec) {
            lastSec = sec;
            emit timeChanged(min, sec);
        }

        if (sec >= 60) {
            ++min;
            start = std::chrono::steady_clock::now();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}
