// define a sorted(ascending) ListNode class for int 
#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
};

void print(ListNode* L){
	if (L == NULL){
		return;
	}
	
	ListNode* cur = L;
	while (cur != NULL){
		if (cur->next == NULL){
			cout << cur->val;
		} else {
			cout << cur->val << " -> ";
		}
		cur = cur->next;
	}
	cout << endl;
}

void insert(ListNode* &L, int v){
	if (L == NULL){
		L = new ListNode;
		L->val = v;
		L->next = NULL;
		return;
	}
	
	ListNode* cur = L;
	
	while (cur->next != NULL && cur->val != v && cur->val+1 != v && (cur->next)->val <= v){
		cur = cur->next;
	}

	ListNode* newNode = new ListNode;
	newNode->val = v;
	newNode->next = cur->next;
	cur->next = newNode;	
}

void remove(ListNode* &L, int v){
	if (L == NULL) return;

	ListNode* cur = L;
	
	while ((cur->next)->val <= v){
		if (cur->next->val == v){
			ListNode* temp = cur;
			cur->next = cur->next->next;
		} else {
			cur = cur->next;
		}
	}
	
}

int main(){
	ListNode* L = NULL;
	insert(L, 1);
	insert(L, 3);
	insert(L, 5);
	insert(L, 9);
	insert(L, 2);
	insert(L, 6);
	insert(L, 8);
	insert(L, 88);
	cout << "After Insertion: " << endl;
	print(L);
	
	cout << "Remove 9: " << endl;
	remove(L, 9);
	print(L);

	return 0;
}
