class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->pre = head;
    }
    int get(int key) {
        if(h.find(key) == h.end()){
            //如果key没有直接返回-1
            return -1;
        }
        //根据key定位到那个节点：在map中通过key得到那个Node
        Node* node = h[key];
        remove(node);  //在双链表中删除node节点
        insert(head,node); //在head后面插入node节点
        return node->value;
    }

    void put(int key, int value) {
        if(h.find(key) == h.end()){//key不存在缓存中，就需要插入
            Node* node = new Node();
            node->key = key;
            node->value = value;
            h[key] = node;
            insert(head,node);
            if(h.size()>capacity){
                h.erase(tail->pre->key); //先删除键值对，在删除链表节点，无法无法找到那个节点了
                remove(tail->pre);
            }
        }else { //如果存在，更新value，从链表中删除，并且放到开头位置
            Node* node = h[key];
            node->value = value;
            remove(node);
            insert(head,node);
        }
    }
private:
    struct Node {//双链表节点定义
        int value;
        int key;
        Node * pre;
        Node * next;
    };
    unordered_map<int,Node*>  h;//为了快速在链表中找到某个值
    Node* head; //二个保护节点head和tail
    Node* tail;
    int capacity;
    void remove(Node* node){//在双链表中删除node节点
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    void insert(Node* p,Node *node){//将node节点插入到链表head后面
        node->next = p->next;
        p->next->pre = node;
        p->next = node;
        node->pre = p;
    }
};