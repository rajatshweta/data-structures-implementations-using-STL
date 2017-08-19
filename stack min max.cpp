#include <iostream>
#include <stack>
using namespace std;

struct st
{
  stack <int> s1,s2,s3;
  int minimum;
  int maximum;
  
  int peek()
  {
  	if(s1.empty())
  	{
  		cout<<"stack is empty";
  	}
  	else
  	{
  		return s1.top();
  	}
  }
  
  void pushh(int a)
  {
  	if(s1.empty())
  	{
  		s1.push(a);
  		s2.push(a);
  		s3.push(a);
  	}
  	else
  	{   
  		if(a>=s2.top())
  		{
  			s1.push(a);
  			s2.push(s2.top());
  			
  		} else { s1.push(a); s2.push(a); }
  		
  		if(a<=s3.top())
  		{
  			s3.push(s3.top());
  		}
  		else { s3.push(a); }
  	}
  }
  
  void pop()
  {  
  	if(!s1.empty())
  	{
  	s1.pop();
  	s2.pop();
  	s3.pop();
  	}
  	else
  	{
  		cout<<"stack is empty";
  	}
  }
  
  int getmin()
  {
  	return s2.top();
  	
  }
  int getmax()
  {
  	return s3.top();
  }
  
  
  

};

int main() {
	int n,i,l;
	cin>>n;
	st stack1;
	for(i=0;i<n;i++)
	{
	cin>>l;
	stack1.pushh(l);
	}
	stack1.pop();
	stack1.pop();
	stack1.pop();
	cout<<stack1.getmin()<<" "<<stack1.getmax()<<" ";
	
	 
	
	
	return 0;
}