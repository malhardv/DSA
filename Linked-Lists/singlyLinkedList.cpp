#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for the node with data: " << value << endl;
    }
};

void InsertAtHead(Node *&head, int d)
{
    // create a new node first
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node *&tail, int d)
{
    // create a new node
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtMiddle(Node *&head, Node *&tail, int position, int d)
{

    // if inserting at start
    if (position == 1)
    {
        InsertAtHead(head, d);
        return;
    }

    int count = 1;
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (position > count + 1)
    { // If position is greater than the list size
        InsertAtTail(tail, d);
        return;
    }

    // traverse to position
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    // create new node
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(Node *&head, Node *&tail, int position)
{

    // deleting the first position
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;

        if (head == NULL)
        {
            tail = NULL;
        }
    }
    else
    {
        // deleting any middle or last node
        Node *curr = head;
        Node *prev = NULL;

        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;

        if (curr == tail)
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

bool detectLoop(Node* &head)
{
    if (head == NULL)
    {
        return false;
    }

    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        // cycle exists
        if (visited[temp] == true)
        {
            cout<<"Loop starts from: "<<temp -> data<<endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);

    InsertAtHead(head, 100);
    print(head);

    InsertAtHead(head, 15);
    print(head);

    InsertAtTail(tail, 200);
    print(head);

    insertAtMiddle(head, tail, 5, 14);
    print(head);

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    print(head);
    tail->next = head->next;

    bool loopExist = detectLoop(head);
    if (loopExist)
    {
        cout << "Loop EXISTS in the Linked List.";
    }
    else
    {
        cout << "No Loop in the Linked List.";
    }

    return 0;
}