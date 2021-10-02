#include<iostream>
using namespace std;
template<typename T>
class node{
    public:
    T data;
    node<T> * next;
    node(T data)
    {
        this->data= data;
        next=NULL;
    }
};
template<typename T>
class Queue{
    private:
         node<T> *head;
         node<T> *tail;
          int size;
    public:
    // constructor
        Queue()
        {
            head=NULL;
            tail=NULL;
            size=0;
        }
        int getsize()
        {
            return size;
        }
        bool isEmpty()
        {
            return size==0;
        }
        void enqueue(T element)
        {
            node<T> *newnode= new node<T>(element);
            if(head==NULL)
            {
                head=newnode;
                tail=newnode;
            }
            tail->next=newnode;
            tail= newnode;
            size++;
        }
        T dequeue()
        {
            if(head==NULL)
            {
                return 0;
            }
            T ans= head->data;
            head=head->next;
            size--;
            return ans;
        }
        T front()
        {
            if(head==NULL)
            {
                return 0;
            }
            return head->data;
        }
        





};
int main()
{
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    cout<< q.getsize()<<endl;
    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.front()<<endl;
    cout<< q.getsize()<<endl;
    cout<<q.isEmpty()<<endl;
}