#include<iostream>
#include<queue>
#include<stack>
using namespace std;

template <class T>
class node{
	
	T data;
	node* left;
	node* right;
	public:
		node(T val){
			data=val;
			left=NULL;
			right=NULL;
		}
		template <class U> friend class BST;
};

template <class T>
class BST{
	public:
	node<T> *root;
		BST(){
			root=NULL;
		}
		void insert(T val){
			node<T> *temp=new node<T>(val);
			if(root==NULL){
				root=temp;
				return;
			}
			node<T> *troot=root;
			node<T> *prev;
			while(troot!=NULL){
				prev=troot;
				if(val==troot->data){
					return;
				}
				else if(val<troot->data){
					troot=troot->left;
					
				}
				else{
					troot=troot->right;
				}
			}
			if(val<prev->data){
				prev->left=temp;
			}
			else{
				prev->right=temp;
			}
		}

        //Recursive Traversals
		void preorder(node<int> *r){
			if(r!=NULL){
				cout<<r->data<<" ";
				preorder(r->left);
				preorder(r->right);
			}
		}
		void postorder(node<int> *r){
			if(r!=NULL){
				
				postorder(r->left);
				postorder(r->right);
				cout<<r->data<<" ";
			}
		}
		void inorder(node<int> *r){
			if(r!=NULL){
				
				inorder(r->left);
				cout<<r->data<<" ";
				inorder(r->right);
			}
		}
		void leveltraverse(){
			queue<node<T>*> q;
			node<T> *troot=root;
			q.enqueue(troot);
			while(!q.empty()){
				troot=q.dequeue();
				cout<<troot->data<<" ";
				if(troot->left!=NULL){
					q.enqueue(troot->left);
				}
				if(troot->right!=NULL){
					q.enqueue(troot->right);
				}
			}
		}
		node<T> *search(T key){
			node<T> *troot=root;
			while(troot!=NULL){
				if(key==troot->data){
					return troot;
				}
				else if(key<troot->data){
					troot=troot->left;
				}
				else{
					troot=troot->right;
				}
			}
			return NULL;
		}
		node<T> *inpredecesor(node<T> *troot){
			while(troot->right!=NULL){
				troot=troot->right;
				
			}
			return troot;
		}
		node<T>* deletenode(node<T> *troot,T key){
				if(troot==NULL){
					return NULL;
				}
				if(troot->data>key){
					troot->left=deletenode(troot->left,key);
				}
				else if(troot->data<key){
					troot->right=deletenode(troot->right,key);
				}
				else{
					if(troot->left==NULL &&troot->right==NULL){
						return NULL;
					}
					else if(troot->left==NULL){
						node<T> *temp=troot->right;
						delete(troot);
						return temp;
					}
					else if(troot->right==NULL){
						node<T> *temp=troot->left;
						delete(troot);
						return temp;
					}
					else{
						node<T> *ipre=inpredecesor(troot->left);
						troot->data=ipre->data;
						troot->left=deletenode(troot->left,ipre->data);
					}
				}
			}
		node<T>* deletebymerging(node<T> *troot,T key){
				if(troot==NULL){
					return NULL;
				}
				if(troot->data>key){
					troot->left=deletenode(troot->left,key);
				}
				else if(troot->data<key){
					troot->right=deletenode(troot->right,key);
				}
				else{
					if(troot->left==NULL &&troot->right==NULL){
						return NULL;
					}
					else if(troot->left==NULL){
						node<T> *temp=troot->right;
						delete(troot);
						return temp;
					}
					else if(troot->right==NULL){
						node<T> *temp=troot->left;
						delete(troot);
						return temp;
					}
					else{
						node<T> *left=troot->left;
						node<T> *right=troot->right;
						delete(troot);
						node<T> *tright=right;
						while(tright->left!=NULL){
							tright=tright->left;
						}
						tright->left=left;
						return right;
					}
				}
			}

