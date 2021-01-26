/*
 * @lc app=leetcode.cn id=535 lang=cpp
 *
 * [535] TinyURL 的加密与解密
 */
#include <string>
#include <map>

using std::string;

// @lc code=start
class Solution
{

    typedef std::string short_url_t;
    typedef std::string long_url_t;

public:
    std::string base_;
    std::uint64_t idx_ = 0;
    std::map<std::uint64_t, long_url_t> map_;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        std::uint64_t cur = idx_++;
        map_.emplace(cur, longUrl);
        return base_ + std::to_string(cur);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        auto idx = shortUrl.find_first_of(base_);
        auto px = shortUrl.substr(base_.length());
        return map_[atoi(px.c_str())];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @lc code=end
