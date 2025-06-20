#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

int height(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    int left = height(node->left);
    int right = height(node->right);
    int ans = max(left, right) + 1;
    return ans;
}

int main() {
    
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    
    int treeHeight = height(root);
    cout << "Height of the binary tree is: " << treeHeight << endl;

    return 0;
}
