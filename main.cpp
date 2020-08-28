#include<iostream>
#include<fstream>
using namespace std;
bool x=false;
template<typename T>
class stack
{
	
	public:
	int top;
	 T *Data;
    int capacity;

	

		stack()
		{
		    Data=new T[100];
			top=-1;
			capacity=100;
			
			
		}
	
		void push(T n)
		{
		  if(top!=capacity)
		  {
		  
		  top++;
	      Data[top]=n;
	      }else
	      cout<<"\n\nStack is full!!";
			
		}
		T pop()
        {
        	if(top!=-1)
        	{
        		
			T var;
        	var=Data[top];
        	top--;
        	return var;
           }
           ;
        
        	
		}
		bool isempty()
		{
			if(top==-1)
            return true;
			return false;			
			
		}
	
	
			
	};
template <typename T>
class Queue;

template <typename T>
class Node
{
	public:
	T data;
	Node<T>*next;

	 

		
	Node()
	{
		data=0;
		next=0;
	}
  Node(const T n,Node *ptr=0)
  {
  	   data=n;
  	   next=ptr;

  }
  
friend class Queue<T>;
};

template <typename T>
class Queue
{
	
	Node<T> *front;
	Node<T> *rear;
	int count;
	
	public:
		
	Queue()
	{
	   front=rear=0;
	   count=0;
	}
	
	void enqueue(T n)
	{
		if(isempty())
		{
			count++;
			Node<T>*newptr=new Node<T>(n);
			rear=front=newptr;
			
			
		}
		else
		{
			count++;
			Node<T>*newptr=new Node<T>(n);
			rear->next=newptr;
			rear=newptr;
		}
		
		
		
		
	}
T Dequeue()
	{
		T var;
		
		if(isempty())
		{
			cout<<"\nQueue is empty\n";
		
		}
    else
	{
		count--;
	   Node<T>*temp;
	   temp=front;
	   front=front->next;
	   var=temp->data;
	   delete temp;
	   temp=0;	
	   if(front==0)
	   rear=0;
	   return var;
		
	}		
}

 T Front()
 {
 	if(!(isempty()))
 	{
 	   return front->data;	
 		
	}
 	
 	
 	
 }


void print()
{
			if(isempty())
		{
			cout<<"\nQueue is empty\n";
			return;
	     }
	Node<T>*temp=front;
	
	while(temp->next!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
		
		
	}
		cout<<temp->data<<endl;
	
	
	
	
	
}
	bool isempty()
	{
		if(front==0&&rear==0)
		return true;
		else 
		return false;
	}
	void Delete_negatives()
{
	Node<T>*temp=front,*prev=front;

   
	while(temp->next!=NULL)
	{
	  
	  if(front->data<0)
     {
     
     	temp=front;
     	front=front->next;
     	delete temp;
     	temp=front;
     	prev=front;
     }
     else if(temp->data<0)
     {
     	
     	Node<T>* t=temp;
     	temp=prev->next=temp->next;
        delete t;
		t=0;     	
     	
     	
	}
	else
	{
	 
	prev=temp;
	temp=temp->next;  
     }
}
	if(temp->data<0)
	{
		prev->next=0;
		delete temp;
		temp=0;
		
	}
	
}
	
  int get_count()
  {
  	return count;
  }
	
};
template <typename T>
class AVL;
template<typename T>

class BTnode
{
	T data;
	BTnode<T> *left;
	BTnode<T>*right;
	int bf;
	
	
	public:
	
	BTnode(T d,BTnode<T>*ptr1=0,BTnode<T>*ptr2=0,int n=0)
	{
		data=d;
	    left=ptr1;
	    right=ptr2;
	    bf=n;

		
    }
 
	
	friend class AVL<T>;
	
	};

class interval
{
  private:
  
  int start_time;
  int duration;
  int ctime;
  int end_time;
  bool conflict;
  
