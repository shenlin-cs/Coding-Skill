#include<iostream>
#include<stack>
using namespace std;

bool isoperator(char ch)
{
	switch(ch)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return true;
	default:
		return false;
	}
}
int priority(char ch)
{
	switch(ch)
	{
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return -1;
	}
}
void infix_to_postfix(char infix[],char postfix[])
{
	stack<char> s1;
	s1.push('#');
	int i=0,j=0;
	while(infix[i]!='\0')
	{
		if(infix[i]>='0'&&infix[i]<='9')
		{
			postfix[j++]=infix[i];
		}
		else if(infix[i]=='(')
		{
			s1.push(infix[i]);
		}
		else if(infix[i]==')')
		{
			while(s1.top()!='(')
			{
				postfix[j++]=' ';
				postfix[j++]=s1.top();
				s1.pop();
			}
			s1.pop();
		}
		else if(isoperator(infix[i]))
		{
			postfix[j++]=' ';
			if(s1.empty())
			{
				s1.push(infix[i]);
			}
			else
			{
				while(priority(infix[i])<=priority(s1.top()))
				{
					postfix[j++]=s1.top();
					postfix[j++]=' ';
					s1.pop();
				}
				s1.push(infix[i]);
			}
		}
		i++;
	}
	while(s1.size())
	{
		postfix[j++]=' ';
		postfix[j++]=s1.top();
		s1.pop();
	}
	postfix[j-1]='\0';
}
int getpostfix_value(char postfix[])
{
	stack<int> s1;
	int i=0,result=0;
	int x1=0,x2=0;
	while(postfix[i]!='\0')
	{
		if(postfix[i]>='0'&&postfix[i]<='9')
		{
			int x=0;
			while(postfix[i]>='0'&&postfix[i]<='9')
			{
				x=x*10+(postfix[i]-'0');
				i++;
			}
			s1.push(x);
		}
		else if(postfix[i]==' ')
		{
			i++;
		}
		else if(postfix[i]=='+')
		{
			x1=s1.top();
			s1.pop();
			x2=s1.top();
			s1.pop();
			int temp=x2+x1;
			s1.push(temp);
			printf("%d+%d=%d\n",x2,x1,temp);
			i++;
		}
		else if(postfix[i]=='-')
		{
			x1=s1.top();
			s1.pop();
			x2=s1.top();
			s1.pop();
			int temp=x2-x1;
			s1.push(temp);
			printf("%d-%d=%d\n",x2,x1,temp);
			i++;
		}
		else if(postfix[i]=='*')
		{
			x1=s1.top();
			s1.pop();
			x2=s1.top();
			s1.pop();
			int temp=x2*x1;
			s1.push(temp);
			printf("%d*%d=%d\n",x2,x1,temp);
			i++;
		}
		else if(postfix[i]=='/')
		{
			x1=s1.top();
			s1.pop();
			x2=s1.top();
			s1.pop();
			if(x1==0){
				printf("error:³ýÊýÎª0.\n");
				exit(1);
			}
			else{
				int temp=x2/x1;
			s1.push(temp);
			printf("%d/%d=%d\n",x2,x1,temp);
			i++;
			}
		}
	}
	result=s1.top();
	return result;
}

int main(){
	char infix[50] = {0};  
    printf("Please input an expression:\n"); 
    scanf("%s", infix); 
	char postfix[1024];
	infix_to_postfix(infix,postfix);
	int result=getpostfix_value(postfix);
    printf("The result of the expression:%d\n",result);  
	return 0;
}


