//
//  bst.h
//  coding_pac
//
//  Created by Edgar Wong on 03/08/2022.
//

#ifndef bst_h
#define bst_h

class BST {
    int data;
    BST *left, *right;
    
public:
    BST():
    data(0),
    left(NULL),
    right(NULL)
    {}
    BST(int val)
    {
        data = val;
        left = right = NULL;
    }
    
    BST* Insert(BST* root, int val)
    {
        if (!root) {
            return new BST(val);
        }
        
        if(val > root->data)
        {
            root->right = Insert(root->right, val);
        }
        else if (val < root->data)
        {
            root->left = Insert(root->left, val);
        }
        return root;
    }
    
    void Inorder(BST* root)
    {
        if(!root)
        {
            return;
        }
        Inorder(root->left);
        cout<< root->data<<endl;
        Inorder(root->right);
    }
};

#endif /* bst_h */