  public:
  interval(int a=0,int b=0,int c=0)
  {
  	start_time=a;
  	duration=b;
  	ctime=c;
  	end_time=a+b+c;
  	conflict=false;
  	
  }
  void print(ofstream &writefile)
  {
    cout<<"("<<start_time<<","<<duration<<","<<ctime<<")"<<endl;
    writefile<<start_time<<" "<<duration<<" "<<ctime<<endl;
  }	
  int get_start_time()
  {
  	 return start_time;
  }
  int get_duration()
  {
  	 return duration;
  }
    int get_ctime()
  {
      return ctime;
  }
     int get_end_time()
  {
      return end_time;
  }
  void set_conflict(bool x)
  {
  	conflict=x;
  }
  bool get_conflict()
  {
  	return conflict;
  }
 
};	
	
template<typename T>
class AVL
{
	private:
		BTnode<T>*root;
	
		
		public:
			
		AVL(BTnode<T>*ptr=0)
		{
		
		   root=ptr;	
		}
		

   BTnode<T>* insert(T &d,BTnode<T>*current)
   {


   	  if(current==NULL)
   	  {

   	    current=new BTnode<T>(d);
   	    return current;
		
   	  	
	  }
	  else if(d.get_start_time()<=current->data.get_start_time())
	  {
	  	
	  	current->left=insert(d,current->left);
	  }
	  else if(d.get_start_time()>current->data.get_start_time())
	  current->right=insert(d,current->right);

	  
	 
	  current->bf=(height(current->left)-height(current->right));
	  
	
	  if(current->bf>1 || current->bf<-1 )
	  {
	  	 
	  	 
		  if(current->right!=NULL)	
	  	  if(check(current->right->right,d))  //for right right case
	  	  {
	  	  		 	

	  	  	  BTnode<T>*B=current->right;
	  	  	  
	  	  	  if(B->left!=NULL)
	  	  	  {
	  	  	      BTnode<T>*temp=B->left;
				  B->left=current;
				  current->right=temp;	
				   current->bf=(height(current->left)-height(current->right));
				  current=B;
	  	  	  	
			  }
			  else
			  {
			   B->left=current;
			   current->right=0;
			   current->bf=(height(current->left)-height(current->right));
			  
			   current=B;
			  }
			current->bf=(height(current->left)-height(current->right));
			 x=false;
			    return current;
	  	        	
	  	   }
	  	   
		  
	  	if(current->left!=NULL)
	  	if(check(current->left->left,d))  //for left left case
	  	  {
	  
	  	  	  BTnode<T>*B=current->left;
	  	  	  
	  	  	  if(B->right!=NULL)
	  	  	  {
	  	  	      BTnode<T>*temp=B->right;
				  B->right=current;
				  current->left=temp;	
				   current->bf=(height(current->left)-height(current->right));
				   current=B; 
	  	  	  	
			  }
			  else
			  {
			   B->right=current;
			   current->left=0;
			   current->bf=(height(current->left)-height(current->right));
			   current=B; 
			  }
			current->bf=(height(current->left)-height(current->right));
			x=false;
		   return current;
	  	}
	  	if(current->left!=NULL)//LR case
	  	if(current->left->right!=NULL)
	  	if(check(current->left->right,d))
	  	{
	  		
	  		BTnode<T>*A=current;
	  		BTnode<T>*B=current->left;
	  		BTnode<T>*C=current->left->right;
	  	  if(C->left!=NULL)
	  	  B->right=C->left;
		  else
		  B->right=0;
		  
		  if(C->right!=NULL)
	  	  A->left=C->right;
		  else
		  A->left=0;
	  		
	  		C->left=B;
	  		C->right=A;
	  	
	  		A->bf=(height(A->left)-height(A->right));
	  		B->bf=(height(B->left)-height(B->right));
	  		C->bf=(height(C->left)-height(C->right));
	  		current=C;
	  		
	  		x=false;
	  	     return current;
		}
		if(current->right!=NULL)//RL case
	  	if(current->right->left!=NULL)
	  	if(check(current->right->left,d))
	  	{
	 
	  		BTnode<T>*A=current;
	  		BTnode<T>*B=current->right;
	  		BTnode<T>*C=current->right->left;
	  	  
			  if(C->left!=NULL)
		  {
	  	  
	  	  A->right=C->left;
		  }
		  else
		  A->right=0;
		  
		  if(C->right!=NULL)
	  	  B->left=C->right;
		  else
		  B->left=0;
	  		
	  		
	  		C->left=A;
	  		C->right=B;
	  	
	  	
	  		A->bf=(height(A->left)-height(A->right));
	  		B->bf=(height(B->left)-height(B->right));
	  		C->bf=(height(C->left)-height(C->right));
	  		current=C;
	  	
	  		x=false;
	  		  return current;
		}
       
	}
		
	  	else
	  	return current;
	  	
	  	
	  	
	
	}



