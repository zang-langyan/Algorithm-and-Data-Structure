#include <iostream>
#include <vector>
using namespace std;

struct BSTree{
	int val;
	BSTree* left = NULL;
	BSTree* right = NULL;
};

void insert(BSTree* &T, int v){
	if (T == nullptr){
		BSTree* node = new BSTree;
		node->val = v;
		T = node;
	} else {
		if (v > T->val){ // go to the right child tree
			insert(T->right, v);
		} else { // go to the left child tree
			insert(T->left, v);
		}
	}
}

BSTree* search(BSTree* T, int target){ // 递归 recursion
	if (T == NULL) return NULL;
	if (T->val < target) return search(T->right, target);
	else if (T->val > target) return search(T->left, target);
	else if (T->val == target) return T;
	return NULL;
}

BSTree* search_itr(BSTree* T, int target){
	while (T != NULL){
		if (T->val < target) {
			T = T->right;
		} else if (T->val > target) {
			T = T->left;
		} else {
			return T;
		}
	}

	return NULL;
}

BSTree* deleteNode(BSTree* T, int val){
	if (T == NULL) return NULL;
	if (T->val < val) {
		T->right = deleteNode(T->right, val);
	} else if (T->val > val) {
		T->left = deleteNode(T->left, val);
	} else {
		if (T->left == NULL && T->right == NULL){
			BSTree* temp = T;
			delete T;
			temp = NULL;
			return temp;
		} else if (T->left == NULL && T->right != NULL){
			BSTree* temp = T->right;
			delete T;
			return temp;
		} else if (T->left != NULL && T->right == NULL){
			BSTree* temp = T->left;
			delete T;
			return temp;
		} else {
			// 1. add right tree to the left
			BSTree* cur = T->left;
			while (cur->right != NULL){
				cur = cur->right;
			} // Now cur is pointing at the largest node of the left child tree
			cur->right = T->right;
			BSTree* temp = T->left;
			delete T;
			return temp;

			// 2. add left tree to the right
			/* 
			BSTree* cur = T->right;
			while (cur->left != NULL){
				cur = cur->left;
			} // Now cur is pointing at the smallest node of the right child tree
			cur->left = T->left;
			BSTree* temp = T->right;
			delete T;
			return temp;
			*/	
		}
	}

	return T;
}

void mid_Traverse(BSTree* T){
	if (T == nullptr){
		return;
	}

	mid_Traverse(T->left);
	cout << T->val << " ";
	mid_Traverse(T->right);
}

int main(){
	BSTree* T = NULL;
	vector<int> values{60,55,78,96,13,15,17,29,36};
	for (auto& v: values){
		insert(T, v);
	}
	
	cout << "中序遍历： " << endl;
	mid_Traverse(T);
	cout << endl;
	cout << endl;

	cout << "Recursion:" << endl;
	BSTree* target_rec = search(T, 60);
	if (target_rec == NULL){
		cout << "Nullptr" << endl;
	} else {
		cout << "地址： " << target_rec << ", 值： " << target_rec->val << endl;
	}
	cout << endl;

	cout << "Iteration:" << endl;
	BSTree* target_itr = search(T, 96);
	if (target_itr == NULL){
		cout << "Nullptr" << endl;
	} else {
		cout << "地址： " << target_itr << ", 值： " << target_itr->val << endl;
	}
	cout << endl;

	cout << "After Delete Node 13: " << endl;
	T = deleteNode(T, 13);
	mid_Traverse(T);
	cout << endl;
	cout << endl;
}