            //Iterative Traversals
			void inorderiterative(){
				node<T> *curr=root;
				stack<node<T>*> stck;
				while(curr!=NULL||stck.empty()==false){
					while(curr!=NULL){
						stck.push(curr);
						curr=curr->left;
						
					}
					curr=stck.top();
					stck.pop();
					cout<<curr->data<<" ";
					curr=curr->right;
				}
			}
			void preorderiterative(){
				node<T> *curr=root;
				stack<node<T>*> stck;
				while(curr!=NULL||stck.empty()==false){
					while(curr!=NULL){
						cout<<curr->data<<" ";
						stck.push(curr);
						curr=curr->left;
						
					}
					curr=stck.top();
					stck.pop();
					curr=curr->right;
					
				}
			}
			void postorderiterative(){
					if(root==NULL){
						return;
					}
				node<T> *curr=root;
				stack<node<T>*> s1,s2;
				s1.push(curr);
				while(!s1.empty()){
					curr=s1.top();
					s1.pop();
					s2.push(curr);
					if(curr->left)
						s1.push(curr->left);
					if(curr->right)
						s1.push(curr->right);
				
				}
				while(!s2.empty()){
					curr=s2.top();
					s2.pop();
					cout<<curr->data<<" ";
					
				}
				
			}
			int findheight(node<T> *troot){
				if(troot==NULL){
					return -1;
				}
				int left=findheight(troot->left);
				int right=findheight(troot->right);
				if(left>right)
				return left+1;
				else
				return right+1;
			}
			int countnodes(node<T> *troot){
				if(troot==NULL){
					return 0;
				}
				int left=countnodes(troot->left);
				int right=countnodes(troot->right);
				return left+right+1;
				
			}
			int countleaves(node<T> *troot){
				if(troot==NULL){
					return 0;
				}
				if(troot->left==NULL&&troot->right==NULL){
					return 1;
				}
				else{
				
				int left=countleaves(troot->left);
				int right=countleaves(troot->right);
				return left+right;
			}
			}
		int countrightchildren(node<T> *t){
			
			if(t==NULL){
				return 0;
			}
			int x=0;
			if(t->left){
				x+=countrightchildren(t->left);
			}
			if(t->right){
				
				x+=countrightchildren(t->right);
				x+=1;
			}
			return x;
		}
		node<T>* deleteallleaves(node<T> *troot){
			if(troot==NULL){
				return NULL;
			}
			if(troot->left==NULL&&troot->right==NULL){
				return NULL;
			}
			troot->left=deleteallleaves(troot->left);
			troot->right=deleteallleaves(troot->right);
			return troot;
		}
		bool testBST(){
			node<T> *curr=root;
			stack<node<T>*> s1;
			int arr[100],size=0;
			while(curr!=NULL||s1.empty()==false){
				while(curr!=NULL){
					s1.push(curr);
					curr=curr->left;
				}
				curr=s1.top();
				s1.pop();
				arr[size]=curr->data;
				size++;
				curr=curr->right;
			}
			for(int i=0;i<(size-1);i++){
				if(arr[i+1]<arr[i])
				return false;
			}
			return true;
		}
};


int main(){
	BST<int> b;
	b.insert(20);
	b.insert(8);
	b.insert(6);
	b.insert(5);
	b.insert(4);
	b.insert(7);
	b.insert(15);
	b.insert(30);
	b.insert(28);
	b.insert(27);
	b.insert(25);
	b.insert(32);
	b.insert(40);
	b.insert(38);
	b.inorder(b.root);
	cout<<"\n";
	b.preorder(b.root);
	cout<<"\n";
	b.postorder(b.root);
	b.root=b.deletebymerging(b.root,20);
	b.inorder(b.root);
	cout<<"\n";
	b.inorderiterative();
	b.inorderiterative();
	cout<<"\n";
	b.preorderiterative();
	cout<<"\n";
	b.postorderiterative();
	cout<<b.countnodes(b.root);
	cout<<"\n"<<b.countleaves(b.root);
	cout<<"\n"<<b.countrightchildren(b.root);
	cout<<"\n";
	b.root=b.deleteallleaves(b.root);
	cout<<"\n";
	b.inorder(b.root);
	cout<<"\n";
	b.preorder(b.root);
// 	cout<<"\n";
// ////	b.postorder(b.root);
// 	cout<<b.testBST();
}