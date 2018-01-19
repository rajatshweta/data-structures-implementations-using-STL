#include <iostream>
using namespace std;

class Node
{ 
   public:
	int data;
	Node * next;
	Node * prev;
};

class Deque
{  
	private:

	Node * front;
	Node * rear;
	int count;
	
	public:
	
	Deque()
	{
		front=NULL;
		rear=NULL;
		count=0;
	}
	int size()
	{
		return count;
	}
	
	bool isempty()
	{
		return count==0 ? true : false;
	}
	
	void pushfront(int i)
	{   
		
		Node * temp=new Node();
		temp->data=i;
		temp->next=NULL;
		temp->prev=NULL;
		
		if(isempty())
		{
		   	front=rear=temp;
		}
		else
		{
			temp->next=front;
			front->prev=temp;
			front=temp;
		}
		count++;
	}
	
	void pushrear(int i)
	{
		Node * temp=new Node();
		temp->data=i;
		temp->next=NULL;
		temp->prev=NULL;
		
		if(rear==NULL)
		{
			front=rear=temp;
		}
		else
		{
			temp->prev=rear;
			rear->next=temp;
			rear=temp;
		}
		
		count++;
	}
	
	void popfront()
	{
		Node * temp=front;
		if(front->next!=NULL)
		{
			front=front->next;
			front->prev=NULL;
		}
		else
		{
			front=NULL;
		}
		delete temp;
		count--;
	 
	}
	
	void poprear()
	{
		Node * temp=rear;
		if(rear->prev!=NULL)
		{
			rear=rear->prev;
			rear->next=NULL;
		}
		else
		{
			rear=NULL;
		}
		delete temp;
		count--;
	}
	
	void print()
	{ 
		Node* temp=front;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
	
	void reverseprint()
	{
		Node* temp=rear;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->prev;
		}
	}
	
	int frontele()
	{
		if(isempty())
		{
			cout<<"deque is empty";
		}
		else
		{
			return front->data;
		}
	}
	
	int rearele()
	{
		if(isempty())
		{
			cout<<"deque is empty";
		}
		else
		{
			return rear->data;
		}
	}
	
	int search(int d)
	{
		Node *temp=front;
		int y=0;
		while(temp!=NULL)
		{
			if (temp->data==d)
			{
				return y;
			}
			
			temp=temp->next;
			y++;
		}
		return 0;
	}
	
	
};


int main() {
	Deque d;
	d.pushfront(12);
	d.pushfront(444);
	d.pushrear(1);
	
	d.print();
	d.poprear();
	//d.poprear();
	
	d.print();
	cout<<d.frontele()<<" "<<d.rearele();
	cout<<d.search(12);
	
	
	return 0;
}