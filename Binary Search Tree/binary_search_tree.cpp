/*Soham Belokar*/
#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF 1e18
#define PI 3.141592653589793238462
#define nline "\n"
#define space " "

typedef long long int ll;
typedef unsigned long long ull;
typedef long double lld;


/*
 *	Tree is non linear data structure
 *	Tree is recursive data structure
 *	Tree with N nodes will have exactly N-1 edges/link
 *	
*/

/*				1
			   / \
			  /   \
			 2     3
	  		/|\   	\
	  	   / | \     \
	  	  4  5  6     7
	  	 /   |        |
	  	8    9 		  10	

*/

/*	Depth and Height of a tree : 
 
 *	Depth of node X 

 	depth of node X = number of edeges in the path from root to node X 
 	(OR) number of nodes in the path from root to X.

 *	Height of node X 

	height of node X = number of edges in the longest path from node X to a leaf

 *  height of the tree = height of root node

 *	so depth of root node is zero and height of root node is the height of tree
	(and) the depth of leaf node is number of edges/nodes from root to that node and height
	of the leaf node is zero 

 *  height is also called as maximum depth of a tree
*/
/* 	Binary Tree:

 *	the tree with atmost two children is called as binary tree
 
 *  Strict binary tree:

 *	it means each node can have either 2 childs or 0 childs

 * 	maximum number of nodes at level i are 2^i

 *  maximum number of nodes in a tree with height H will be , (2^(H-1)) - 1

 *  perfect binary tree:
 *  if number of nodes are N
 *  number of edges are exactly N-1 (OR) 
 *  if height of a tree is H then the leaf nodes are exactly 2^H

*/


struct BstNode{
	int data;
	BstNode* right;
	BstNode* left;
};

bool isempty(BstNode* root){
	return (root == NULL);
}

BstNode* getNewNode(int val){
	BstNode* newnode = new BstNode;
	newnode->data = val;
	newnode->right = newnode->left = NULL;

	return newnode;
}
// // inserting a node in a binary search tree recursively
BstNode* insert(BstNode* root, int val){

	if(root == NULL){
		root = getNewNode(val);		
	}
	else if(val <= root->data){
		root->left = insert(root->left,val);		
	}
	else{
		root->right = insert(root->right, val);
	}

	return root;

}
// // searching an element in a binary search tree
bool search(BstNode* root,int val){
	if(root == NULL){return false;}
	else if(root->data == val){return true;}
	else if(val <= root->data){
		return search(root->left, val);
	}
	else{
		return search(root->right, val);
	}
}
// // inserting a node in a binary search tree using iterative method
BstNode* insertIterative(BstNode* root, int data){

	BstNode* temp = root;
	BstNode* prev = NULL;
	while(temp != NULL){
		prev = temp;
		if(data <= temp->data){
			temp = temp->left;
		}
		else{
			temp = temp->right;
		}
	}

	BstNode* newnode = getNewNode(data);
	if(prev == NULL){prev = newnode;}
	else if(data <= prev->data){
		prev->left = newnode;
	}
	else{
		prev->right = newnode;
	}

	return root;
}

// // finding the minimum element in a binary search tree
int findMin(BstNode* root){

	BstNode* temp = root;

	while(temp->left != NULL){
		temp = temp->left;
	}

	return temp->data;

}
// // finding the maximum element in a binary search tree
int findMax(BstNode* root){
	BstNode* temp = root;
	while(temp->right != NULL){
		temp = temp->right;
	}

	return temp->data;
}

// level order traversal / Breadth First Search(BFS)
void BreadthFirstSearch(BstNode* root){

	if(root == NULL){return;}

	BstNode* temp;
	queue<BstNode*> q;
	q.push(root);
	while(!q.empty()){
		temp = q.front();
		cout << temp->data << nline;
		q.pop();
		if(temp->left != NULL){q.push(temp->left);}
		if(temp->right != NULL){q.push(temp->right);}
	}

}


// // Depth First Search(DFS)

