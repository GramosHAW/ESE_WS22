#ifndef THREADPOOL_H
#define THREADGPOOL_H

#include <cstddef>
#include <functional> // ref()
#include <thread>
#include <vector>
#include <mutex>
#include <queue>


class ThreadPool{
public:
	ThreadPool();
	virtual ~ThreadPool();
    void Start();
    void QueueJob(const std::function<void()>& job);
    void Stop();

private:
    void ThreadLoop();

    bool should_terminate = false;           // Tells threads to stop looking for jobs
    std::mutex queue_mutex;                  // Prevents data races to the job queue
    std::condition_variable mutex_condition; // Allows threads to wait on new jobs or termination
    std::vector<std::thread> threads;
    std::queue<std::function<void()>> jobs;
};

#endif
