#include<iostream>

using namespace std;

class Link
{      public:
	struct Node
	{
		int data;
		Node* next;
		Node(int data, Node* next)
		  : data(data),next(next){}
	};
	
	Node * head;
	Node * tail;
	
	Link():
	   head(nullptr)
	   ,tail(nullptr)
	   {}
	   
	~Link ()
              {
                   Node* tmp;
                   for(;head;head = tmp)
                     {
                          tmp = head->next;
                          delete head;
                     }
                   //delete tail;
              }
    
            void append(int data);
            void insertathead(int data);
            void insertbw(Node * a,int data);
            void print();
            void rprint(Node * head);
            Node * gethead(){ return head;}
            Node * gettail(){ return tail;}
            
            Node * search(int val)
            { 
	   Node * temp=head;
	   while(temp)
	     {
		if(temp->data==val)
		{
			return temp;
		}
		else
		{
			temp=temp->next;
		}
	     }
            }
            
            void del(Node * beforedel);
            void popfront();
            int front()
            {
            	if(head==NULL){ cout<<"underflow!";}
            	else
            	{
            		return head->data;
            	}
            }
            
            int back()
            {
            	if(tail==NULL){ cout<<"underflow"; }
            	{
            		return tail->data;
            	}
            }
            
            void rreverse(Node * p)
            {
            	if(p->next==NULL)
            	{
            		head=p;
            		return;
            	}
            	rreverse(p->next);
            	Node* q=p->next;
            	q->next=p;
            	p->next=NULL;
            }
            
            void reverse()
            {
            	Node * prev,*curr,*nexxt;
            	curr=head;
            	tail=head;
            	prev=NULL;
            	while(curr!=NULL)
            	{
            		nexxt=curr->next;
            		curr->next=prev;
            		prev=curr;
            		curr=nexxt;
            	}
            	head=prev;
            	
            }
            
            bool isempty()
            {
            	if(head==NULL)
            	{
            		return true;
            	}
            	else
            	{
            		return false;
            	}
            }
};

void Link:: print()
 {
 	Node * e=head;
 	while(e)
 	{
 		cout<<e->data<<" ";
 		e=e->next;
 	}
	
 }
 
void Link:: rprint(Node * head)
 {
 	Node * e =head;
 	if(!e)
 	{  
 		return;
 	}
 	cout<<e->data<<" ";
 	rprint(e->next);
 	
 }
 
void Link :: insertathead(int data)
{
	if (head==NULL)
	{
		Node * temp=new Node(data,NULL);
		tail=temp;
		head=temp;
	}
	else
	{
		head = new Node(data, head);
	}
}

void Link :: append(int data)
{
	Node * temp=new Node(data,NULL);
	if (head==NULL)
	{
		tail=temp;
		head=temp;
	}
	else
	{
		tail->next=temp;
		tail=tail->next;
	}
}

void Link:: insertbw (Node * a,int data)
{
      Node * temp= new Node(data,NULL);
      temp->next=a->next;
      a->next=temp;
}

void Link:: del(Node * beforedel)
{
   Node * temp=beforedel->next;
   beforedel->next=temp->next;
   delete temp;
   
}

void Link:: popfront()
{
	Node * temp=head;
	head=head->next;
	delete temp;
}


 

int main ()
{
  Link l1;
  l1.append(1);
  l1.append(2);
  l1.append(3);
  l1.reverse();
  l1.rprint(l1.gethead());
  cout<<l1.back();
  
	
return 0;	
}