// // Preorder 
// // root , left , right
void preorder(BstNode* root){

	if(root == NULL){return;}
	cout << root->data << nline;
	preorder(root->left);
	preorder(root->right);

}
// // preorder iterative
void preorderIterative(BstNode* root){

	BstNode* temp = root;

	stack<BstNode*> st;
	
	while(!st.empty() || temp != NULL){
		while(temp != NULL){
			cout << temp->data << nline;

			if(temp->right){
				st.push(temp->right);
				
			}
			temp = temp->left;
		}
		if(!st.empty()){
			temp = st.top();
			st.pop();
		}
	}

}


// // inorder
// // left , root , right
void inorder(BstNode* root){
	if(root == NULL){return;}
	inorder(root->left);
	cout << root->data << nline;
	inorder(root->right);
}

// inorder iterative
void inorderIterative(BstNode* root){
	BstNode* temp = root;

	stack<BstNode*> st;

	while(temp != NULL || !st.empty()){
		while(temp != NULL){
			
			if(temp){st.push(temp);}
			temp = temp->left;
		}
		if(!st.empty()){
			cout << st.top()->data << nline;
			temp = st.top()->right;
			st.pop();
		}

	}
}

// // postorder
// // left , right , root
void postorder(BstNode* root){
	if(root == NULL){return;}
	postorder(root->left);
	postorder(root->right);
	cout << root->data << nline;
}

// // postorder iterative
void postorderIterative(BstNode* root){
	BstNode* temp = root;

	stack<BstNode*> s1,s2;
	s1.push(root);

	while(!s1.empty()){
	
		temp = s1.top();
		s2.push(temp);
		s1.pop();

		if(temp->left){
			s1.push(temp->left);
		}
		if(temp->right){
			s1.push(temp->right);
		}

	}

	while(!s2.empty()){
		cout << s2.top()->data << nline;

		s2.pop();
	}	

}

// // postorder iterative using one stack
void postorderIterativeSingleStack(BstNode* root){
	BstNode* curr = root;
	BstNode* temp = NULL;
	stack<BstNode*> st;

	while(!st.empty() || curr!=NULL){
		if(curr != NULL){
			st.push(curr);
			curr = curr->left;
		}
		else{
			temp = st.top()->right;
			if(temp != NULL){
				curr = temp;
			}
			else{
				temp = st.top();
				st.pop();
				cout << temp->data << " ";
				while(!st.empty() && temp == st.top()->right){
					temp = st.top();
					st.top();
					cout << temp->data << " ";
				}

			}
		}
	}
	cout << nline;
}

// // is it a binary search tree
bool isSubtreeGreater(BstNode* root, int val){

	if(root == NULL){return true;}

	if(root->data >= val && isSubtreeGreater(root->left,val) && isSubtreeGreater(root->right,val)){
		return true;
	}
	return false;

}

bool isSubtreeSmaller(BstNode* root, int val){

	if(root == NULL){return true;}
	if(root->data <= val && isSubtreeSmaller(root->left,val) && isSubtreeSmaller(root->right,val)){
		return true;
	}
	return false;

}

bool isBST(BstNode* root){
	
	if(root == NULL){return true;}

	if(isSubtreeSmaller(root->left,root->data) && isSubtreeGreater(root->right,root->data)
	&& isBST(root->left) && isBST(root->right)){return true;}

	return false;

}

bool onechild(BstNode* root){
	if((root->left==NULL && root->right!=NULL) || (root->right==NULL && root->left!=NULL)){
		return true;
	}
	return false;
}

bool nochild(BstNode* root){
	if(root->left == NULL && root->right == NULL){return true;}
	return false;
}

