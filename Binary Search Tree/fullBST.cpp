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

class BST {
    int data{};
    BST *left{};
    BST *right{};

    bool find_chain(vector<BST*> &ancestors, int val){
        ancestors.push_back(this);
        if(val == data)
            return true;
        if(val < data)
            return left && left->find_chain(ancestors, val);
        return right && right->find_chain(ancestors, val);
    }

    BST* minNode(){
        BST* cur = this;
        while(cur && cur->left)
            cur = cur->left;
        return cur;
    }

    void special_delete(BST* child){
        data = child->data;
        left = child->left;
        right = child->right;
        delete child;
    }

    BST* deleteNode(int val, BST* node){
        if(!node)
            return nullptr;
        if(val < node->data)
            node->left = left->deleteNode(val, node->left);
        else if(val < node->data)
            node->right = right->deleteNode(val, node->right);
        else{
            if(!node->left && !node->right) {
                delete node;
                node = nullptr;
            }
            else if(!node->left)
                node->special_delete(node->left);
            else if(!node->right)
                node->special_delete(node->right);
            else {
                BST* mn = node->right->minNode();
                node->data = mn->data;
                node->right = deleteNode(node->data, mn);
            }
        }
        return node;
    }

public:
    BST(int data) : data(data){}

    void printInorder(){
        if(left)
            left->printInorder();
        cout<<data<<" ";
        if(right)
            right->printInorder();
    }

    void insert(int val){
        if(val < data) {
            if (!left)
                left = new BST(val);
            else
                left->insert(val);
        }
        else if(val > data){
            if(!right)
                right = new BST(val);
            else
                right->insert(val);
        }
    }

    bool search(int val){
        if(val == data)
            return true;
        if(val < data)
            return left && left->search(val);
        return right && right->search(val);
    }

    int minValue(){
        BST* cur = this;
        while(cur && cur->left)
            cur = cur->left;
        return cur->data;
    }

    BST* get_next(vector<BST*> &ancestors){
        if(ancestors.size() == 0)
            return nullptr;
        BST* node = ancestors.back();
        ancestors.pop_back();
        return node;
    }

    int successor(int val){
        vector<BST*> ancestors;
        if(!find_chain(ancestors, val))
            return 0;
        BST *child = get_next(ancestors);
        if(child->right)
            return child->right->minValue();
        BST *parent = get_next(ancestors);
        while(parent && parent->right == child)
            child = parent, parent = get_next(ancestors);
        if(parent)
            return parent->data;
        return 0;
    }

    void deleteValue(int val){
        if(val == data && !left && !right)
            return;
        deleteNode(val, this);
    }
};

int main() {
    YASSIN FAST
//    solve();



    return 0;
}