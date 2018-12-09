#include"bst.h"
#include<functional>
#include<iostream>
#include<assert.h>

// Node implementation: Implemented
struct BinarySearchTree::Node {
    Node(int v, Node *l, Node *r) :value(v), left(l), right(r) {}
    Node() :Node(0, nullptr, nullptr) {}
    
    int value;
    Node *left, *right;
};

//----------------------------------------------------------
//-------------- Binary Search Tree Function Implementations
//--
//-- Public Interface functions
//--        Completley Implemented, nothing to do.  These functions
//--        call the recursive helper functions you will implement.
//--
// Constructor
BinarySearchTree::BinarySearchTree() :m_root(nullptr) {}

// Destructor
BinarySearchTree::~BinarySearchTree() {
    
    //Use the post order traversal to delete the nodes.
    //lambda function to delete a node n:
    //                [](Node* n) {delete n; }
    _postorder(m_root, [](Node* n) {delete n; });
}

void BinarySearchTree::printInorder(){
    
    //Use inorder traversal to print values in a node in the tree.
    //lambda function to print the value in a node:
    //                [](Node* n) {std::cout << n->value << std::endl; }
    _inorder(m_root, [](Node* n) {std::cout << n->value << " "; });
    std::cout << std::endl;
}
void BinarySearchTree::printPreorder() {
    
    //Use pre order traversal to print values in a node in the tree.
    //lambda function to print the value in a node:
    //                [](Node* n) {std::cout << n->value << std::endl; }
    _preorder(m_root, [](Node* n) {std::cout << n->value << " "; });
    std::cout << std::endl;
}
void BinarySearchTree::printPostorder(){
    
    //Use post order traversal to print values in a node in the tree.
    //lambda function to print the value in a node:
    //                [](Node* n) {std::cout << n->value << std::endl; }
    _postorder(m_root, [](Node* n) {std::cout << n->value << " "; });
    std::cout << std::endl;
}
void BinarySearchTree::insert(int value) {
    m_root = _insert(m_root, value);
}
void BinarySearchTree::remove(int value) {
    m_root = _deleteNode(m_root, value);
}
int    BinarySearchTree::min() const {
    
    assert(m_root != nullptr);
    
    Node *node = _minNode(m_root);
    return node->value;
}
int    BinarySearchTree::max() const {
    
    assert(m_root != nullptr);
    
    Node *node = _maxNode(m_root);
    return node->value;
}
int    BinarySearchTree::height() const {
    
    return _height(m_root);
}
bool BinarySearchTree::search(int value) const {
    Node *node = _search(m_root, value);
    return (node != nullptr);
}

bool BinarySearchTree::isEmpty() const {
    return (m_root == nullptr);
}

void BinarySearchTree::printTree() const {
    
    _printTree(m_root,0);
}

//----------------------------------------------------------
//--
//-- Private Helper Recursive Functions
//--


// Inorder Traversal: Implemented so you can see how passing a function into
// another function works, other traversals left for you to implement.  the second
// parameter, process, is a function and we see that its return type is void and it
// has a Node* as a parameter.  Any function of that form passed into _inorder will be
// called as seen below.
void BinarySearchTree::_inorder(Node* node, std::function<void(Node*)> process) {
    if (node == nullptr) return;
    
    _inorder(node->left, process);
    process(node);
    _inorder(node->right, process);
    
}

void BinarySearchTree::_postorder(Node* node, std::function<void(Node*)> process) {
    
    // *********** TODO *************
    
    
    
}

void BinarySearchTree::_preorder(Node* node, std::function<void(Node*)> process) {
    
    // *********** TODO *************
    
    
    
}

