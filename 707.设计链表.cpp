/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */
 #include <utility>

// @lc code=start
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        size_ = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index<0 || index>= size_) return -1;
        ListNode *pCur = dummy_.next_; 
        while(index-- > 0) {
            pCur = pCur->next_;
        }
        return pCur->val_;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
       auto* ptr =  new ListNode();
       ptr->val_ = val;

       ptr->prev_ = &dummy_;
       ptr->next_ = dummy_.next_;

       dummy_.next_ = ptr;
       dummy_.next_->prev_ = ptr;

       size_++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        auto* ptr =  new ListNode();
        ptr->val_ = val;

        ptr->next_ = &dummy_;
        ptr->prev_ = dummy_.prev_;

        dummy_.prev_->next_ = ptr;
        dummy_.prev_ = ptr;

        size_++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index < 0) {
            addAtHead(val);
        } else if(index == size_ ) {
            addAtTail(val);
        } else if(index > size_) {
            // nop
        } else {
            // add before of pCur
            ListNode *pCur = dummy_.next_;
            while(index-- > 0) {
                pCur= pCur->next_;
            }
            ListNode* ptr = new ListNode();
            ptr->val_ = val;
            ptr->next_ = pCur;
            ptr->prev_ = pCur->prev_;
            pCur->prev_->next_  = ptr;
            pCur->prev_ = ptr;
            size_++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= 0 && index < size_) {
            ListNode *pCur = dummy_.next_;
            while(index-- > 0) {
                pCur= pCur->next_;
            }
            pCur->prev_->next_ = pCur->next_;
            pCur->next_->prev_ = pCur->prev_;
            delete pCur;
        }
    }

    private:
    struct ListNode {
        ListNode* next_;
        ListNode* prev_;
        int val_;
        ListNode() : next_(this), prev_(this) , val_(0) {}
    };
    ListNode dummy_;
    uint64_t size_;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

