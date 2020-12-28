/*
 * @lc app=leetcode.cn id=1115 lang=cpp
 *
 * [1115] 交替打印FooBar
 */

// @lc code=start

#include "pthread.h" // -lpthread
#include <functional>
#include <sys/select.h>

using std::function;

class FooBar {
private:
  int n;

public:
  FooBar(int n) { this->n = n; }

  void foo(function<void()> printFoo) {

    for (int i = 0; i < n; i++) {

      // printFoo() outputs "foo". Do not change or remove this line.
      printFoo();
    }
  }

  void bar(function<void()> printBar) {

    for (int i = 0; i < n; i++) {

      // printBar() outputs "bar". Do not change or remove this line.
      printBar();
    }
  }
};
// @lc code=end
