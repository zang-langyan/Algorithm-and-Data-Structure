#include <iostream>
#include <vector>
using namespace std;

struct Avl_Node{
  int val;
  int height;
  Avl_Node* left;
  Avl_Node* right;
};

Avl_Node* newNode(int val){
  Avl_Node* node = new Avl_Node;
  node->val = val;
  node->height = 1;

  return node;
}

int getHeight(Avl_Node* node){
  if (node == NULL){
    return 0;
  }
  return node->height;
}

// 左旋
// 1. 当前结点(根结点)的右子树会作为新树的根结点
// 2. 当前结点(根结点)会作为新树根结点的左子树
// 3. 如果新树的根结点原本有左子树，则其将作为当前结点(根结点)的右子树
Avl_Node* left_rotate(Avl_Node* root){
  Avl_Node* newRoot = root->right;
  
  // T2 保存新树根结点原本的左子树
  Avl_Node* T2 = newRoot->left;
  
  // Left Rotate
  newRoot->left = root;
  root->right = T2;

  // update height
  root->height = 1 + max(getHeight(root->left), getHeight(root->right)); 
  newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

  return newRoot;
}

// 右旋
// 1. 当前结点(根结点)的左子树会作为新树的根结点
// 2. 当前结点(根结点)会作为新树根结点的右子树
// 3. 如果新树的根结点原本有右子树，则其将作为当前结点(根结点)的左子树
Avl_Node* right_rotate(Avl_Node* root){
  Avl_Node* newRoot = root->left;
  
  // T2 保存新树根结点原本的左子树
  Avl_Node* T2 = newRoot->right;
  
  // Right Rotate
  newRoot->right = root;
  root->left = T2;

  // update height
  root->height = 1 + max(getHeight(root->left), getHeight(root->right)); 
  newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

  return newRoot;
}

int getBalance(Avl_Node* node){
  return getHeight(node->left) - getHeight(node->right);
}

// 插入结点
Avl_Node* insertNode(Avl_Node* node, int key){
  if (node == NULL){
    return newNode(key);
  }

  if (key < node->val){
    node->left = insertNode(node->left, key);
  } else if (key > node->val){
    node->right = insertNode(node->right, key);
  } else { // key already exist, no insertion 
    return node;
  } 

  // update height
  node->height = 1 + max(getHeight(node->left), getHeight(node->right));

  // 失衡
  int balance = getBalance(node);
  if (balance > 1 && getBalance(node->left) > 0){ // LL
    return right_rotate(node); 
  }
  if (balance > 1 && getBalance(node->left) < 0){ // LR
    node->left = left_rotate(node->left);
    return right_rotate(node);
  }
  if (balance < -1 && getBalance(node->right) < 0){ // RR
    return left_rotate(node); 
  }
  if (balance < -1 && getBalance(node->right) > 0){ // RL
    node->right = right_rotate(node->right);
    return left_rotate(node);
  }

  return node;
}

/* 
 * 先序遍历
 */
void pre_traverse(Avl_Node* root){
  if (root == NULL) return;

  cout << root->val << " ";
  pre_traverse(root->left);
  pre_traverse(root->right);
}

/* 
 * 中序遍历
 */
void mid_traverse(Avl_Node* root){
  if (root == NULL) return;

  mid_traverse(root->left);
  cout << root->val << " ";
  mid_traverse(root->right);
}

Avl_Node* find(Avl_Node* root, int target, int* counter){
  Avl_Node* cur = root;
  while(cur != NULL){
    if (target < cur->val){
      cur = cur->left;
      (*counter)++;
    } else if (target > cur->val){
      cur = cur->right;
      (*counter)++;
    } else {
      return cur;
    }
  }

  return NULL;
}

void test(){
  Avl_Node* root = NULL;
  vector<int> values{10,20,30,40,50,60,70,80,90};

  for (auto& v: values){
    root = insertNode(root, v);
  }

  int counter = 0;
  Avl_Node* result = find(root, 70, &counter);
  cout << "Find 70 in " << counter << " times. " << endl << endl;

  cout << "Pre-Traverse: " << endl;
  pre_traverse(root);
  cout << endl;
  
  cout << "Mid-Traverse: " << endl;
  mid_traverse(root);
  cout << endl;
}

int main(){
  test();
	return 0;
}
