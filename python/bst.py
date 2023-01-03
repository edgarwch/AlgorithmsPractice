

from lib2to3.pytree import Node
from logging import root


class BST:
    def __init__(self):
        self.root = None

    def insert(self, root, val):
        if(root == None):
            self.node = BST.Node(val)
            root = self.node
            return root
        else:
            if root.data == val:
                return root
            elif root.data < val:
                root.right = self.insert(root.right, val)
            elif root.data > val:
                root.left = self.insert(root.left, val)
        self.root = root
        return root
    def inorder(self, root):
        if root:
            self.inorder(root.left)
            print(root.data)
            self.inorder(root.right)

    class Node:
        def __init__(self, val):
            self.left = None
            self.right = None
            self.data = val



r = BST()
root = None
root = r.insert(root, 30)
root = r.insert(root, 50)
root = r.insert(root, 10)
r.inorder(root)