BstNode* deleteNode(BstNode* root, int val){


	if(root == NULL){return root;}

	BstNode* temp = root;
	BstNode* prev = NULL;
	while(temp->data != val){
		prev =  temp;
		if(val <= temp->data){
			if(temp->left){temp = temp->left;}
			else{break;}
		}
		else{
			if(temp->right){temp = temp->right;}
			else{break;}
		}
		
	}
	
	if(nochild(temp)){
		if(prev->left == temp){prev->left = NULL;}
		else{prev->right = NULL;}
		delete(temp);
	}
	else if(onechild(temp)){
		if(temp->left){
			temp->data = temp->left->data;
			temp->left = NULL;
		}
		else{
			temp->data = temp->right->data;
			temp->right = NULL;
		}
		
	}
	else{
		// find the minimum in right subtree and copy the data to the node to be deleted 
		// then remove the duplicate node from right subtree (by using case 1 or case 2)
		// OR
		// find the maximum in left subtree and copy the data to the node to be deleted 
		// then remove the duplicate node from left subtree (by using case 1 or case 2)
		int replacement = findMax(temp->left);
		deleteNode(root, replacement);
		temp->data = replacement;
	}
	return root;
}

// deleting a node from BST recursively
BstNode* deleteNodeRecursive(BstNode* root, int val){

	if(root == NULL){return root;}
	else if(val < root->data){root->left = deleteNodeRecursive(root->left,val);}
	else if(val > root->data){root->right = deleteNodeRecursive(root->right,val);}
	else{
		// case 1: no child
		if((root->left == NULL) && (root->right == NULL)){
			delete root;
			root = NULL;
		}
		// case 2: one child
		else if(root->left == NULL){
			BstNode* temp = root;
			root = root->right;
			delete(temp);
		}
		else if(root->right == NULL){
			BstNode* temp = root;
			root = root->left;
			delete(temp);
		}
		// case 3: two childs
		else{
			int temp = findMax(root->left);
			root->data = temp;
			root->left = deleteNodeRecursive(root->left, temp);

		}
	}
	return root;

}

// // height of the tree
int HeightOfTree(BstNode* root){

	if(root == NULL){
		return 0;
	}

	int LeftHeight =  HeightOfTree(root->left);
	int RightHeight = HeightOfTree(root->right);

	return 1 + max(LeftHeight,RightHeight);

}

// // check if the tree is balanced
// // O(N^2)
bool isBalanced(BstNode* root){
	if(root == NULL){return true;}

	int leftheight = HeightOfTree(root->left);
	int rightheight = HeightOfTree(root->right);

	if(abs(leftheight - rightheight) > 1){return false;}

	bool left = isBalanced(root->left);
	bool right = isBalanced(root->right);

	if(!right || !left){return false;}


	return true;
}

// // checks if the tree is balanced in O(N) time complexity

int isbalancecdtree(BstNode* root){
	if(root == NULL){
		return 0;
	}

	int leftheight = HeightOfTree(root -> left);
	int rightheight = HeightOfTree(root -> right);

	if(abs(leftheight - rightheight) > 1){return -1;}

	return max(leftheight,rightheight) + 1;
}

int main() 
{ 	

	BstNode* root = NULL;	// creating an empty tree
	
	root = insert(root, 10);
	root = insert(root, 5);
	root = insert(root, 4);
	root = insert(root, 6);
	root = insertIterative(root, 15);
	root = insertIterative(root, 11);
	root = insert(root, 16);
	root = insert(root, 14);
	root = insert(root, 12);

	// BstNode* temp = root;
	// root = deleteNode(root,15);
	// root = deleteNodeRecursive(root,15);
	// cout << (*root).data << nline;
	// postorderIterativeSingleStack(root); // **

	// cout << HeightOfTree(root) << nline;
	// (isBalanced(root)) ? cout << "true" : cout << "false";
	// cout << nline;
	// cout << isbalancecdtree(root) << nline;
	
	// inorderIterative(root);
	// cout << findMin(root) << nline;
	// cout << findMax(root) << nline;

	// BreadthFirstSearch(root);

	// preorder(root);
	// preorderIterative(root);	

	// inorder(root);
	// inorderIterative(root);

	// postorder(root);
	// cout << nline;
	// postorderIterative(root);

	// (isBST(root)) ? cout << "YES" : cout << "NO";
	
	

	// root = deleteNode(root,14);
	
	
	


return 0;
}
