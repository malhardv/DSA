#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    // constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }

    ~Node() {
        int value = this -> data;

        //memory free
        if(this -> next != NULL) {
            delete next;
            this -> next = NULL;
            this -> prev = NULL;
        }
        cout<<"Memory is free for the node: "<<value<<endl;
    }
};

void insertAtHead(Node* &head, int data) {
    // create a new node
    Node* temp = new Node(data);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

void insertAtEnd(Node* &head, Node* &tail, int data) {
    Node* temp = new Node(data);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
}

void insertInMiddle(Node* &head, Node* &tail, int position, int data) {

    // insertion at starting
    if(position == 1) {
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int count = 1;
    while(temp -> next != NULL) {
        temp = temp -> next;
    }

    if(position > count + 1) {
        insertAtEnd(head, tail, data);
        return;
    }

    temp = head;
    count = 1;
    while(count < position - 1) {
        temp = temp -> next;
        count++;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    nodeToInsert -> prev = temp;
    temp->next->prev = nodeToInsert;
    temp -> next = nodeToInsert;
}

void deleteNode(Node* &head, Node* &tail, int position) {
    
    // delete the first node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        delete temp;

        if(head == NULL) {
            tail = NULL;
        }
    } else {
        // deleting from any other position including the last one
        Node* curr = head;
        Node* prev = head;

        int count = 1;
        while(count < position) {
            prev = curr;
            curr = curr -> next;
            count++;
        }

        prev -> next = curr -> next;
        curr -> next -> prev = prev;

        if(curr == tail) {
            tail = prev;
        }

        curr -> next = NULL;
        curr -> prev = NULL;
        delete curr;
    }


}

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<< temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl; 
}

int getLength(Node* &head) {
    int len = 0;
    Node* temp = head;
    while(temp != NULL) {
        temp = temp -> next;
        len++;
    }
    return len;
}

int main() {

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertAtHead(head, 20);
    print(head);

    insertAtEnd(head, tail, 50);
    print(head);

    insertInMiddle(head, tail, 1, 100);
    print(head);

    deleteNode(head, tail, 2);
    print(head);

    cout<<"Length of the Doubly Linked List: "<<getLength(head)<<endl;
    cout<<"Head: "<<head -> data<<endl;
    cout<<"Tail: "<<tail -> data;
    return 0;
}