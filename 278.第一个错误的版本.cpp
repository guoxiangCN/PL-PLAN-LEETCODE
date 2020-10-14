/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 * 你真牛逼，你开发了1420736637个版本。产品经理呢，抓过来让他做，做不满1420736637个版本不让走。
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

extern bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        while(n >= 1) {
            if(isBadVersion(n)) {
                n--;
            } else {
                return n + 1;
            }
        }
        return n + 1;
    }
};
// @lc code=end

