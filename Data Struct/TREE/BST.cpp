#include<iostream>
#include<algorithm>
#include<cstring>
#include <random>
#include <chrono>
#include<math.h>
#include<cstdio>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<string>
#include<string.h>
#include<set>
#include<map>
#include<stack>
#include<Windows.h>

#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;


typedef struct BST {
	int id;
	int key;
	struct BST* left;
	struct BST* right;
}Bst;


Bst* create_node(int num) {
	Bst* node = (Bst*)malloc(sizeof(Bst));
	node->key = num;
	node->left = NULL;
	node->right = NULL;
	return node;
}


Bst* interative_Search(Bst* root, int k) {//使用
	while (root && k != root->key) {
		if (k < root->key) {
			root = root->left;
		}
		else {
			root = root->right;
		}
	}
	return root;
}


Bst* tree_maximum(Bst* root) {
	while (root->right!=NULL)
		root = root->right;
	return root;
}


Bst* tree_minimum(Bst* root) {
	while (root->left!= NULL)
		root = root->left;
	return root;
}



Bst* insert(Bst* root, int num) {
	Bst* node = create_node(num);
	if (!root)return node;
	Bst* p = root;
	while (1) {
		if (num < p->key) {
			if (!p->left) {
				p->left = node;
				break;
			}
			p = p->left;
		}
		else if (num > p->key) {
			if (!p->right) {
				p->right = node;
				break;
			}
			p = p->right;
		}
		else {
			cout << "ERROR!!!";
			exit(-1);
		}
	}
	return root;
}

Bst* Delete(Bst* root, int k) {
	if (!root)return root;
  //寻找删除元素的位置
	if (root->key > k) {
		root->left = Delete(root->left,k);
		return root;
	}
	else if (root->key < k) {
		root->right = Delete(root->right, k);
		return root;
	}
  //判断元素的位置属于哪种情况，具体见GLRS的297页Figure12.4
  //GLRS使用了存在父节点的结构体
	if (root->left == NULL) {
		Bst* temp = root->right;
		delete root;
		return temp;
	}
	else if (root->right == NULL) {
		Bst* temp = root->left;
		delete root;
		return temp;
	}
	else {
		Bst* succP = root;
		Bst* succ = root->right;
		while (succ->left != NULL) {
			succP = succ;
			succ = succ->left;
		}
		if (succP != root) succP->right = succ->right;
		else succP->right = succ->right;
		root->key = succ->key;
		delete succ;
		return root;
	}
}


void inorder(Bst* root) {
	if (root) {
		inorder(root->left);
		cout << root->key<<endl;
		inorder(root->right);

	}
}

int main() {
	Bst* root = NULL;
	root = insert(root, 50);
	root = insert(root, 41);
	root = insert(root, 42);
	root = insert(root, 9);
	root = insert(root, 20);
	root = insert(root, 1);
	inorder(root);
	Delete(root, 20);
	inorder(root);

}
