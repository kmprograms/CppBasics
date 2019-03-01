#ifndef BST_TREE
#define BST_TREE

#include <optional>
#include "bs_tree_node.h"

template <class T>
class BSTree {
private:
	BSTreeNode<T>* root;

	BSTreeNode<T>* insert_node(BSTreeNode<T>* node, const T& key);
	void traverse_nodes_in_order(BSTreeNode<T>* node);	
	BSTreeNode<T>* search_node(BSTreeNode<T>* node, const T& key);

	std::optional<T> min_node(BSTreeNode<T>* node);
	std::optional<T> max_node(BSTreeNode<T>* node);
	std::optional<T> successor(BSTreeNode<T>* node);
	std::optional<T> predecessor(BSTreeNode<T>* node);
	BSTreeNode<T>* remove(BSTreeNode<T>* node, const T& key);
public:
	void insert(const T& key);	
	void traverse_in_order();	
	bool search(const T& key);

	std::optional<T> min();
	std::optional<T> max();
	std::optional<T> successor(const T& key);
	std::optional<T> predecessor(const T& key);
	void remove(const T& key);
};

template<class T>
BSTreeNode<T> * BSTree<T>::insert_node(BSTreeNode<T>* node, const T& key) {
	if (node == nullptr)
	{
		node = new BSTreeNode<T>{};
		node->key = key;
		node->left = nullptr;
		node->right = nullptr;
		node->parent = nullptr;
	}
	else if (node->key < key)
	{
		node->right = insert_node(node->right, key);
		node->right->parent = node;
	}
	else
	{
		node->left = insert_node(node->left, key);
		node->left->parent = node;
	}

	return node;
}

template<class T>
void BSTree<T>::insert(const T& key) {
	root = insert_node(root, key);
}

template<class T>
void BSTree<T>::traverse_nodes_in_order(BSTreeNode<T>* node) {
	if (!node) {
		return;
	}

	traverse_nodes_in_order(node->left);
	std::cout << node->key << " ";	
	traverse_nodes_in_order(node->right);
}

template<class T>
void BSTree<T>::traverse_in_order() {
	traverse_nodes_in_order(root);
	std::cout << std::endl;
}

template<class T>
BSTreeNode<T>* BSTree<T>::search_node(BSTreeNode<T>* node, const T& key) {
	if (!node) {
		return nullptr;
	}
	else if (node->key == key) {
		return node;
	}
	else if (node->key < key) {
		return search_node(node->right, key);
	}
	else {
		return search_node(node->left, key);
	}
}

template<class T>
bool BSTree<T>::search(const T& key) {
	return search_node(root, key);
}


template<class T>
std::optional<T> BSTree<T>::min_node(BSTreeNode<T>* node) {
	if (!node) {
		return std::nullopt;
	}
	else if (!node->left) {
		return std::optional<T>{node->key};
	}
	else {
		return min_node(node->left);
	}
}

template<class T>
std::optional<T> BSTree<T>::max_node(BSTreeNode<T>* node) {
	if (!node) {
		return std::nullopt;
	}
	else if (!node->right) {
		return std::optional<T>{node->key};
	}
	else {
		return max_node(node->right);
	}
}

template<class T>
std::optional<T> BSTree<T>::min() {
	return min_node(root);
}

template<class T>
std::optional<T> BSTree<T>::max() {
	return max_node(root);
}

template<class T>
std::optional<T> BSTree<T>::successor(BSTreeNode<T>* node) {
	if (node->right != nullptr) {
		return min_node(node->right);
	}
	else {
		BSTreeNode<T>* parent_node = node->parent;
		BSTreeNode<T>* current_node = node;

		while (parent_node != nullptr && current_node == parent_node->right) {			
			current_node = parent_node;
			parent_node = current_node->parent;
		}

		return parent_node == nullptr ? std::nullopt : std::optional<T>{ parent_node->key };
	}
}

template<class T>
std::optional<T> BSTree<T>::successor(const T& key) {
	BSTreeNode<T>* node = search_node(root, key);
	return node == nullptr ? std::nullopt : successor(node);
}

template<class T>
std::optional<T> BSTree<T>::predecessor(BSTreeNode<T>* node) {
	if (node->left != nullptr) {
		return max_node(node->left);
	}
	else {
		BSTreeNode<T>* parent_node = node->parent;
		BSTreeNode<T>* current_node = node;

		while (parent_node != nullptr && current_node == parent_node->left) {
			current_node = parent_node;
			parent_node = current_node->parent;
		}
		return parent_node == nullptr ? std::nullopt : std::optional<T>{ parent_node->key };
	}
}

template<class T>
std::optional<T> BSTree<T>::predecessor(const T& key) {
	BSTreeNode<T>* key_node = search_node(root, key);
	return key_node == nullptr ? std::nullopt : predecessor(key_node);
}

template<class T>
BSTreeNode<T>* BSTree<T>::remove(BSTreeNode<T>* node, const T& key) {
	if (node == nullptr) {
		return nullptr;
	}

	if (node->key == key) {
		if (node->left == nullptr && node->right == nullptr) {
			node = nullptr;
		}
		else if (node->left == nullptr && node->right != nullptr) {
			node->right->parent = node->parent;
			node = node->right;
		}
		else if (node->left != nullptr && node->right == nullptr) {
			node->left->parent = node->parent;
			node = node->left;
		}
		else {
			T successor_key = successor(key).value_or(INT_MIN);
			node->key = successor_key;			
			node->right = remove(node->right, successor_key);
		}
	}
	else if(node->key < key) {
		node->right = remove(node->right, key);
	}
	else {
		node->left = remove(node->left, key);
	}
	return node;

}

template<class T>
void BSTree<T>::remove(const T& key) {
	root = remove(root, key);
}

#endif // !BST_TREE

