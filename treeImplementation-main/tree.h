#include <iostream>
#include <vector>
#include <queue>

using namespace std;
template <class T>
class Tree;

template <class T>
class TreeNode {
private:
	TreeNode<T> * left;
	TreeNode<T> * right;
	int data;

public:
	TreeNode(int el) {
		data = el;
		left = NULL;
		right = NULL;
	}

	friend class Tree<T>;
};


template<class T>
class Tree {
public:
	vector<int> myVector;
	TreeNode<T> * root;
	Tree() {
		root = NULL;
	}
	void insert(int el) {
		TreeNode<T> * newnode = new TreeNode<T>(el);
		if (!root) {
			root = newnode;
		}
		else {
			TreeNode<T> * current = root;
			while (true) {
				if (el < current->data) {
					if (current->left) {
						current = current->left;
					}
					else {
						current->left = newnode;
						break;
					}
				}
				else {
					if (current->right) {
						current = current->right;
					}
					else {
						current->right = newnode;
						break;
					}
				}
			}
		}
	}

	int height(TreeNode<T>* node){
		if(node == NULL) return 0;
		int heightLeft = height(node->left);
		int heightRight = height(node->right);
		if(heightLeft > heightRight) return heightLeft+1;
		else return heightRight+1;
	}
	vector<int> findOnlyChilds(TreeNode<T>* treeNode){
		if(treeNode == NULL) return myVector;
		if(treeNode->right && !treeNode->left || !treeNode->right&&treeNode->left){
			if(treeNode->right) myVector.push_back(treeNode->right->data);
			else myVector.push_back(treeNode->left->data);
		}	
		findOnlyChilds(treeNode->left);
		findOnlyChilds(treeNode->right);
		return myVector;
	}
};