	bool confliction(BTnode<T>*current,T &d)
	{ 
		if((d.get_start_time()>current->data.get_start_time()&&d.get_start_time()<current->data.get_end_time())||d.get_start_time()==current->data.get_start_time())
		 return true;
		 else if(d.get_start_time()<current->data.get_start_time()&&d.get_end_time()>current->data.get_start_time())
		 return true;
		 else 
		 return false;
	}
	void check_conflict(T &d,BTnode<T>*current)
    {
    	
    	if(current==0)
    	return;
   
    if(confliction(current,d))
    {
    	d.set_conflict(true);
         return;
        
    
    }
    else if(confliction(current,d))
    {
        d.set_conflict(true);
   
    	return;
    
	}
    check_conflict(d,current->left);
    check_conflict(d,current->right);
		
    	
    	
	}
	void insert(T &d)
	{	

	    check_conflict(d,root);
	    if(d.get_conflict()==false)
		root=insert(d,root);
		
		
	}
	void insert1(T&d)
	{
		root=insert(d,root);
	}
	
	bool check(BTnode<T>*current,T d)
	{


	  	if(current==NULL)
		{
		  return x;
		}
		else if(d.get_start_time()==current->data.get_start_time())
		{
			x=true;
			return x;
		}
		else if(d.get_start_time()<current->data.get_start_time())
		check(current->left,d);
		else
		check(current->right,d);
}
  
  
  
  
  
  
  void BFS_print()
  {
  Queue<BTnode<T>*> q1;	
	BTnode<T>*temp;
	if(root!=NULL)
	q1.enqueue(root);
	
	while((!q1.isempty()))
	{
	  temp=q1.Dequeue();
	  if(temp!=NULL)
	      cout<<"("<<temp->data.get_start_time()<<","<<temp->data.get_duration()<<","<<temp->data.get_ctime()<<")"<<temp->data.get_end_time()<<endl;	
	  //cout<<"bf:"<<temp->bf<<endl;
	  if(temp->left!=NULL)
	  q1.enqueue(temp->left);
	  if(temp->right!=NULL)
	  q1.enqueue(temp->right);	
    }
 }
 void inorder_print(BTnode<T>*temp,ofstream &writefile)
 {
 	 if(temp==NULL)
 	 return;
 	 
 	inorder_print(temp->left,writefile);
 	cout<<"("<<temp->data.get_start_time()<<","<<temp->data.get_duration()<<","<<temp->data.get_ctime()<<")"<<endl;
 	writefile<<temp->data.get_start_time()<<" "<<temp->data.get_duration()<<" "<<temp->data.get_ctime()<<endl;
	inorder_print(temp->right,writefile)  ;
 	
 	
 }
 
 BTnode<T>* get_root()
 {
 	return root;
 }

 
 
