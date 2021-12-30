#include<iostream>
using namespace std;
#define MAX 20

class bstnode
{
	public:
	int info;
	bstnode *left, *right;
	
	bstnode()
	{
		info=0;
		left=NULL;
		right=NULL;
	}	

	bstnode(int x)
	{
		info=x;
		left=NULL;
		right=NULL;
	}
};

class stack
{
	bstnode *st[MAX];
	int top;
	
	public:
		stack()
		{
			top=-1;
		}

		int isempty()
		{
			if(top==-1)
				return 1;
			else 
				return 0;
		}

		void push(bstnode *x)
		{
			if(top==(MAX-1))
				cout<<"\nStack overflow";
			else
			{
				top=top+1;
				st[top]=x;
			}
		}

		bstnode* ret_top()
		{
			return st[top];
		}

		bstnode* pop()
		{
			if(top==-1)
				cout<<"\nUnderflow";
			else
			{
				bstnode* x=st[top];
				top=top-1;
				return x;
			}	
		}
};

class queue
{
	bstnode *A[MAX];
	int front, rear;
    public:
	queue()
	{
		front= -1;
		rear= -1;
	}
	
	int IsEmpty()
	{
        if((front == -1)&&(rear == -1))
            return 1;
        else
            return 0;
	}

	int IsFull()
	{
		if((front == rear+1)||((front == 0)&&(rear == MAX-1)))
            return 1;
        else
            return 0;
	}
	
	void Enqueue(bstnode *x)
	{
		if(IsFull())
		{
			cout<<"\nQueue is full.";
			return;
		}
		else
		{
		    if(front == -1)
            {
                rear++;
                front++;
            }
            else if(rear == MAX-1)
            {
                rear=0;
            }
            else
            {
                rear++;
            }
            A[rear]=x;
		}
	}
	
	bstnode* Dequeue()
	{
		if(IsEmpty())
		{
			cout<<"\nQueue is empty.";
		}
		else
		{
			bstnode *x= A[front];
			if(front == MAX-1 )
			{
				front = 0;
			}
			else if(front == rear)
			{
				front = rear = -1;
			}
			else
	        {
	            front++;
			}
			return x;
		}
	}
};

class bst
{
	bstnode *root;
	stack s;
	queue q;
	public:
	bst()
	{
		root=NULL;
	}
		
	void insert(int x)			//function for inserting values to binary tree.
	{
		bstnode *p, *q, *prev;
		p=new bstnode(x);
		q=root;
		if(q==NULL)
		{
			root=p;
		}
		else
		{
			while(q!=NULL)
			{
				if(x<q->info)
				{
					prev=q;
					q=q->left;
				}
				else
				{
					prev=q;
					q=q->right;
				}
			}
			
			if(x<prev->info)
				prev->left=p;
			else
				prev->right=p;
		}
	}
	
	bstnode* ret_root()
	{
		return root;
	}	

//***********************ITERATIVE TRAVERSALS**********************
	void pre_order_ite(bstnode *p)
	{
		bstnode *q;
 		if(p!=NULL)
		{
			if(p!=NULL)
				s.push(p);
			
			while(!s.isempty())
			{
				q=s.pop();
				cout<<q->info<<" ";
				if(q->right!=NULL)
					s.push(q->right);
				if(q->left!=NULL)
					s.push(q->left);
			}
		}
		else
			cout<<"\nTree is empty.";
	}
			
	void in_order_ite( bstnode *p)
	{
		if(p!=NULL)
		{
			while(p!=NULL)
			{
				while(p!=NULL)
				{
					if(p->right!=NULL)
						s.push(p->right);
					s.push(p);
					p=p->left;
				}
				p=s.pop();
				while( !s.isempty() && p->right==NULL)
				{
					cout<<p->info<<" ";
					p=s.pop();
				}
				cout<<p->info<<" ";
				if(!s.isempty())
					p=s.pop();
				else
					p=NULL;
			}
		}
		else
			cout<<"\nTree is empty.";
	}

