#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
}*head;

void insert(int x)
{
    node*temp = new node();
    temp->data = x;
    if(head!=NULL)
    {
        temp->next = head;
    }
    head = temp;
}
void print()
{
    node*temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp->next = next;
    }
    cout<<endl;
}

int main()
{
    node*head = NULL;
    cout<<"How many numbers?\n";
    int i, n, x;
    cin>>n;
    for(i = 0; i < n; i++)
    {
        cout<<"Enter the number: ";
        cin>>x;
        insert(x);
        print();
    }
}