 int height(BTnode<T>*current)
{
	
	static int righth;
	static int lefth;
	
	if(current==NULL)
	{
		
		return -1;
		
		
	}
	
	lefth+=height(current->left);
	righth+=height(current->right);
	
	return max(height(current->left),height(current->right))+1;
	
	
}
int max(int d1,int d2)
{
	
	if(d1<d2)
	return d2;
	else
	return d1;
}
	 BTnode<T>* findmin(BTnode<T>*current)
 {
 	
 	while(current->left!=NULL)
 	{
 		
 		current=current->left;
 	}
 	return current;
}
 BTnode<T>* findmax(BTnode<T>*current)
 {
 	
 	
 	while(current->right!=NULL)
 	{
 		
 		current=current->right;
 	}
 	return current;
}
BTnode<T>* Delete(BTnode<T>*current,T &n)
{


	if(current==0)
	return current;
	
	else if(n.get_start_time()<current->data.get_start_time())
	current->left=Delete(current->left,n);
	else if(n.get_start_time()>current->data.get_start_time())
	current->right=Delete(current->right,n);
	else
	{
		
		
		if(current->left==NULL&&current->right==NULL)  //handling of case 1 if both childs are null
		{
		
			delete current;
			current=0;
		}
		else if(current->left==NULL)  //handling of case 2 if one child is null
		{
		
			BTnode<T>*temp=current;
			current=current->right;
			delete temp;
			temp=0;
		}
			else if(current->right==NULL)
		{
			BTnode<T>*temp=current;
			current=current->left;
			delete temp;
			temp=0;
		}
		else //handling of case 3 if both childs are null by reducing to case 1 and case 2
		    
		     
		     
		{
	
			BTnode<T>*temp=findmin(current->right);
			current->data=temp->data;
			
		    	
			current->right=Delete(current->right,temp->data);
		}
	
    }
    
         if(current==0)
         return current;
		
		current->bf=(height(current->left)-height(current->right));
	
		if(current->bf>1)
		{

			current->left->bf=(height(current->left->left)-height(current->left->right));
			if(current->left->bf>=0)//left left
			{
				
	  	  	  BTnode<T>*B=current->left;
	  	  	  
	  	  	  if(B->right!=NULL)
	  	  	  {
	  	  	      BTnode<T>*temp=B->right;
				  B->right=current;
				  current->left=temp;	
				   current->bf=(height(current->left)-height(current->right));
				   current=B; 
	  	  	  	
			  }
			  else
			  {
			   B->right=current;
			   current->left=0;
			   current->bf=(height(current->left)-height(current->right));
			   current=B; 
			  }
			current->bf=(height(current->left)-height(current->right));
				
			}
			else //left right
			{

			BTnode<T>*A=current;
	  		BTnode<T>*B=current->left;
	  		BTnode<T>*C=current->left->right;
	  	  
		 if(C->left!=NULL)
	  	  B->right=C->left;
		  else
		  B->right=0;
		  
		  if(C->right!=NULL)
	  	  A->left=C->right;
		  else
		  A->left=0;
		  
	  		C->left=B;
	  		C->right=A;
	  	
	  	  	
	  		A->bf=(height(A->left)-height(A->right));
	  		B->bf=(height(B->left)-height(B->right));
	  		C->bf=(height(C->left)-height(C->right));
	  		current=C;

			}
			
			
		}
		else if(current->bf<-1)
		{
				
			 
			current->right->bf=(height(current->right->left)-height(current->right->right));
			if(current->right->bf<=0)//RR
			{
				
	  	  	  BTnode<T>*B=current->right;
	  	  	  
	  	  	  if(B->left!=NULL)
	  	  	  {
	  	  	  	;
	  	  	      BTnode<T>*temp=B->left;
				  B->left=current;
				  current->right=temp;	
				   current->bf=(height(current->left)-height(current->right));
				  current=B;
	  	  	  	
			  }
			  else
			  {
			   B->left=current;
			   current->right=0;
			   current->bf=(height(current->left)-height(current->right));
			 
			   current=B;
			  }
			  
			current->bf=(height(current->left)-height(current->right));
			
			}
			else //RL
			{
			
	  		BTnode<T>*A=current;
	  		BTnode<T>*B=current->right;
	  		BTnode<T>*C=current->right->left;
	  		  
		  if(C->left!=NULL)
		  {
	  	  
	  	  A->right=C->left;
		  }
		  else
		  A->right=0;
		  
		  if(C->right!=NULL)
	  	  B->left=C->right;
		  else
		  B->left=0;
	  		
	  		
	  		C->left=A;
	  		C->right=B;
	  	
	  		  	
	  		A->bf=(height(A->left)-height(A->right));
	  		B->bf=(height(B->left)-height(B->right));
	  		C->bf=(height(C->left)-height(C->right));
	  		current=C;
			}
			
		}
	return current;
}
	
void Delete(T &d)
{
 this-> root=Delete(root,d);	
}	
void check_silent (interval *t,int size) 
{ 
interval temp;
stack <BTnode<T>*> st; 
BTnode<T>*current=root;
BTnode<T>*prev=NULL;
   while (current!= NULL || !(st.isempty())) 
    {
	while (current !=0) 
        {
         st.push(current);
         current = current->left; 
		} 
  current = st.pop();

for(int i=0;i<size;i++)
{
	if(confliction(current,t[i]))
	{
		if(prev!=NULL)
		if(prev->data.get_end_time()<=t[i].get_start_time())
		if(t[i].get_start_time()-prev->data.get_end_time()<current->data.get_start_time()-prev->data.get_end_time())
     	{
		//	cout<<prev->data.get_start_time()<<" "<<current->data.get_start_time()<<" "<<t[i].get_start_time()<<endl; 
     		temp=current->data;
     		temp.set_conflict(true);
     	
		   Delete(current->data);
		   t[i].set_conflict(false);
		   insert1(t[i]);
		   t[i]=temp;
		   
     
		     }
	}
}
prev=current;  
current = current->right; 

}

   }
 




};
int partition(interval *p,int start,int end)
{
interval pivot,temp;
int j=0,i=0;
pivot=p[end];

 while(i<end)
{
	
	if(p[i].get_start_time()<=pivot.get_start_time())
     {
       
     	temp=p[i];
     	p[i]=p[j];
     	p[j]=temp;
     	j++;
    }
    i++;
	
    
}
       
        	
		temp=p[end];
     	p[end]=p[j];
     	p[j]=temp;
     	return j;
         
 	
}