	void post_order_ite(bstnode *p)
	{
		if(p!=NULL)
		{
			do
			{
				while(p!=NULL)
				{
					if(p->right!=NULL)
						s.push(p->right);
					s.push(p);
					p=p->left;
				}
				p=s.pop();
				if( s.ret_top()==p->right  && p->right!=NULL)
				{
					s.pop();
					s.push(p);
					p=p->right;
				}
				else
				{
					cout<<p->info<<" ";
					p=NULL;
				}
				
			}while(!s.isempty());
		}
		else
			cout<<"\nTree is empty.";
		
	}

//*******************RECURSIVE TRAVERSALS****************
	void pre_order_rec(bstnode *p)
	{
		if(p!=NULL)
		{
			cout<<p->info<<" ";
			pre_order_rec(p->left);
			pre_order_rec(p->right);
		}
		else
			cout<<"\nTree is empty.";
	}

	void in_order_rec(bstnode *p)
	{
		if(p!=NULL)
		{
			pre_order_rec(p->left);
			cout<<p->info<<" ";
			pre_order_rec(p->right);
		}
		else
			cout<<"\nTree is empty.";
	}

	void post_order_rec(bstnode *p)
	{
		if(p!=NULL)
		{
			pre_order_rec(p->left);
			pre_order_rec(p->right);
			cout<<p->info<<" ";
		}		
		else
			cout<<"\nTree is empty.";
	}
	
	void bfs(bstnode *p)				//Breadth first search traversal.
	{
		if(p!=NULL)
		{
			cout<<p->info<<" ";
			do
			{
				if(p->left)
					q.Enqueue(p->left);
				if(p->right)
					q.Enqueue(p->right);
				p=q.Dequeue();
				cout<<p->info<<" ";
			}while(!q.IsEmpty());
		}
		else
			cout<<"\nTree is empty.";
	}			
	
	int height(bstnode *p)
	{
		if(p==NULL)
			return 0;
		else
		{
			int lht= height(p->left);
			int rht= height(p->right);
			
			if(lht>rht)
				return lht+1;
			else
				return rht+1;
		}
	}
	
	void mirror( bstnode *p)
	{
		bstnode *temp;
		if(p!=NULL)
		{
			mirror(p->left);
			mirror(p->right);
			
			temp=p->left;
			p->left=p->right;
			p->right=temp;
		}
	}
	
	int getLeafCount(bstnode *p)
	{
		
		if( p==NULL)       
			return 0;
		if(p->left == NULL && p->right==NULL)      
			return 1;            
		else
			return getLeafCount(p->left) + getLeafCount(p->right);      
	}
	
	int totalNode(bstnode *p)
	{
		if(p==NULL)
			return 0;
		else
			return 1+totalNode(p->left)+totalNode(p->right);
	}
	
	int search(bstnode *p, int x)
	{
		if(p!=NULL)
		{
			if(p->info==x)
				return 1;
			else if( p->info<x)
				search(p->right,x);
			else
				search(p->left,x);
		}
		else 
			return 0;
	}
	
	bstnode* FindMin(bstnode *node)
	{
        if(node==NULL)
        {
			/* There is no element in the tree */
			return NULL;
        }
        if(node->left) /* Go to the left sub tree to find the min element */
			return FindMin(node->left);
        else 
			return node;
	}
	
	bstnode * DeletebyCopying(bstnode *node, int info)
	{
        bstnode *temp;
        if(node==NULL)
        {
			cout<<"\nElement Not Found";
        }
        else if(info < node->info)
        {
			node->left = DeletebyCopying(node->left, info);
        }
        else if(info > node->info)
        {
			node->right = DeletebyCopying(node->right, info);
        }
        else
        {
			if(node->right && node->left)			//Two child
			{
					
					temp = FindMin(node->right);
					node -> info = temp->info; 		//Copy minimum value of right sub-tree onto node to be deleted.
		
					node -> right = DeletebyCopying(node->right,temp->info);	//Delete node copied onto node to be deleted.
			}
			else									// Only child or One child.
			{
					temp = node;
					if(node->left == NULL)
							node = node->right;
					else if(node->right == NULL)
							node = node->left;
					delete (temp);
			}
        }
        return node;
	}

