//
//  tree.h
//  coding_pac
//
//  Created by Edgar Wong on 02/01/2023.
//

#ifndef tree_h
#define tree_h

struct TreeNode{
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): value(x), left(NULL), right(NULL){};
};

#endif /* tree_h */
