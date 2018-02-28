#include<iostream>
using namespace std;
template<class T>
class MaxHeap
{
	T *h;
	int hsize,max;
	public:
		MaxHeap(int size=5)
		{
			max=size;
			hsize=0;
			h=new T[max];
		}
		void insert(T &e)
		{
			if(hsize==max)
			{
				max*=2;
				T *temp=new T[max];
				for(int i=1;i<=hsize;i++)
					temp[i]=h[i];
				delete h;
				h=temp;
			}
			int i=++hsize;
			while(i!=1&&h[i/2]<e)
			{
				h[i]=h[i/2];
				i=i/2;
			}
			h[i]=e;
		}
		T Delete()
		{
			if(isempty())
				throw "heap is empty.cannot delete";
			T lastE=h[hsize--];
			T firstE=h[1];
			int cnode=1,i=2;
			while(i<=hsize)
			{
				if(i<hsize&&h[i]<h[i+1])
					i++;
				if(lastE>=h[i])
					break;
				h[cnode]=h[i];
				cnode=i;
				i=2*i;
			}
			h[cnode]=lastE;
			return firstE;
		}
		void display()
		{
			if(isempty())
				throw "no elements.heap is empty";
			for(int i=1;i<=hsize;i++)
				cout<<h[i]<<"\t";
		}
		bool isempty()
		{
			return hsize==0;
		}

};
main()
{
	MaxHeap<int> obj(10);
	int e;
	while(1)
	{
		cout<<"\n enter elements into heap tree(-1 for exit):";
		cin>>e;
		if(e==-1)
			break;
		obj.insert(e);
	}
	cout<<"\n After insert operation heap tree is\n";
	obj.display();
	cout<<"\n Deleting elements from heap..\n";
	while(!obj.isempty())
		cout<<obj.Delete()<<"\t";
}
