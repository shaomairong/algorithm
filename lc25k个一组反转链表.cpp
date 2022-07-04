//1.getKGroupEnd函数：获得k个一组节点的结尾节点
    ListNode* getKGroupEnd(ListNode* head,int k){
        
        while(--k !=0 && head !=nullptr){
            head = head->next;
        }
        //如果--k为真但head为null表示不足k个，那么直接返回head(此时head为null)
        return head;
        //后续可以通过判断head==nullptr来判断是不是需要反转
        //如果head为null，说明不足k个，那么不用反转
    }
    
    
    //2.revese函数:反转start-end区间的节点，并且要记录反转区间的下一个节点
    void revese(ListNode* start,ListNode * end){
        end = end->next; //记录反转区间的下一个节点
        ListNode* pre = nullptr;
        ListNode* next = nullptr;
        ListNode* cur = start; 
        //start指向反转前的开始节点（即反转后的末尾节点）,后面要将start->next连接到下一区间的开始节点（也即是前面记录的end=end->next）
        while(cur!=end){
            next = cur->next; //记录下一个要反转的节点
            cur->next = pre; //pre表示已经反转好的链表的头，用头插法将cur插到pre的前面
            pre = cur; //更新pre指向已经反转后的链表的新头结点
            cur = next;  //跟新cur为下一个要进行头插的节点
        }
        start->next = end;
        //start此时为反转后区间的尾节点了，它的next要指向下一个区间的开始节点（即上面记录的end）
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start = head;
        ListNode* end = getKGroupEnd(start,k);
        if(end == nullptr){ //不足k个不用反转
            return head;
        }
        //end不为空，说明end为要反转的第一个区间的结尾节点
        head = end; //让head指向第一个要反转区间的末尾节点，即第一个区间反转后的开始节点，也是整个链表反转后的开始节点
        revese(start,end); //反转第一个区间
        ListNode* lastEnd = start; //记录反转后区间的末尾节点
        while(lastEnd->next!=nullptr){
            start = lastEnd->next;
            end = getKGroupEnd(start,k);
            if(end == nullptr){ //不足k个不用反转
                break;
            }
            revese(start,end);
            lastEnd->next = end;//更新：让上一区间的最后一个节点指向 当前区间反转后的开始节点
            lastEnd =  start; //更新lastEnd为当前区间反转后的结尾节点
        }
        return head;
    }