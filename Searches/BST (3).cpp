//Binary Search Tree implementation
#include<iostream>
using namespace std;
template<class T>
class BST;
template<class T>
class BSTnode
{
	T data;
	BSTnode<T> *lc,*rc;
	friend class BST<T>;
	public:
	BSTnode(T &e,BSTnode<T> *l=0,BSTnode<T> *r=0)
	{
		data=e;	lc=l;	rc=r;
	}
};
template<class T>
class BST
{
	BSTnode<T> *root;
	public:
		BST(){root=NULL;}
		void Insert(T& ele);
		void Delete(T ele);
		void Search(T ele);
		void Inorder(BSTnode<T> *);
		void Inorder(){Inorder(root);}
};
template<class T>
void BST<T>::Insert(T &ele)
{
	BSTnode<T> *pp,*p=root;
	while(p!=NULL)
	{
		pp=p;
		if(p->data<ele)
			p=p->rc;
		else if(p->data>ele)
			p=p->lc;
		else
		{
			cout<<"duplicate element's not allowed";
			return;
		}
	}
	BSTnode<T> *temp=new BSTnode<T>(ele);
	if(root==NULL)
		root=temp;
	else
	{
		if(pp->data<ele)
			pp->rc=temp;
		else
			pp->lc=temp;
	}
}
template<class T>
void BST<T>::Delete(T ele)
{
	T e;
	BSTnode<T> *p=root,*pp=NULL;
	if(root==NULL)
	{
		cout<<"\n Tree is Empty";
		return;
	}
	while(p!=NULL&&p->data!=ele)
	{
		pp=p;
		if(p->data>ele)
			p=p->lc;
		else
			p=p->rc;
	}
	if(p==NULL)
	{
		cout<<"\n Node does not exist";
		return;
	}
	e=p->data;
	if(p->lc!=NULL&&p->rc!=NULL)
	{
		BSTnode<T> *s,*ps;
		s=p->lc;ps=p;
		while(s->rc!=NULL)
		{
			ps=s;
			s=s->rc;
		}
		p->data=s->data;
		p=s;
		pp=ps;
	}
	BSTnode<T>*c;
	if(p->lc!=NULL)
		c=p->lc;
	else
		c=p->rc;
	if(p==root)
		root=c;
	else
	{
		if(pp->lc==p)
			pp->lc=c;
		else
			pp->rc=c;
	}
	cout<<e<<" node is deleted\n";
	delete p;
}
template<class T>
void BST<T>::Search(T ele)
{
	BSTnode<T> *ptr=root;
	if(root==NULL)
	{
		cout<<"\n Tree is empty";
		return;
	}
	while(ptr!=NULL)
	{
		if(ptr->data>ele)
			ptr=ptr->lc;
		else if(ptr->data<ele)
			ptr=ptr->rc;
		else
		{
			cout<<"\n Element exist";
			return;
		}
	}
	cout<<"\n Element does not exist";
}
template<class T>
void BST<T>::Inorder(BSTnode<T>* p)
{
	if(p!=NULL)
	{
		Inorder(p->lc);
		cout<<p->data<<"\t";
		Inorder(p->rc);
	}
}
int menu()
{
	int i;
	cout<<"\n 1.Insert\n 2.Delete\n3.Search\n4.inorder\n5.exit";
	cin>>i;
	return i;
}
int main()
{
	int i,ele;
	BST<int> obj;
	i=menu();
	while(i!=5)
	{
		switch(i)
		{
			case 1: cout<<"\n Enter element:";
			        cin>>ele;
			        obj.Insert(ele);break;
			case 2: cout<<"\n Enter element for delete:";
				        cin>>ele;
			        obj.Delete(ele); break;
			case 3:cout<<"\n Enter element for searching:";
			        cin>>ele;
			        obj.Search(ele);break;
			case 4:obj.Inorder();break;
		}
		i=menu();
	}
	return 0;
}
