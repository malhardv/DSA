#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;

        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory cleared for the node: " << value << endl;
    }
};

void insertNode(Node *&tail, int element, int data)
{
    if (tail == NULL)
    {
        // empty list
        Node *newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
        return;
    }
    else
    {
        // non empty list
        // assuming that the element is present
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }

        // element is found ---> curr is on the element found
        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node *&tail, int element)
{

    // list is empty
    if (tail == NULL)
    {
        cout << "List is already empty" << endl;
        return;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        // 1-node Linked list
        if (curr == prev)
        {
            tail = NULL;
        }
        else if (tail == curr)
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

void print(Node *&tail)
{
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

int main()
{
    Node *tail = NULL;
    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 9, 11);
    print(tail);

    insertNode(tail, 7, 21);
    print(tail);

    deleteNode(tail, 21);
    print(tail);

    deleteNode(tail, 11);
    print(tail);
    return 0;
}