#include <iostream>
#include <stack>
using namespace std;
template <class T>
T swap(T a,T b)
{ 
	if(a.empty()==true||b.empty()==true)
	{
		cout<<" cannot swap";
		
	}
	else
	{
		int i=0;
		T a1;
		if(a.size()>=b.size())
		{
			for(i=0;i<a.size();i++)
			{
				a1=a[i];
				a[i]=b[i];
				b[i]=a1;
			}
		}
		else
		{   for(i=0;i<=b.size();i++)
			{
				a1=b[i];
				b[i]=a[i];
				a[i]=a1;
			}
			
		}
	}
}
int main() 
{   stack <char>t1,t2;
    	char w ='a',y='z';
    	
	if(t1.empty()==true)
	{   
		for(int i=0;i<10;i++)
		{
			t1.push(w);
			w++;
		}
		
	}
	else
	{
		cout<<"stack is not empty";
	}
		 
	if(t2.empty()==true)
	{   
		for(int i=0;i<10;i++)
		{
			t2.push(y);
			--y;
		}
		
	}
	else
	{
		cout<<"stack is not empty";
	}
 
	
	cout<<"after swap"<<"\n";
	swap(t1,t2);
	while(t1.empty()!=true)
{
	cout<<t1.top();
	t1.pop();
}
cout<<"\n";
    while(t2.empty()!=true)
{
	cout<<t2.top();
	t2.pop();
}
    
 return 0;
}