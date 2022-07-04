class Solution {
public:
    ListNode* reverseList1(ListNode* head) { //方法1：循环
        if(head==nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* pre = nullptr;
        ListNode* next = nullptr;
        ListNode* cur = head;
        while(cur!=nullptr){
            next = cur->next; //先记录要反转的下一个节点
            cur->next = pre; //反转(相当于把cur头插到以pre为头节点的已反转链表上)
            pre = cur;//更新pre，pre一直指向反转后链表的头
            cur = next; //更新cur为之前记录的下一个要反转的节点
        }
        return pre; //返回pre，pre一直指向反转后链表的头
    }
    ListNode* reverseList2(ListNode* head) { //方法2：递归
        if(head==nullptr || head->next ==nullptr){ 
        //base case :如果head为空或者只有head一个节点，那么直接返回
            return head;
        }
        ListNode* newHead = reverseList(head->next); 
        //递归返回head->next为头节点的链表，返回一个反转后链表的头
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};