//
//  Trie.hpp
//  coding_pac
//
//  Created by Edgar Wong on 07/01/2023.
//

#ifndef Trie_hpp
#define Trie_hpp

#include <stdio.h>
#include <string>

struct TrieNode{
	TrieNode* children[26];
	bool is_leaf;
};

TrieNode* makeNode(){
	TrieNode* node = new TrieNode;
	node->is_leaf = false;
	for(int i = 0 ; i< 26; i++){
		node->children[i] = NULL;
	}
	return node;
}

void insert(TrieNode* node, std::string word){
	TrieNode* tmp = node;
	for(int i = 0; i< word.size(); i++){
		int index = word[i] - 'a';
		if(tmp->children[index] == NULL){
			tmp->children[index]= makeNode();
		}
		tmp = tmp->children[index];
	}
	tmp->is_leaf = true;
}

int countChildren(TrieNode* node, int* index){
	TrieNode* tmp = node;
	int count = 0;
	for(int i = 0; i< 26; i++){
		if(tmp->children[i]!=NULL){
			count++;
			*index = i;
		}
	}
	return count;
}

std::string tra(TrieNode* Node){
	TrieNode* tmp = Node;
	int index;
	std::string prefix;
	while(countChildren(tmp, &index) == 1 && tmp->is_leaf ==false){
		tmp = tmp->children[index];
		prefix.push_back('a' + index);
	}
	return prefix;
}





#endif /* Trie_hpp */
