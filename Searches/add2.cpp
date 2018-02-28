#include<iostream>
using namespace std;

class term
{
	int coeff;
	int exp;
	term *next;
	public:
		term(float c,int e, term *ptr=NULL)
		{
			coeff=c;
			exp=e;
			next=ptr;
		}
		term(){}
	friend class polynomial;
};

class polynomial
{
	term *first,*last;
	public:

	polynomial()
	{
		first=last=NULL;
	}
	void createpoly()
	{
		int c,e;
		cout<<"\n enter coef & exp (give exp as -1 for exit):";
		cin>>c>>e;
		while(e!=-1)
		{
			term *t=new term(c,e);
			inslast(t);
			cout<<"\n enter coef & exp (give exp as -1 for exit):";
			cin>>c>>e;
		}
	}
	void display()
	{
		term *ptr=first;
		while(ptr!=NULL)
		{
			cout<<ptr->coeff<<"x^"<<ptr->exp<<" + ";
			ptr=ptr->next;
		}
	}
	polynomial add(polynomial t)
	{
		polynomial c;
		int sum,ex;
		term *a=first,*b=t.first,*s=NULL;
		while(a!=NULL && b!=NULL)
		{
			//sum=ex=0;
			if(a->exp==b->exp)
			{
				sum=a->coeff+b->coeff;
				ex=a->exp;
				a=a->next;
				b=b->next;
			}
			else if(a->exp > b->exp)
			{
				sum=a->coeff;
				ex=a->exp;
				a=a->next;
			}
			else if(a->exp < b->exp)
			{
				sum=b->coeff;
				ex=b->exp;
				b=b->next;
			}
			s=new term(sum,ex);
			c.inslast(s);
		}
		while(a!=NULL)
		{
			s=new term(a->coeff,a->exp);
			c.inslast(s);
			a=a->next;
		}

		while(b!=NULL)
		{
			s=new term(b->coeff,b->exp);
			c.inslast(s);
			b=b->next;
		}
		return c;
	}

    void inslast(term *s)
    {
            if(first==NULL)	  first=last=s;
			else   			last=last->next=s;
    }

};
int main()
{
	polynomial p1,p2;
	cout<<"\n Enter first polynomial\n";
	p1.createpoly();
	cout<<"\n Enter second polynomial\n";
	p2.createpoly();
	cout<<"\n First polynomial ....\n";
	p1.display();
	cout<<"\n second polynomial ....\n";
	p2.display();
	polynomial p3=p1.add(p2);
	cout<<"\n third polynomial ....\n";
	p3.display();
	cout<<endl;
}



