#include <bits/stdc++.h>
using namespace std;

class Node
{
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;

    if (val == -1)
        root = NULL;
    else
        root = new Node(val);

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node *myleft;
        Node *myright;

        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);

        if (r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);

        p->left = myleft;
        p->right = myright;

        if (p->left)
            p.push(p->left);
        if (p->right)
            p.push(p->right);
    }

    return root;
}

void postorder(Node *root){
    if(root==NULL){
        return;
    };
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

int main()
{
    Node *root=input_tree();

    postorder(root);

    return 0;
}