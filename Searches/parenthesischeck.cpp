// Implementation of parenthesis check








































#include"AStack.h"

void checkparen(char *a)
{
	AStack<char> s;
	char ch;
	int valid=1;
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i]=='(')
  			s.Push(a[i]);
		else if(a[i]==')')
		{
			if(s.IsEmpty())
			{
				cout<<"\n More number of right parenthesis\n";
				return;
			}
			else
			{
				ch=s.Pop();
				
			}
		}
	}
	if(!s.IsEmpty())
		valid=0;
	if(valid==1)
		cout<<"\n Expresion is valid";
	else
		cout<<"\n Expression id invalid";
}

int main()
{
	char e[20];
	cout<<"\n Enter the expression:";
	cin>>e;
	checkparen(e);
	return 0;
}
