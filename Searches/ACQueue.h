#include<iostream>
using namespace std;
template<class T>
class ACQueue
{
    T *q;
    int front,rear,max;
    public:
    ACQueue(int size)
    {
        if(size<0)
                    throw "negative size for the array is not allowed";
        max=size;
        q=new T[max];
        front=rear=0;
    }
    ~ACQueue(){ delete []q;}
    bool IsEmpty() const
    {
        return rear==front;
    }
    bool IsFull() const
    {
        if((rear+1)%max==front)
        return true;
        else
        return false;
    }
    T First()
    {
        if(IsEmpty())
            throw"Queue is empty.no first element";
        return q[(front+1)%max];
    }
    T Last()
    {
    if(IsEmpty())
        throw"Queue is empty.no last element";
        else
    return q[rear];
    }
    void Insert(T x);
    T Delete();
    void Display();
};

template<class T>
void ACQueue<T>::Insert(T x)
{
    if(IsFull())
    {
         T *nq=new T[2*max];
         int j=0;
         if(front>rear)
         {
            for(int i=(front+1)%max;i<max;i++,j++)
                nq[j]=q[i];
            for(int i=0;i<=rear;i++,j++)
                nq[j]=q[i];
        }
        else
        {
            for(int i=(front+1)%max;i<=rear;i++,j++)
            nq[j]=q[i];
        }
        front=2*max-1;
        rear=max-2;
        max=max*2;
        delete[]q;
        q=nq;
    }
    rear=(rear+1)%max;
    q[rear]=x;
}

template<class T>
T ACQueue<T>::Delete()
{
    if(IsEmpty())
    throw"QUEUE IS UNDERFLOW.no delete";
    front=(front+1)%max;
    cout<<"\n f="<<front<<"\tr="<<rear<<endl;
    return q[front];
}

template<class T>
void ACQueue<T>::Display()
{
    if(IsEmpty())
        throw"QUEUE IS UNDERFLOW.no elements";
    if(front>rear&&front!=max-1)
    {
        for(int i=(front+1)%max;i<max;i++)
            cout<<q[i]<<"\t";
        for(int i=0;i<=rear;i++)
            cout<<q[i]<<"\t";
    }
    else
    {
        for(int i=(front+1)%max;i<=rear;i++)
            cout<<q[i]<<"\t";
    }
}
