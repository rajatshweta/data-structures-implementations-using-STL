#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack <char> s1;
	char w ='a';
	if(s1.empty()==true)
	{   
		for(int i=0;i<10;i++)
		{
			s1.push(w);
			w++;
		}
		
	}
	else
	{
		
cout<<"stack is empty";	}
cout<<s1.size()<<"\n";
while(s1.empty()!=true)
{
	cout<<s1.top();
	s1.pop();
}
	return 0;
}