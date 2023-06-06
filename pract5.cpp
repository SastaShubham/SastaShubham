
/*
 Construct an expression tree from the given prefix expression eg. +--a*bc/def and traverse it using post order traversal (non recursive) and then delete the entire tree.
 */

#include<iostream>
#include<stack>
#include<string>

using namespace std;

// Structure of the node of the expression tree
struct Node {
    char data;
    Node* left;
    Node* right;
};

// Function to create a new node of the expression tree
Node* newNode(char data) {
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to construct an expression tree from the given prefix expression
Node* constructExpressionTree(string prefix) {
    stack<Node*> s;
    int len = prefix.length();
    for (int i = len - 1; i >= 0; i--) {
        char ch = prefix[i];
        if (isdigit(ch) || isalpha(ch)) {
            s.push(newNode(ch));
        } else {
            Node* node = newNode(ch);
            node->left = s.top();
            s.pop();
            node->right = s.top();
            s.pop();
            s.push(node);
        }
    }
    return s.top();
}

// Function to traverse the expression tree in postorder without recursion
void postorderTraversal(Node* root) {
    if (root == NULL) return;
    stack<Node*> s;
    s.push(root);
    Node* prev = NULL;
    while (!s.empty()) {
        Node* curr = s.top();
        if (prev == NULL || prev->left == curr || prev->right == curr) {
            if (curr->left) {
                s.push(curr->left);
            } else if (curr->right) {
                s.push(curr->right);
            }
        } else if (curr->left == prev) {
            if (curr->right) {
                s.push(curr->right);
            }
        } else {
            cout << curr->data << " ";
            s.pop();
        }
        prev = curr;
    }
    cout << endl;
}

// Function to delete the expression tree
void deleteTree(Node* root) {
    if (root == NULL) return;
    stack<Node*> s;
    s.push(root);
    Node* prev = NULL;
    while (!s.empty()) {
        Node* curr = s.top();
        if (prev == NULL || prev->left == curr || prev->right == curr) {
            if (curr->left) {
                s.push(curr->left);
            } else if (curr->right) {
                s.push(curr->right);
            }
        } else if (curr->left == prev) {
            if (curr->right) {
                s.push(curr->right);
            }
        } else {
            delete curr;
            s.pop();
        }
        prev = curr;
    }
}

int main() {
    string prefix = "+--a*bc/def";
    Node* root = constructExpressionTree(prefix);
    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    deleteTree(root);
    return 0;
}
