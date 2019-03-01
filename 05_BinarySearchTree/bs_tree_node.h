#ifndef BST_TREE_NODE
#define BST_TREE_NODE

template<class T>
struct BSTreeNode {
	T key;

	BSTreeNode<T>* left;
	BSTreeNode<T>* right;
	BSTreeNode<T>* parent;
};

#endif // BST_TREE_NODE
