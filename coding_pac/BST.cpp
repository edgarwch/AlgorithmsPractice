//
//  BST.cpp
//  coding_pac
//
//  Created by Edgar Wong on 04/01/2023.
//

#include "BST.hpp"


void BST::init(Node *node, int key){
	node->val = key;
	node->parent = nullptr;
	node->left = nullptr;
	node->right = nullptr;
}

void BST::preOrderTravel(Node *node){
	if(node == nullptr) return;
	std::cout<<node->val<<" ";
	preOrderTravel(node->left);
	preOrderTravel(node->right);
}

void BST::postOrderTravel(Node *node){
	if(node == nullptr) return;
	postOrderTravel(node->left);
	postOrderTravel(node->right);
	std::cout<<node->val<<" ";
}

void BST::inOrderTravel(Node *node){
	if(node == nullptr) return;
	inOrderTravel(node->left);
	std::cout<<node->val<<" ";
	inOrderTravel(node->right);
}

Node* BST::searchTree(Node *node, int key){
	if(node == nullptr || node->val	== key){
		return node;
	}
	if(key < node->val){
		return searchTree(node->left, key);
	}
	else{
		return searchTree(node->right, key);
	}
	
}

Node* BST::getMaximum(Node *node){
	while(node->right != nullptr){
		node = node->right;
	}
	return node;
}

Node* BST::getMinimum(Node *node){
	while(node->left != nullptr){
		node = node->left;
	}
	return node;
}

void BST::Insert(int key){
	Node* nNode = new Node;
	nNode->parent = nullptr;
	nNode->left = nullptr;
	nNode->right = nullptr;
	nNode->val = key;
	
	Node* y = nullptr;
	Node* x = this->root;
	
	while(x != nullptr){
		y = x;
		if(nNode->val < x->val){
			x = x->left;
		}
		else{
			x = x->right;
		}
	}
	nNode->parent = y;
	if(y == nullptr){
		root = nNode;
	}
	else if(nNode->val < y->val){
		y->left = nNode;
	}
	else{
		y->right = nNode;
	}
}

void BST::Transplant(Node *u, Node *v)
{
	if(u->parent == nullptr){
		this->root = v;
	}
	else if(u->val == u->parent->left->val){
		u->parent->left = v;
	}
	else u->parent->right = v;
	if(v != nullptr){
		v->parent = u->parent;
	}
}

Node* BST::deleteNodeHelper(Node* node, int key) {
	// search the key
	if (node == nullptr) return node;
	else if (key < node->val) node->left = deleteNodeHelper(node->left, key);
	else if (key > node->val) node->right = deleteNodeHelper(node->right, key);
	else {

		// case 1: node is a leaf node
		if (node->left == nullptr && node->right == nullptr) {
			delete node;
			node = nullptr;
		}

		// case 2: node has only one child
		else if (node->left == nullptr) {
			Node* temp = node;
			node = node->right;
			delete temp;
		}

		else if (node->right == nullptr) {
			Node* temp = node;
			node = node->left;
			delete temp;
		}

		// case 3: has both children
		else {
			Node* temp = getMinimum(node->right);
			node->val = temp->val;
			node->right = deleteNodeHelper(node->right, temp->val);
		}

	}
	return node;
}

void BST::deleteNode2(Node *node, int key){
	Node* z = nullptr;
	Node* y;
	while(node != nullptr){
		if(node->val == key){
			z = node;
			break;
		}
		if(node->val < key){
			node = node->right;
		}
		if(node->val > key){
			node = node->left;
		}
	}
	
	if(z == nullptr) return;

	if(z->left == nullptr){
		Transplant(z, z->right);
	}
	else if(z->right == nullptr){
		Transplant(z, z->left);
	}
	else{
		y = getMinimum(z->right);
		if(y->val != z->right->val){
			Transplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		Transplant(z, y);
		y->left = z->left;
		y->left->parent = y;
	}
	
}
