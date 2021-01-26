/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */
#include <algorithm>
#include <list>

// @lc code=start
class LRUCache {
private:
  struct Entry {
    int m_k;
    int m_v;
    Entry(int k, int v) : m_k(k), m_v(v) {}
  };
  std::list<Entry> m_entries;
  int m_cap;

public:
  LRUCache(int capacity) { m_cap = capacity; }

  int get(int key) {
    int ret = -1;
    for (auto it = m_entries.begin(); it != m_entries.end(); it++) {
      if (it->m_k == key) {
        ret = it->m_v;
        Entry backup = *it;
        m_entries.erase(it);
        m_entries.push_front(std::move(backup));
        break;
      }
    }
    return ret;
  }

  void put(int key, int value) {
    for (auto it = m_entries.begin(); it != m_entries.end(); it++) {
      if (it->m_k == key) {
        m_entries.erase(it);
        m_entries.push_front(Entry(key, value));
        return;
      }
    }

    if (m_entries.size() == m_cap) {
      m_entries.pop_back();
    }
    m_entries.push_front(Entry(key, value));
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
