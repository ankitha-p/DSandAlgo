#include<iostream>
using namespace std;
class poly;
class Term
{
	friend class poly;
	int coef,exp;
};
class poly
{
	Term *ta;
	int maxsize,nt;
	public:
	poly(int ms=1,int n=0)
	{
		maxsize=ms;nt=n;
		ta=new Term[maxsize];
	}
	void create();
	poly add(poly);
	void display();
	void attach(const int,const int);	
};
void poly::create()
{
	for(int i=0;i<nt;i++)
	{
		cout<<"\nEnter the coefficient & exponent :";
		cin>>ta[i].coef;
		cin>>ta[i].exp;
	}
}
void poly::display()
{
	for(int i=0;i<nt;i++)
	{
		cout<<ta[i].coef<<"X^"<<ta[i].exp;
		if(i!=(nt-1))
			cout<<" + ";
	}
}
poly poly::add(poly b)
{
	int apos=0,bpos=0;
	poly c;
	while((apos<nt)&&(bpos<b.nt))
	{
		if(ta[apos].exp==b.ta[bpos].exp)
		{	
			int t=ta[apos].coef + b.ta[bpos].coef;
			if(t)
				c.attach(t,ta[apos].exp);
			apos++;bpos++;
		}
		else if(ta[apos].exp<b.ta[bpos].exp)
		{
			c.attach(b.ta[bpos].coef,b.ta[bpos].exp);
			bpos++;
		}
		else
		{
			c.attach(ta[apos].coef,ta[apos].exp);
			apos++;
		}
	}
	for(;apos<nt;apos++)
		c.attach(ta[apos].coef,ta[apos].exp);
	for(;bpos<b.nt;bpos++)
		c.attach(b.ta[bpos].coef,b.ta[bpos].exp);
	return c;
}
void poly::attach(const int c,const int e)
{
	if(nt==maxsize)
	{
		maxsize*=2;
		Term *temp=new Term[maxsize];
		for(int i=0;i<nt;i++)
		temp[i]=ta[i];
		delete []ta;
		ta=temp;
	}
	ta[nt].coef=c;ta[nt].exp=e;
	nt++;
}
main()
{
	poly p1(3,3),p2(4,4);
	poly p3;
	cout<<"\n Enter first polynomial:";
	p1.create();
	cout<<"\n Enter second polynomial:";
	p2.create();
	p3=p1.add(p2);
	cout<<"\nfirst polynomial is.....\n";
	p1.display();
	cout<<"\nsecond polynomial is.....\n";
	p2.display();
	cout<<"\nthird polynomial is.....\n";
	p3.display();
	cout<<endl;
}
