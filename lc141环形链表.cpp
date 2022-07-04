class Solution {
public:
//1快慢指针法：有环必定发生套圈(快慢指针相遇),无环不会发生套圈(快指针到达null)
    bool hasCycle1(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=nullptr  && fast->next != nullptr){ 
        //注意：这里需要对fast和fast->next进行判空操作，因为它跑得快
            slow = slow->next ;
            fast = fast->next->next; //先对快慢指针递增，然后再判断它们是不是相等，相等表示有环
            if(slow == fast){
                return true;
            }
        }
        return false;//fast跑得快，如果fast到nullptr了退出循环说明一定没有环
    }
    //方法2：set集合判断
       bool hasCycle(ListNode *head) {
        set<ListNode*> s;
        bool flag = false;
        while(head){
            if(s.find(head) == s.end()){
                s.insert(head);
                head = head->next; 
            }else {
                flag= true;
                break;
            }
        }
        return flag;

    }
};