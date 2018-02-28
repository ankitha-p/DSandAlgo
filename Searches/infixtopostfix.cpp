#include"AStack.h"
#include<ctype.h>
int pred(char c)
{
	switch(c)
	{
		case'^':return 5;
		case'*':
		case'/':
		case'%':return 4;
		case'+':
		case'-':return 3;
		default: return 2;
	}
}
void InfixToPost(char *e)
{
	AStack<char> obj(30);
	char post[30];
	int j=0;
	obj.Push('#');

for(int i=0;e[i]!='\0';i++)
{
	if(isalpha(e[i]))
		post[j++]=e[i];
	else if(e[i]=='(')
		obj.Push(e[i]);
	else if(e[i]==')')
	{
		while(obj.TopElement()!='(')
			 post[j++]=obj.Pop();
		obj.Pop();
	}
	else
	{
		while(pred(e[i])<=pred(obj.TopElement()))
			post[j++]=obj.Pop();
		obj.Push(e[i]);
	}
}
while(obj.TopElement()!='#')
	post[j++]=obj.Pop();

post[j]='\0';

cout<<"\n Postfix expression is :"<<post<<endl;
}

int main()
{
	char e[20];
	cout<<"\n Enter Infix expression:";
	cin>>e;
	InfixToPost(e);
	return 0;
}