void Quick_sort(interval *p,int start,int end)
{

	if(start<end)
	{
	
	int pivoti=partition(p,start,end);
		Quick_sort(p,start,pivoti-1);
		Quick_sort(p,pivoti+1,end);
	}
	
	
	
}





int main()
{

  int m1,m2,m3,m4,m5,a,b,c;
  //input files
ifstream readfile1("manager1.txt");
ifstream readfile2("manager2.txt"); 
ifstream readfile3("manager3.txt");
ifstream readfile4("manager4.txt");
ifstream readfile5("manager5.txt");
readfile1>>m1;
readfile2>>m2;
readfile3>>m3;
readfile4>>m4;
readfile5>>m5;
interval obj[m1+m2+m3+m4+m5];
AVL<interval>t1;
int i=0;
for(i=0;i<m1;i++)
{
	readfile1>>a>>b>>c;

	obj[i]=interval(a,b,c);
	
}

for(int j=0;j<m2;j++,i++)
{
	readfile2>>a>>b>>c;
	obj[i]=interval(a,b,c);
}

for(int j=0;j<m3;j++,i++)
{
	readfile3>>a>>b>>c;
	obj[i]=interval(a,b,c);
}


for(int j=0;j<m4;j++,i++)
{
	readfile4>>a>>b>>c;
	obj[i]=interval(a,b,c);
}

for(int j=0;j<m5;j++,i++)
{
	readfile5>>a>>b>>c;
	obj[i]=interval(a,b,c);
}
readfile1.close();
readfile2.close();
readfile3.close();
readfile4.close();
readfile5.close();

t1.insert(obj[0]);

for(int j=1;j<i;j++)
{
t1.insert(obj[j]);
}

interval obj2[100];

int j=0;

for( i=0,j=0;i<m1+m2+m3+m4+m5;i++)
{
	if(obj[i].get_conflict()==true)
	 {
	 	
	 	obj2[j]=obj[i];
	 	j++;
	 }
}


t1.check_silent(obj2,j);
Quick_sort(obj2,0,j-1);
cout<<"Conflicting times:"<<endl;

ofstream writefile("conflict.txt");

for(int k=0;k<j;k++)
{
	
 obj2[k].print(writefile);	
 
	
}

writefile.close();

ofstream writefile1("compatible.txt");

cout<<"\nCompatible times:"<<endl;
t1.inorder_print(t1.get_root(),writefile1);
writefile1.close();

return 0;
}
	
