#include<iostream>
#include"LStack.h"
using namespace std;
template<class T>
class BT;
template<class T>
class BTNode
{
	friend class BT<T>;
	T ele;
	BTNode<T> *lc,*rc;
	public:
		BTNode(T e=0,BTNode<T> *l=0,BTNode<T> *r=0)
		{
			ele=e;
			lc=l;rc=r;
		}
};
template<class T>
class BT
{
	BTNode<T> *root;
	public:
		BT(){root=0;}
		void makeTree(T e,BT<T> &a,BT<T> &b)
		{
			root=new BTNode<T>(e,a.root,b.root);
			a.root=b.root=0;
		}
		void Inorder()
		{
			Inorder(root);
			cout<<"\n Height of the tree is :"<<Height(root);
		}
		void Inorder(BTNode<T> *r)
		{
			if(r)
			{
				Inorder(r->lc);
				cout<<r->ele<<"\t";
				Inorder(r->rc);
			}
		}
		int Height(BTNode<T> *r)
		{
			if(!r)
				return 0;
			int hl=Height(r->lc);
			int hr=Height(r->rc);
			if(hl>hr)
				return ++hl;
			else
				return ++hr;
		}
		void nonrecinorderiterator()
		{
			InorderIterator obj(root);
			while(1)
			{
				T temp=obj.Next();
				if(temp==0)
					return;
				cout<<temp<<"\t";
			}
		}
		class InorderIterator
		{
			LStack<BTNode<T>*> s;
			BTNode<T> *currentNode;
			public:
				InorderIterator(BTNode<T>* cn){ currentNode=cn;}
				T Next()
				{
					while(currentNode)
					{
						s.Push(currentNode);
						currentNode=currentNode->lc;
					}
					if(s.IsEmpty())
						return 0;
					currentNode=s.Pop();
					T temp=currentNode->ele;
					currentNode=currentNode->rc;
					return temp;
				}
		};
		//non-recursive  or iterative inorder traversals implementation
		void nonrecinorder()
		{
			BTNode<T> *currentNode=root;
			LStack<BTNode<T>*> s;
			while(1)
			{
			 	while(currentNode)
			        {
			                s.Push(currentNode);
			                currentNode=currentNode->lc;
			        }
			        if(s.IsEmpty())
			                return ;
			        currentNode=s.Pop();
			        cout<<currentNode->ele<<"\t";
			        currentNode=currentNode->rc;
			}
		}
};

int main()
{
BT<char> X,Y,Z,a,b,c;
X.makeTree('G',a,a);
Y.makeTree('H',b,b);
Z.makeTree('E',X,Y);
c.makeTree('D',a,a);
X.makeTree('B',c,Z);
Y.makeTree('F',a,a);
Z.makeTree('C',a,Y);
Y.makeTree('A',X,Z);
cout<<"\n inorder traversal using recursive function\n";
Y.Inorder();
cout<<"\n inorder traversal using non recursive function\n";
Y.nonrecinorder();
cout<<"\n inorder traversal using non recursive Inorder Iterator nested class of binary tree\n";
Y.nonrecinorderiterator();
return 0;
}

