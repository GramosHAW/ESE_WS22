#ifndef SRC_QUEUE_THREADSAFEQUEUE_H_
#define SRC_QUEUE_THREADSAFEQUEUE_H_
#include <string.h>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>



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
	  T& front ()//Nicht threadsafe :'(
	  {
		  std::unique_lock<std::mutex> mlock(mutex_);
		  while (queue_.empty())
		  {
			cond_.wait(mlock);
		  }
		  return queue_.front();
	  }
	  void push(const T& item)
	  {
	    std::unique_lock<std::mutex> mlock(mutex_);
	    queue_.push(item);
	    mlock.unlock();
	    cond_.notify_one();
	  }
	  int size(){//Auch nicht threadsafe :((
		  return queue_.size();
	  }
	  bool empty(){ //Nicht threadsafe :'(
		  return queue_.empty();
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
