/*
 * @lc app=leetcode.cn id=1195 lang=cpp
 *
 * [1195] 交替打印字符串
 */

// @lc code=start
#include <functional>
#include <mutex>
#include <condition_variable>
using std::function;

class FizzBuzz
{
private:
    int n;
    int x;
    std::mutex mtx_;
    std::condition_variable cv_;

public:
    FizzBuzz(int n)
    {
        this->n = n;
        this->x = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz)
    {
        while (x <= n)
        {
            std::unique_lock<std::mutex> guard(mtx_);
            if (x % 3 == 0 && x % 5 != 0)
            {
                printFizz();
                x++;
                cv_.notify_all();
            }
            else
            {
                cv_.wait(guard);
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz)
    {
        while (x <= n)
        {
            std::unique_lock<std::mutex> guard(mtx_);
            if (x % 5 == 0 && x % 3 != 0)
            {
                printBuzz();
                x++;
                cv_.notify_all();
            }
            else
            {
                cv_.wait(guard);
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz)
    {
        while (x <= n)
        {
            std::unique_lock<std::mutex> guard(mtx_);
            if (x % 5 == 0 && x % 3 == 0)
            {
                printFizzBuzz();
                x++;
                cv_.notify_all();
            }
            else
            {
                cv_.wait(guard);
            }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber)
    {
        while (x <= n)
        {
            std::unique_lock<std::mutex> guard(mtx_);
            if (x % 5 != 0 && x % 3 != 0)
            {
                printNumber(x++);
                cv_.notify_all();
            }
            else
            {
                cv_.wait(guard);
            }
        }
    }
};
// @lc code=end
