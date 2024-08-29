#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* input_tree() {
    int val;
    cin >> val;
    Node *root;

    if (val == -1) root = NULL;
    else root = new Node(val);

    queue<Node*> q;
    if (root) q.push(root);
    while (!q.empty()) {
        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node *left;
        Node *right;
        if (l == -1) left = NULL;
        else left = new Node(l);

        if (r == -1) right = NULL;
        else right = new Node(r);

        p->left = left;
        p->right = right;

        if (p->left) q.push(p->left);
        if (p->right) q.push(p->right);
    }

    return root;
}

int find_depth(Node* root) {
    int depth = 0;
    while (root != NULL) {
        depth++;
        root = root->left;
    }
    return depth;
}

bool is_perfect_util(Node* root, int depth, int level = 0) {
    if (root == NULL)
        return true;

    if (root->left == NULL && root->right == NULL)
        return depth == level + 1;

    if (root->left == NULL || root->right == NULL)
        return false;

    return is_perfect_util(root->left, depth, level + 1) && 
           is_perfect_util(root->right, depth, level + 1);
}

bool is_perfect_tree(Node* root) {
    int depth = find_depth(root);
    return is_perfect_util(root, depth);
}

int main() {
    Node *root = input_tree();
    if (is_perfect_tree(root))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
