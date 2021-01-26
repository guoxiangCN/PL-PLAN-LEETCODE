/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include <stack>

// @lc code=start
class MyQueue
{
private:
    std::stack<int> s1_;
    std::stack<int> s2_;

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        s1_.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        while (s1_.size() > 1)
        {
            s2_.push(s1_.top());
            s1_.pop();
        }
        int ret = std::move(s1_.top());
        s1_.pop();

        while (!s2_.empty())
        {
            s1_.push(s2_.top());
            s2_.pop();
        }
        return ret;
    }

    /** Get the front element. */
    int peek()
    {
        while (s1_.size() > 1)
        {
            s2_.push(s1_.top());
            s1_.pop();
        }
        int ret = s1_.top();
        while (!s2_.empty())
        {
            s1_.push(s2_.top());
            s2_.pop();
        }
        return ret;
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return s1_.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
