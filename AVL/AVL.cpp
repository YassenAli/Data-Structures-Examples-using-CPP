#include <bits/stdc++.h>

using namespace std;

#define YASSIN cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define ll long long
#define ull unsigned long long
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define N '\n'
//#define d double
#define Max (1e9 + 1)
#define Min (-1e9 - 1)
#define Yes cout<<"YES\n";
#define No cout<<"NO\n";

//void solve() {}

class AVLTree{
    struct BinaryNode{
        int data{ };
        int height{};
        BinaryNode *left{ };
        BinaryNode *right{ };

        BinaryNode(int data): data(data){}

        int ch_height(BinaryNode *node){
            if(!node)
                return -1;
            return node->height;
        }

        int update_height(){
            return height = 1 + max(ch_height(left), ch_height(right));
        }

        int balance_factor(){
            return ch_height(left) - ch_height(right);
        }
    };
    BinaryNode* root{ };

    bool search(int target, BinaryNode *node){
        if(!node)
            return false;
        if(target == node->data)
            return true;
        if(target < node->data)
            return search(target, node->left);
        return search(target, node->right);
    }

    BinaryNode* right_rotation(BinaryNode *Q){
        cout<<"right rotation "<<Q->data<<endl;
        BinaryNode *P = Q->left;
        Q->left = P->right;
        P->right = Q;
        Q->update_height();
        P->update_height();
        return P;
    }

    BinaryNode* left_rotation(BinaryNode *Q){
        cout<<"left rotation "<<Q->data<<endl;
        BinaryNode *P = Q->right;
        Q->right = P->left;
        P->left = Q;
        Q->update_height();
        P->update_height();
        return P;
    }

    BinaryNode *balance(BinaryNode *node){
        if(node->balance_factor() == -2){
            if(node->right->balance_factor() == 1)
                node->right = right_rotation(node->right);
            node = left_rotation(node->right);
        }
        else if(node->balance_factor() == 2){
            if(node->left->balance_factor() == -1)
                node->left = left_rotation(node->left);
            node = right_rotation(node->left);
        }
        return node;
    }

    BinaryNode *insert(int val, BinaryNode *node){
        if(val < node->data){
            if(!node->left)
                node->left = new BinaryNode(val);
            else
                node->left = insert(val, node->left);
        }
        else if(val > node->data) {
            if (!node->right)
                node->right = new BinaryNode(val);
            else
                node->right = insert(val, node->right);
        }
        node->update_height();
        return balance(node);
    }

    BinaryNode *min_node(BinaryNode *cur){
        while(cur && cur->left)
            cur = cur->left;
        return cur;
    }

    BinaryNode *deleteNode(int val, BinaryNode* node){
        if(!node)
            return nullptr;
        if(val < node->data)
            node->left = deleteNode(val, node->left);
        else if(val > node->data)
            node->right = deleteNode(val, node->right);
        else {
            BinaryNode *temp = node;
            if(!node->left && !node->right)
                node = nullptr;
            else if(!node->left)
                node = node->right;
            else if(!node->right)
                node = node->left;
            else {
                BinaryNode *mn = min_node(node);
                node->data = mn->data;
                node->right = deleteNode(mn->data, node->right);
                temp = nullptr;
            }
            if(temp)
                delete temp;
        }
        if(node){
            node->update_height();
            node = balance(node);
        }
        return node;
    }

    bool isBST(BinaryNode *node){
        bool leftBST = !node->left || node->data > node->left->data && isBST(node->left);
        if(!leftBST)
            return false;
        bool rightBST = !node->right || node->data < node->right->data && isBST(node->right);
        return rightBST;
    }

    void verify(){
        assert(abs(root->balance_factor()) <= 1);
        assert(isBST(root));
    }

    void printInorder(BinaryNode *node){
        if(!node)
            return;
        cout<<"left: ";
        printInorder(node->left);
        cout<<" cur:";
        cout<<node->data<<" ";
        cout<<" right:";
        printInorder(node->right);
        cout<<endl;
    }

public:
    void insert(int val){
        if(!root)
            root = new BinaryNode(val);
        else
            root = insert(val, root);
        verify();
    }

    void deleteVal(int val){
        if(root){
            root = deleteNode(val, root);
            verify();
        }
    }

    bool search(int val){
        return search(val, root);
    }

    void printInorder(){
        printInorder(root);
    }

    void level_order_traversal(){
        if(!root)
            return;
        cout<<"**************\n";
        queue<BinaryNode*> nodes_queue;
        nodes_queue.push(root);

        int level = 0;
        while(!nodes_queue.empty()){
            int sz = nodes_queue.size();

            cout<<"Level "<<level<<": ";
            while(sz--){
                BinaryNode* cur = nodes_queue.front();
                nodes_queue.pop();
                cout<<cur->data<<" ";
                if(cur->left)
                    nodes_queue.push(cur->left);
                if(cur->right)
                    nodes_queue.push(cur->right);
            }
            level++;
            cout<<endl;
        }
    }
};

int main() {
    YASSIN
    FAST
//    solve();

    AVLTree tree;

    for (int i = 0; i <= 32; ++i) {	// degenerate
        tree.insert(i);
    }
    cout<<endl<<endl<<endl;
    cout<<"in order traversal: "<<endl;
//    tree.level_order_traversal();
    tree.printInorder();
    return 0;
}