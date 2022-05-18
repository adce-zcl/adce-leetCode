// 设计链表
class MyLinkedList 
{
private:
    struct Node
    {
        int val;
        struct Node *next;
        struct Node *prev;
        Node(int _val):val(_val),next(nullptr),prev(nullptr){}
    };
    struct Node *head;
    struct Node *tail;
    int size;

public:
    MyLinkedList() 
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    int get(int index) 
    {
        if(index < 0 || index >= size)  // 索引无效
        {
            return -1;
        }
        Node *temp = head;
        int i = 0;
        while (i < index)
        {
            temp = temp->next;
            ++i;
        }
        return temp->val;
    }
    
    void addAtHead(int val) 
    {
        Node *temp = new Node(val);
        if(head == nullptr)
        {
            tail = temp;
            head = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        ++size;
    }
    
    void addAtTail(int val) 
    {
        Node *temp = new Node(val);
        if(tail == nullptr)
        {
            tail = temp;
            head = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        ++size;
    }
    
    void addAtIndex(int index, int val) 
    {
        if (index > size)
        {
            return;
        }
        else if(index <= 0)
        {
            addAtHead(val);
        }
        else if(index == size)
        {
            addAtTail(val);
        }
        else
        {
            Node *temp = head;
            int i = 0;
            while (i < index)
            {
                temp = temp->next;
                ++i;
            }
            Node *prv = temp->prev;
            // 在temp之前插入
            Node *current = new Node(val);
            current->next = temp;
            temp->prev = current;
            current->prev = prv;
            prv->next = current;
            size++;
        }
    }
    
    void deleteAtIndex(int index) 
    {
        if(index < 0 || index >= size)
        {
            return;
        }
        else if(index == 0)
        {
            // 删除头节点
            Node *temp = head;
            head = head->next;
            delete temp;
            --size;
        }
        else if(index == size - 1)
        {
            // 删除尾节点
            Node *temp = tail;
            tail = tail->prev;
            delete temp;
            --size;
        }
        else
        {
            Node *temp = head;
            int i = 0;
            while (i < index)
            {
                temp = temp->next;
                ++i;
            }
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete temp;
            --size;
        }
    }
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

int main()
{
    MyLinkedList *linkedList = new MyLinkedList();
    linkedList->addAtHead(1);
    linkedList->addAtTail(3);
    linkedList->addAtIndex(1, 2);
    linkedList->get(1);
    linkedList->deleteAtIndex(1);
    linkedList->get(1);
}