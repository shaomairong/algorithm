class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=nullptr && fast->next !=nullptr){
            fast = fast->next->next ;
            slow = slow->next;
            if(fast == slow){ //有环，这里是快慢指针的相遇点
                while(head!=slow){ //从相遇点和head同时出发，二指针相遇即为环的入口节点
                    head=head->next;
                    slow=slow->next;
                }
                return head; //环的入点
            }
        }
        return nullptr;
    }
};