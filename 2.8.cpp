#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct Node
{
    char *data;
    Node *next;
    Node(char *data, Node *next);
};
Node::Node(char *data, Node *next = nullptr)
{
    this->data = data;
    this->next = next;
}

class LinkedList
{
public:
    int Siize();
    void printt();
    void push_front(char *data);
    void empty();
    void Free_Mem();
    void Assert(char *new_elem);
    int Size;
    Node *head;
    LinkedList();
    ~LinkedList();
    char *Find(int index);
};

char *LinkedList::Find(int index)
{
    Node *n = head;
    for (int i = 1; i < index; i++)
        n = n->next;
    return n->data;
}
LinkedList::LinkedList()
{
    head = nullptr;
    Size = 0;
}

LinkedList::~LinkedList()
{
}
int LinkedList::Siize()
{
    return Size;
}
void LinkedList::push_front(char *data)
{
    head = new Node(data, head);
    Size++;
}
void LinkedList::Free_Mem()
{
    Node *n = head->next;
    delete head;
    head = n;
    Size--;
}
void LinkedList::empty()
{
    while (Size != 0)
    {
        Free_Mem();
    }
}
void LinkedList::printt()
{
    for (Node *n = head; n != nullptr; n = n->next)
    {
        cout << n->data << " ";
    }
}
void LinkedList::Assert(char *new_elem)
{
    Node *n = head;
    while (n != nullptr)
    {
        if (typeid(n->data).name() == typeid(char *).name())
        {
            Node *em = new Node(new_elem, n->next);
            em->data = new char[strlen(new_elem) + 1];
            strcpy(em->data, new_elem);
            n->next = em;
            Size++;
            break;
        }
        n = n->next;
    }
}

struct TwoNode
{
    int data;
    TwoNode *next;
    TwoNode *prev;
    TwoNode(int data, TwoNode *next = nullptr, TwoNode *prev = nullptr)
    {
        this->next = next;
        this->prev = prev;
        this->data = data;
    }
};

class TwoListNode
{
public:
    TwoListNode(int data);
    void push_front(int data);
    void print();
    void del_even_elen();
    void FreMem();

    int size = 0;
    TwoNode *head = nullptr;
};

TwoListNode::TwoListNode(int data)
{
    head = new TwoNode(data);
    size++;
}
void TwoListNode::push_front(int data)
{
    TwoNode *n = new TwoNode(data, head);
    if (head != nullptr)
    {
        head->prev = n;
    }

    head = n;
    size++;
}
void TwoListNode::print()
{

    for (TwoNode *n = head; n != nullptr; n = n->next)

        cout << "Unit "
             << ": " << n->data << endl;
}

void TwoListNode::del_even_elen()
{
    TwoNode *n = head;
    TwoNode *m = nullptr;

    while (n != nullptr)
    {
        if (n->data % 2 == 0)
        {

            if (n == head)
            {
                head = n->next;
                if (head != nullptr)
                {
                    head->prev = nullptr;
                }
                delete n;
                n = head;
            }
            else if (n->next == nullptr)
            {
                m->next = nullptr;
                delete n;
                break;
            }
            else
            {
                m->next = n->next;
                n->next->prev = m;
                delete n;
                n = m->next;
            }
            size--;
        }
        else
        {
            m = n;
            n = n->next;
        }
    }
    cout << "Enum Elements have be delete, new TwoLInkedList";
}

void TwoListNode::FreMem()
{
    TwoNode *n = head;
    while (n != nullptr)
    {
        n = head->next;
        delete head;
        head = n;
    }
    cout << "TWoLInkedList is clear!\n";
}

class WildYeees
{
private:
    char *data;
public:
    WildYeees *Right = nullptr;
    WildYeees *Left = nullptr;

    WildYeees(const char *data) {
        this->data = new char[strlen(data) + 1];
        strcpy(this->data, data);
    }

    ~WildYeees() {
        delete[] data;
    }

    const char* getData() const {
        return data;
    }
};

class Tree
{
private:
    int size = 0;
public:
    WildYeees *head = nullptr;
    Tree(const char *data);
    void Add(const char *data);
    void BFS();
};

Tree::Tree(const char *data) {
    head = new WildYeees(data);
    std::cout << "Tree root created!\n";
    size++;
}

void Tree::Add(const char *data) {
    WildYeees *n = head;
    WildYeees *o = new WildYeees(data);
    while (true) {
        if (strcmp(n->getData(), data) < 0) {
            if (n->Right == nullptr) {
                n->Right = o;
                break;
            }
            else {
                n = n->Right;
            }
        }
        else if (strcmp(n->getData(), data) > 0) {
            if (n->Left == nullptr) {
                n->Left = o;
                break;
            }
            else {
                n = n->Left;
            }
        }
        else {
            delete o;
            return;
        }
    }
    size++;
}

void Tree::BFS() {
    if (head == nullptr)
        return;

    std::queue<WildYeees*> q;
    q.push(head);

    while (!q.empty()) {
        WildYeees* current = q.front();
        q.pop();

        std::cout << current->getData() << " ";

        if (current->Left != nullptr)
            q.push(current->Left);

        if (current->Right != nullptr)
            q.push(current->Right);
    }
}





int main()
{
    LinkedList ls;
    ls.push_front("ура");
    ls.push_front("Второй элемент");
    ls.printt();
    cout << endl;
    ls.Assert("добавление элемента после char");
    ls.printt();
    cout << endl;
    cout << "Unit on index = " << ls.Find(3);
    ls.empty();
    cout << "\n"
         << "Size " << ls.Siize() << endl;
    cout << "---------------------------------------------------------------------------------------------------\n";
    TwoListNode lk(5);
    lk.push_front(10);
    lk.push_front(12);
    lk.print();
    lk.del_even_elen();
    lk.print();
    lk.FreMem();
    lk.print();

    cout << "---------------------------------------------------------------------------------------------------\n";
    Tree tree("50");

    tree.Add("40");
    tree.Add("30");
    tree.Add("60");
    tree.Add("70");
    tree.BFS();

    return 0;
}
