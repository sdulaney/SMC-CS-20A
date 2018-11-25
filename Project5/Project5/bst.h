#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include<functional>

class BinarySearchTree {
    
public:
    
    // Public Interface Functions: All of these are implemented
    BinarySearchTree();
    ~BinarySearchTree();
    
    void    printInorder();
    void    printPostorder();
    void    printPreorder();
    void    insert(int value);
    
    void    remove(int value);
    
    int        min() const;
    int        max() const;
    int        height() const;
    bool    search(int value) const;
    
    bool    isEmpty() const;
    
    void    printTree() const;
    
private:
    // Forward declare Node
    struct Node;
    
    // Member variable root
    Node* m_root;
    
    
    
    //Auxillary (helper) recursive bst functions
    //public interface functions call these
    //You will implement these functions.
    
    // Tree traversal, second parameter is a "function" with
    // return type void and parameter Node*, i.e:
    //                    void process(Node* )
    void _inorder(Node* node, std::function<void(Node*)> process);
    void _preorder(Node* node, std::function<void(Node*)> process);
    void _postorder(Node* node, std::function<void(Node*)> process);
    
    Node*    _minNode(Node *node) const;
    Node*    _maxNode(Node *node) const;
    int     _height(Node* node) const;
    
    Node*    _insert(Node *node, int value);
    Node*    _search(Node *node, int value) const;
    
    Node*    _deleteNode(Node *node, int value);
    
    void    _printTree(Node *node, int space) const;
};

#endif//BINARYSEARCHTREE_H
