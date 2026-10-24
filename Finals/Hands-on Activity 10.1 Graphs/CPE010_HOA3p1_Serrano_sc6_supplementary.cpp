#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* newNode(int value) {
    TreeNode* node = new TreeNode();
    node->val = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void preorder(TreeNode* node){
    if (node == nullptr) return;
    std::cout << node->val << " ";
    preorder(node->left);
    preorder(node->right);
}


int main(){
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    std::cout << "Preorder:  ";
    preorder(root);
    std::cout << std::endl;
    
    return 0;
}