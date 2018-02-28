//Heap Sort implementation
#include<iostream>
using namespace std;
template<class T>
class Hsort
{
	T *heap;
	int maxsize;
	public:
		Hsort(int size)
		{
			maxsize=size;
			heap=new T[maxsize+1];
		}
		void read();
		void display();
		void heapsort();
		void adjustH(int i,int size);
};
template<class T>
void Hsort<T>::read()
{
	cout<<"\nEnter elements:";
	for(int i=1;i<maxsize+1;i++)
		cin>>heap[i];
}
template<class T>
void Hsort<T>::display()
{
	for(int i=1;i<maxsize+1;i++)
		cout<<heap[i]<<"\t";
}
template<class T>
void Hsort<T>::heapsort()
{
	// constructing a heap tree
	 for(int i=maxsize/2;i>=1;i--)
		 adjustH(i,maxsize);
	//repeatedly replacing the root node with last node of the tree & reconstructing the tree for i-1 nodes 
	 for(int i=maxsize;i>=2;i--)
	 {
		 T temp=heap[1];
		 heap[1]=heap[i];
		 heap[i]=temp;
		 adjustH(1,i-1);
	}
}
template<class T>
void Hsort<T>::adjustH(int i,int size)
{
	int ci=2*i; //lchild of i
	while(ci<=size)
	{
		if(ci<size && heap[ci]<heap[ci+1])//  rchild exist and it larger than lchild
			ci++;
		if(heap[i]<heap[ci])
		{
			T temp=heap[i];
			heap[i]=heap[ci];
			heap[ci]=temp;
		}
		i=ci;
		ci=2*i;
	}
}
int main()
{
	int n;
	cout<<"\n Enter number of elements u want to sort:";
	cin>>n;
	Hsort<int> obj(n);
	obj.read();
	cout<<"\nBefore sorting:\n";
	obj.display();
	obj.heapsort();
	cout<<"\nAfter sorting:\n";
	obj.display();
	return 0;
}

