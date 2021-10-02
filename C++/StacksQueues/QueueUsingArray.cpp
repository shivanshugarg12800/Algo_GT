#include<iostream>
using namespace std;
template<typename T>
class Queue{
private:
    T *data;
    int firstindex;
    int nextindex;
    int size;
    int capacity;
public:
    Queue()
    {
        data = new T[4];
        nextindex=0;
        firstindex=-1;
        capacity=4;
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

    void enqueue(T element)                  //     in this enqueue function we have used the dynamic array
    {                                        //    approach to create a never ending queue*/
        
        if(size==capacity)
        {
            T *newdata= new T [2*capacity];
            int j=0;
            for(int i=firstindex; i<capacity;i++){
                newdata[j]=data[i];                  // we have used the firstindex as the index number to 
                j++;                                //  to save the index the first element
            }                                       // nextindex is the index to insert nextelement 
            for(int i=0; i<firstindex;i++)          
            {
                newdata[j]=data[i];
                j++;
            }
            delete []data;
            data=newdata;
            firstindex=0;
            nextindex=capacity;
            capacity=2*capacity;
        }
        data[nextindex]=element;
        nextindex=(nextindex+1)%capacity;
        if(firstindex==-1)
        {
        firstindex=0;
        }
        size++;


    }
    T dequeue(){
        if(isEmpty())
        {
            return 0;
        }
        T ans= data[firstindex];
         firstindex= (firstindex+1)%capacity;
         size--;
         if(size==0)
        {
            firstindex=-1;
            nextindex=0;
        }
        
        return ans; 
        }
       
    
    T front()
    {
        if(isEmpty())
        {
            return 0;
        }
        else
        {
            return data[firstindex];
        }
        
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