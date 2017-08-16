#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, i,str[1000000]; cin>>n;
	for(i=0;i<n;i++)
	{
	cin>>str[i];}
	stack <int> s1;
	for(i=0;i<n;i++)
	{
		if(str[i]>0)
		{
			s1.push(str[i]);
		}
		else
		{
			if(!s1.empty()&&s1.top()==(str[i]*(-1)))
			{
				s1.pop();
			}
			else
			{
				s1.push(str[i]);
			}
		}
	}
	cout<<n-s1.size();
	
	
	return 0;
}