    bstnode * DeletebyMerging(bstnode *node, int info){
        bstnode *temp;
        if(node==NULL)
        { 
            cout<<"\nElement Not Found";
        }
        else if(info < node->info)
        {
            node->left = DeletebyMerging(node->left, info);
        }
        else if(info > node->info)
        {
            node->right = DeletebyMerging(node->right, info);
        }
        else
        {
            if(node->right && node->left)			//Two child
            {
                temp = FindMin(node->right);
                node -> info = temp->info; 		//Copy minimum value of right sub-tree onto node to be deleted.
                node -> right = DeletebyMerging(node->right,temp->info);	//Delete node copied onto node to be deleted.
            }
            else									// Only child or One child.
            {
                temp = node;
                if(node->left == NULL)
                    node = node->right;
                else if(node->right == NULL)
                    node = node->left;
                delete (temp);
            }
        }
    }
};

int main()
{
	bst ob;
	char ch;
	int num, num2;
	int leaf, nleaf;
	do
	{
		system("cls");
		cout<<"\n********MENU***********";
		cout<<"\n1. Insert element.";
		cout<<"\n2. Pre-order traversal.";
		cout<<"\n3. In-order traversal.";
		cout<<"\n4. Post-order traversal.";
		cout<<"\n5. Deletion by copying.";
		cout<<"\n6. Deletion by merging.";
		cout<<"\n7. Height of tree.";
		cout<<"\n8. Mirror image of tree.";
		cout<<"\n9. Count leaf and non-leaf nodes.";
		cout<<"\n10. Search any value in tree.";
		cout<<"\n11. Exit.";
		cout<<"\nEnter your choice: ";
		cin>>num;
		
		switch(num)
		{
			case 1: system("cls");
					do{
						cout<<"\nEnter value: ";
						cin>>num2;
						ob.insert(num2);
						cout<<"\nEnter more values(y/n): ";
						cin>>ch;
					}while(ch=='y');
					break;
					
			case 2: system("cls");
					cout<<"\n1. Using iterative.";
					cout<<"\n2. Using recursive.";
					cout<<"\nEnter your choice: ";
					cin>>num;
					if(num==1)
						ob.pre_order_ite( ob.ret_root());
					else 
						ob.pre_order_ite( ob.ret_root());
					break;
					
			case 3: system("cls");
					cout<<"\n1. Using iterative.";
					cout<<"\n2. Using recursive.";
					cout<<"\nEnter your choice: ";
					cin>>num;
					if(num==1)
						ob.in_order_ite( ob.ret_root());
					else 
						ob.in_order_ite( ob.ret_root());
					break;
					
			case 4: system("cls");
					cout<<"\n1. Using iterative.";
					cout<<"\n2. Using recursive.";
					cout<<"\nEnter your choice: ";
					cin>>num;
					if(num==1)
						ob.post_order_ite( ob.ret_root());
					else 
						ob.post_order_ite( ob.ret_root());
					break;
					
			case 5: cout<<"\nValue to be deleted from tree: ";
					cin>>num2;
					ob.DeletebyCopying( ob.ret_root(), num2);
					break;
					
			case 6: cout<<"\nValue to be deleted from tree: ";
                    cin>>num2;
                    ob.DeletebyMerging( ob.ret_root(), num2);
					break;
					
			case 7:	num2=ob.height( ob.ret_root());
					cout<<"\nHeight of tree: "<<num2;
					break;
					
			case 8: ob.mirror( ob.ret_root());
					break;
				
			case 9: leaf=ob.getLeafCount( ob.ret_root());
					nleaf=ob.totalNode( ob.ret_root()) -leaf;
					if(leaf==1 && nleaf==0)
					{
						cout<<"\nOnly root node present.";
					}
					else
					{
						cout<<"\nNumber of leaf nodes: "<<leaf;
						cout<<"\nNumber of non-leaf node: "<<nleaf;
					}	
					break;
					
			case 10:cout<<"\nEnter value for searching: ";
					cin>>num2;
					if( ob.search( ob.ret_root(), num2) )
						cout<<"\nValue found in tree.";
					else
						cout<<"\nValue not found.";
					break;
					
			case 11: cout<<"\nExiting...";
					exit(100);
					break;
			default: cout<<"\nWrong input!!!";
					break;
		}
		cout<<"\n\nReturn to menu(y/n): ";
		cin>>ch;
	}while(ch=='y');
	return 0;
}