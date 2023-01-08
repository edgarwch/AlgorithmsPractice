//
//  BST.hpp
//  coding_pac
//
//  Created by Edgar Wong on 04/01/2023.
//

#ifndef BST_hpp
#define BST_hpp

#include <stdio.h>
#include <string>
#include <iostream>

struct Node{
	int val;
	Node *parent;
	Node *left;
	Node *right;
};

class BST{
private:
	Node* root;
	
	void init(Node* node, int key);
	
	void preOrderTravel(Node* node);
	
	void postOrderTravel(Node* node);
	
	void inOrderTravel(Node* node);
	
	Node* searchTree(Node* node, int key);
	
	Node* deleteNode(Node* node, int key);
	
	void printTree(Node* root, std::string indent, bool last);
	
	Node* getMinimum(Node* node);
	
	Node* getMaximum(Node* node);
	
	void Transplant(Node* u, Node* v);
	
	Node* deleteNodeHelper(Node* node, int key);

	void deleteNode2(Node* node, int key);
	
	void printHelper(Node* root, std::string indent, bool last) {
		// print the tree structure on the screen
		if (root != nullptr) {
		   if (last) {
			  std::cout<<"└────";
			  indent += "     ";
		   } else {
			  std::cout<<"├────";
			  indent += "|    ";
		   }

		   std::cout<<root->val<<std::endl;

		   printHelper(root->left, indent, false);
		   printHelper(root->right, indent, true);
		}
	}
public:
	BST(){
		root = nullptr;
	}
	
	void createSampleTree1() {
		Node* node50 = new Node;
		init(node50, 50);
		Node* node30 = new Node;
		init(node30, 30);
		Node* node70 = new Node;
		init(node70, 70);

		node30->parent = node50;
		node70->parent = node50;
		node50->left = node30;
		node50->right = node70;

		Node* node23 = new Node;
		init(node23, 23);
		Node* node35 = new Node;
		init(node35, 35);

		node23->parent = node30;
		node35->parent = node30;
		node30->left = node23;
		node30->right = node35;

		Node* node11 = new Node;
		init(node11, 11);
		Node* node25 = new Node;
		init(node25, 25);

		node11->parent = node23;
		node25->parent = node23;
		node23->left = node11;
		node23->right = node25;

		Node* node31 = new Node;
		init(node31, 31);
		Node* node42 = new Node;
		init(node42, 42);

		node31->parent = node35;
		node42->parent = node35;
		node35->left = node31;
		node35->right = node42;

		Node* node80 = new Node;
		init(node80, 80);

		node80->parent = node70;
		node70->right = node80;

		Node* node73 = new Node;
		init(node73, 73);
		Node* node85 = new Node;
		init(node85, 85);

		node73->parent = node80;
		node85->parent = node80;
		node80->left = node73;
		node80->right = node85;

		this->root = node50;
	}
	
	void Insert(int key);
	
	Node* Successor(Node* node);
	
	Node* Predecessor(Node* node);
	
	Node* deleteNode(int data) {
		return deleteNodeHelper(this->root, data);
	}
	void deleteNode2(int data) {
		deleteNode2(this->root, data);
	}
	
	void prettyPrint() {
		printHelper(this->root, "", true);
	}
	
	void printRoot(){
		std::cout<<root->val;
	}
};

#endif /* BST_hpp */
