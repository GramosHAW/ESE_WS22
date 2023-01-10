

#ifndef SRC_QUEUE_THREADSAFEQUEUE_H_
#define SRC_QUEUE_THREADSAFEQUEUE_H_
#include <string.h>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

struct werkstueck{
int id;
int heightSA1;
int heightSA2;
std::string Typ;
};

template<typename T>
class ThreadsafeQueue {
public:

	  T pop()
	  {
	    std::unique_lock<std::mutex> mlock(mutex_);
	    while (queue_.empty())
	    {
	      cond_.wait(mlock);
	    }
	    auto val = queue_.front();
	    queue_.pop();
	    return val;
	  }
	  void push(const T& item)
	  {
	    std::unique_lock<std::mutex> mlock(mutex_);
	    queue_.push(item);
	    mlock.unlock();
	    cond_.notify_one();
	  }
	  ThreadsafeQueue() = default;
	  ThreadsafeQueue(const ThreadsafeQueue&) = delete;
	  ThreadsafeQueue& operator =(const ThreadsafeQueue&) = delete;
private:
  std::queue<T> queue_;
  std::mutex mutex_;
  std::condition_variable cond_;
};

#endif /* SRC_QUEUE_THREADSAFEQUEUE_H_ */
