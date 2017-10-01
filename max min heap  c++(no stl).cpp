#include <iostream>
#include<climits>

using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

class maxheap
 {
    int *a;
    int capac,hs;
    
  public:
   maxheap(int capac);
   
   int getroot(int i)  { return (i-1)/2; }
   
   int leftnode(int i) { return 2*i+1; }
   
   int rightnode(int i) { return 2*i+2; }
   
   int getmax(){  return (hs==0)?-1:a[0];}
   
   void heapify(int);
   int extractmax();
   void decreasekey(int i,int new_val);
   void deletekey(int i);
   void insert(int k);
   void print();
   int search(int val);
	
 };

int maxheap:: search(int val)
 { int s=-1;
   for(int i=0;i<hs;i++) { if(a[i]==val){ s=i; break;} } 
   return s;
 }

void maxheap::print()
 {
    for(int i=0;i<hs;i++){ cout<<a[i]<<" "; }
 }
 
void maxheap::deletekey(int i)
 {
   decreasekey(i, INT_MAX);
   extractmax();
 }


void maxheap:: insert(int k)
{   
  if(hs==capac){ return;}
   
      hs++;
      int l=hs-1;
      a[l]=k;
  
  while(l!=0 && a[getroot(l)]<a[l])
  {
    swap(&a[l],&a[getroot(l)]);
    l=getroot(l);
  }
}



maxheap::maxheap(int cap)
 {
   hs=0;
   capac=cap;
   a=new int[cap];
 }

void maxheap:: decreasekey(int i,int new_val)
{
    a[i]=new_val;
    while(i!=0 && a[getroot(i)]<a[i])
    {
      swap(&a[i],&a[getroot(i)]);
      i=getroot(i);
    }
}

int maxheap:: extractmax()
 {
     if(hs<=0){ return INT_MAX; }
     if(hs==1){ hs--; return a[0]; }
     
     int root =a[0];
     a[0]=a[hs-1];
     hs--;
     heapify(0);
     return root;
 }

void maxheap:: heapify(int i)
{
    int l=leftnode(i);
    int r=rightnode(i);
    int largest =i;
    
    if(l<hs && a[l]>a[largest])
    {
        largest=l;
    }
    if(r<hs && a[r]>a[largest]  )
    {
      largest=r;
    }
    if(largest!=i)
    {
      swap(&a[i],&a[largest]);
      heapify(largest);
    }
}


class minheap
 {
    int *a;
    int capac,hs;
    
  public:
   minheap(int capac);
   
   int getroot(int i)  { return (i-1)/2; }
   
   int leftnode(int i) { return 2*i+1; }
   
   int rightnode(int i) { return 2*i+2; }
   
   int getmin(){ return a[0];}
   
   void heapify(int);
   int extractmin(); 
   void decreasekey(int i,int new_val);
   void deletekey(int i);
   void insert(int k);
   void print();
   int search(int val);	
 };

 

void minheap::print()
 {
    for(int i=0;i<hs;i++) { cout<<a[i]<<" "; }
 }
 
 
void minheap:: deletekey(int i)
 {
   decreasekey(i,INT_MIN);
   extractmin();
 }

 void minheap::insert(int k)
 {
    if(hs==capac){ return; }
     hs++;
     int i=hs-1;
     a[i]=k;
     
     while(i!=0 && a[getroot(i)]>a[i])
     {
     	swap(&a[i],&a[getroot(i)]);
     	i=getroot(i);
     }
 }
 
 int minheap:: extractmin()
 {
     if(hs<=0){ return INT_MAX; }
     if(hs==1){ hs--; return a[0]; }
     
     int root =a[0];
     a[0]=a[hs-1];
     hs--;
     heapify(0);
     return root;
 }
 
 
 void minheap:: decreasekey(int i, int n)
 {
   a[i]=n;
   while(i!=0 && a[getroot(i)]>a[i])
   {
      swap(&a[i],&a[getroot(i)]);
      i=getroot(i);
   }
 }

minheap:: minheap(int cap)
{
  hs=0;
  capac=cap;
  a=new int[cap];
}

void minheap:: heapify(int i)
{
  int l=leftnode(i);
  int r=rightnode(i);
  int small=i;
  if(l<hs && a[l]<a[i])
  { small=l; }
  
    if(r<hs && a[r]<a[small])
  { small=r; }
  
  if(small!=i)
  {
     swap(&a[i],&a[small]);
     heapify(small);
  }
}

int minheap:: search(int val)
{ int s=-1;
  for(int i=0;i<hs;i++) { if(a[i]==val){ s=i; break;}} 
  return s;
}

int main() {
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	minheap hn(100001); maxheap hm(100001);
	
	int q,l,m,n,z,x; cin>>q;
	
	while(q--)
	{   cin>>l;
	   if(l==1){ cin>>m; hn.insert(m); hm.insert(m);}
	   
	   if(l==2)
	   {  cin>>m;
	      z=hm.search(m);
	      x=hn.search(m);
	      if(z==-1)
	      {
	      cout<<"-1"<<"\n";	
	      }
	      else
	      {
	      	hm.deletekey(z);
	      	hn.deletekey(x);
	      } 
	      }
	      
	   if(l==3){ cout<<hm.getmax()<<"\n";}
	   
	   if(l==4){ cout<<hn.getmin()<<"\n";}
		
	}
 
 
    
    return 0;

}