#include <iostream>
using namespace std;

struct BinaryTree{
	int val;
	BinaryTree* left;
	BinaryTree* right;
};

void Pre_createTree(BinaryTree* &B){ // PreTraversal to create Binary Tree
	cout << "Please Fill In Current Node Value (-1 represents NULL Node): ";
	int value;
	cin >> value;
	if (value == -1){
		return;
	} else {
		BinaryTree* node = new BinaryTree;
		node->val = value;
		B = node;
		Pre_createTree(B->left);
		Pre_createTree(B->right);
	}
}

void preTraverse(BinaryTree* Node){
	if (Node == NULL){
		return;
	} else {
		// sth to do with current node
		cout << Node->val << " ";
		// ...
		preTraverse(Node->left);
		preTraverse(Node->right);
	}
}

void midTraverse(BinaryTree* Node){
	if (Node == NULL){
		return;
	} else {
		midTraverse(Node->left);
		// sth to do with current node
		cout << Node->val << " ";
		// ...
		midTraverse(Node->right);
	}
}

void postTraverse(BinaryTree* Node){
	if (Node == NULL){
		return;
	} else {
		postTraverse(Node->left);
		postTraverse(Node->right);
		// sth to do with current node
		cout << Node->val << " ";
		// ...
	}
}
int main(){
	BinaryTree* B = NULL;
	
	Pre_createTree(B);
	
	// print the node in pre-traverse order
	cout << "Pre-Traverse: " << endl;
	preTraverse(B);
	cout << endl;
	// print the node in mid-traverse order
	cout << "Mid-Traverse: " << endl;
	midTraverse(B);
	cout << endl;
	// print the node in post-traverse order
	cout << "Post-Traverse: " << endl;
	postTraverse(B);
	cout << endl;
}