// BinarySearchTree::_insert recursively inserts into the BST according
// to the rules of the BST.
BinarySearchTree::Node* BinarySearchTree::_insert(Node *node, int value) {
    if (node == nullptr) {
        return new Node(value, nullptr, nullptr);
    }
    if (value == node->value) {
        return node;
    }
    if (value < node->value) {
        if (node->left != nullptr) {
            _insert(node->left, value);
        }
        else {
            node->left = new Node(value, nullptr, nullptr);
        }
        return node;
    }
    // else value > node->value
    if (node->right != nullptr) {
        _insert(node->right, value);
    }
    else {
        node->right = new Node(value, nullptr, nullptr);
    }
    return node;
}

// BinarySearchTree::_search recursively searches the tree for value.
BinarySearchTree::Node* BinarySearchTree::_search(Node *node, int value) const {
    
    // *********** TODO *************
    
    
    
    return nullptr;
}

// BinarySearchTree::_height
// Height of a binary tree is the height of the largest subtree + 1
// An empty tree has height 0;
int    BinarySearchTree::_height(Node* node) const {
    // Base case: an empty tree has height 0
    if (node == nullptr) {
        return 0;
    }
    // Return the max height between the left and right subtrees plus 1 for the current node
    return std::max(_height(node->left), _height(node->right)) + 1;
}

// BinarySearchTree::_min recursively obtain the node with the minimum value
BinarySearchTree::Node*    BinarySearchTree::_minNode(Node *node) const  {
    if (node->left == nullptr) {
        return node;
    }
    return _minNode(node->left);
}

// BinarySearchTree::_max recursively obtain the node with the minimum value
BinarySearchTree::Node*    BinarySearchTree::_maxNode(Node *node) const {
    if (node->right == nullptr) {
        return node;
    }
    return _maxNode(node->right);
}

// BinarySearchTree::_printTree
// Prints the BST in a tree format rotated -90 degrees.  Uses space to
// signify the space between levels of the tree. Uses the inorder
// traversal but traverses right first, rather than left. Cannot use
// any of the other travel functions because of this.
//
// parameter space determines the number of spaces needed for each level.
// Example binary shows 5 spaces between levels.
//
// i.e. traverse right
//        print appropriate number of spaces
//        print value
//        traverse left
void BinarySearchTree::_printTree(Node *node, int space = 0) const {
    
    // *********** TODO *************
    
    
    
    
    
}


//BinarySearchTree::_deleteNode
//
// Make sure you're comfortable with the iterative solution seen in the lecture slides
// before thinking about how to do it recursively.
//
// Recursively removes a node in the binary tree.  The recursive algorithm will
// be different than the iterative algorithm.  The iterative algorithm conisted
// of first finding the node using two pointers so that we know how to rearrange
// the children of the deleted node. In recursion we are passing in the sub trees
// each recursive step, so by definition we already have a handle on each subtrees'
// parents (it is the node that is passed into the previous recursive step).
// After we find the node to remove (if it is in the tree) everything else is the same, we
// handle the three cases: leaf, one child (which consist of two cases: left vs right),
// and two children.  With iterative algorithm there were subcases regardling if the
// node was root or not, with recursion we get that for free.
//
// In the iterative algorithm discussed in class, in dealing with a node with two children
// We swapped values from one of the nodes in either subtree.  For the recursive algorithm
// We just want to write the subtree node's value into the node to be deleted, not actually
// swap. This way subtree remains a valid bst, so we can recurse on that subtree and
// recursively call _deleteNode on that value (not the original) to remove that node.
//
// It takes a bit to wrap your head around this, use the 6 steps, draw lots of pictures.
//
// Bonus: recall that in the case of the two children node, we have a choice between
// choosing a node in the left subtree or right subtree.  Either choice is correct so you
// can always choose one or the other.  However, you could make your algorithm slightly
// more sophisticed in that you can have decide on which subtree to choose based on
// the height or max depth of the either subtree. I'll leave it to you to reason about this.
//
BinarySearchTree::Node*    BinarySearchTree::_deleteNode(Node *node, int value) {
    
    // *********** TODO *************
    
    
    
    
    
    return nullptr; // parent node can update reference
    
}


