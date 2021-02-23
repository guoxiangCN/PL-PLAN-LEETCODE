

/*
 * @lc app=leetcode.cn id=1206 lang=cpp
 *
 * [1206] 设计跳表
 * 
 * 2021/02/23
 */
#include <vector>
#include <iostream>
#include <cassert>
#include <ctime>
#include <atomic>
#include <random>
#include <stdio.h>

#define NEVER_REACH do {                                                       \
     fprintf(stderr, "NEVER_REACH CODE RAN at %s:%d\n", __FILE__, __LINE__);    \
     exit(1);                                                                   \
     } while(0)

 // @lc code=start
class Skiplist {
    class Node;
public:
    Skiplist() : head_(0, kMaxLevel), max_height_(1) {

    }

    bool search(int target) {
        Node* ptr = FindGreaterOrEqual(target, nullptr);
        return ptr == nullptr ? false : (ptr->val == target);
    }

    void add(int num) {
        Node* prevs[kMaxLevel];                   // 0 - (kMaxLevel-1)
        Node* x = FindGreaterOrEqual(num, prevs); // 0 - (maxHeigh-1)
        assert(x == nullptr || x->val >= num);

        // 1/4概率给新的SkipListNode增加level.
        int level = 1;
        time_t s = time(nullptr);
        if (static_cast<int>(s) % 4 == 0) {
            std::default_random_engine dre;
            std::uniform_int_distribution<int> distribution(2, kMaxLevel);
            level = distribution(dre);
        }

        if (level > max_height_) {
            for (int i = max_height_.load(); i < kMaxLevel; i++) {
                prevs[i] = &head_;
            }
            max_height_.store(level);
        }

        Node* sNode = new Node(num, level);
        for (int i = 0; i < level; i++) {
            sNode->SetNext(i, prevs[i]->GetNext(i));
            prevs[i]->SetNext(i, sNode);
        }
    }

    bool erase(int num) {
        for (;;) {
            Node* prevs[kMaxLevel] = { 0 };
            Node* sNode = FindGreaterOrEqual(num, prevs);
            if (sNode == nullptr || sNode->val != num) {
                break;
            }
            for (int i = 0; i < sNode->GetHeight(); i++) {
                prevs[i]->SetNext(i, sNode->GetNext(i));
            }
            delete sNode;
            // fprintf(stdout, "delete-op \n");
        }
        return true;
    }

private:
    Node* FindGreaterOrEqual(int val, Node** prev) {
        int level = max_height_.load() - 1;
        Node* x = &head_;
        for (;;) {
            // fprintf(stdout, "enter loop, level = %d, val = %d \n", level, val);
            Node* next = x->GetNext(level);
            if (KeyIsAferNode(val, next)) {
                x = next;
            }
            else {
                if (prev != nullptr) prev[level] = x;
                if (level == 0) {
                    return next;
                }
                else {
                    level--;
                }
            }
        }
    }

    inline bool KeyIsAferNode(int key, Node* x) {
        return x != nullptr && key > x->val;
    }
private:
    struct Node {
        int val;
        std::vector<Node*> nexts_;

        Node(int val, int level) {
            this->val = val;
            this->nexts_.resize(level, nullptr);
        }

        void SetNext(int level, Node* next) {
            assert(level <= nexts_.size());
            nexts_[level] = next;
        }

        Node* GetNext(int level) {
            assert(level <= nexts_.size());
            return nexts_[level];
        }

        int GetHeight() const { return nexts_.size(); }
    };
    Node head_;
    std::atomic<int32_t> max_height_;
    static const int kMaxLevel = 6;
};

//int main(int argc, char** argv) {
//    Skiplist list;
//    list.add(1);
//    list.add(2);
//    list.add(3);
//    list.add(1);
//    list.add(2);
//    list.add(2);
//
//    std::cout << std::boolalpha << "contains 1 :" << list.search(1) << std::endl;
//    std::cout << std::boolalpha << "contains 2 :" << list.search(2) << std::endl;
//    std::cout << std::boolalpha << "contains 3 :" << list.search(3) << std::endl;
//    std::cout << std::boolalpha << "contains 4 :" << list.search(4) << std::endl;
//    std::cout << std::boolalpha << "contains 5 :" << list.search(5) << std::endl;
//
//    list.erase(2);
//
//    std::cout << "after- erase--" << std::endl;
//
//    std::cout << std::boolalpha << "contains 1 :" << list.search(1) << std::endl;
//    std::cout << std::boolalpha << "contains 2 :" << list.search(2) << std::endl;
//    std::cout << std::boolalpha << "contains 3 :" << list.search(3) << std::endl;
//    std::cout << std::boolalpha << "contains 4 :" << list.search(4) << std::endl;
//    std::cout << std::boolalpha << "contains 5 :" << list.search(5) << std::endl;
//	return 0;
//}
