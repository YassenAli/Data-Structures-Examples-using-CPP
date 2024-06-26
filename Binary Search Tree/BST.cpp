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


class BinarySearchTree {
private:
    int data{};
    BinarySearchTree *left{};
    BinarySearchTree *right{};

    bool find_chain(vector<BinarySearchTree*> &ancestors, int val){
        ancestors.push_back(this);
        if(val == data)
            return true;

        if(val < data)
            return left && left->find_chain(ancestors, val);

        return right && right->find_chain(ancestors, val);
    }

    BinarySearchTree* min_node(){
        BinarySearchTree* cur = this;
        while(cur && cur->left)
            cur = cur->left;
        return cur;
    }

    void special_delete(BinarySearchTree* child){
        // Instead of deleting node and return its child
        // copy child data and remove him
        // why? as sometimes node is actually the original this
        // Deleting it is RTE
        // This is another complication we pay for our coding style
        // to use only a single class instead of class + struct like linkedlist
        data = child->data;
        left = child->left;
        right = child->right;
        delete child;
    }

    // Delete the target node in the tree and return updated tree
    // Caller use updated tree to re-link with children!
    BinarySearchTree* delete_node(int val, BinarySearchTree* node){
        if(!node)
            return nullptr;

        if(val < node->data)
            node->left = delete_node(val, node->left);
        else if(val > node->data)
            node->right = delete_node(val, node->right);
        else {
            // found the node: Handle deletion
            BinarySearchTree* tmp = node;

            if(!node->left && !node->right)
                node = nullptr;
            else if(!node->left)
                node->special_delete(node->right);		// connect with child
            else if(!node->right)
                node->special_delete(node->left);		// connect with child
            else{   // 2 children use successor
                BinarySearchTree* mn = node->right->min_node();
                node->data = mn->data;
                node->right = delete_node(node->data, node->right);
                tmp = nullptr;
            }
            if(tmp)
                delete tmp;
        }
        return node;
    }

public:

    BinarySearchTree(int data) :
            data(data) {
    }

    void get_inorder(vector<int>& values) {
        if (left)
            left->get_inorder(values);
        values.push_back(data);
        if (right)
            right->get_inorder(values);
    }

    void print_inorder() {
        if (left)
            left->print_inorder();
        cout << data << " ";
        if (right)
            right->print_inorder();
    }
    ////////////////////////////////////////////
    bool search(int val){
        if(val == this->data)
            return true;
        else if(val < this->data)
            return left && left->search(val);
        return right && right->search(val);
    }

    void insert(int val){
        if(val < data){
            if(!left)
                left = new BinarySearchTree(val);
            else
                left->insert(val);
        }
        else if(val > data){
            if(!right)
                right = new BinarySearchTree(val);
            else
                right->insert(val);
        }
//        else: already exits
    }

    int min_value(){
        BinarySearchTree* cur = this;
        while(cur && cur->left)
            cur = cur->left;
        return cur->data;
    }

    void delete_value(int val){
        if(val == data && !left && !right)
            return ; // can't remove root in this structure
        delete_node(val, this);
    }

    /*
     Problem #1: Iterative Search
        ● bool search_iterative(int target)
        ● The same logic as our search but iterative
     */
    bool search_iterative(int target){
        for(BinarySearchTree* cur(this); cur; ){
            if(target == cur->data)
                return true;
            else if(target < cur->data)
                if(left)
                    cur = cur->left;
                else
                if(right)
                    cur = cur->right;
        }
        return false;
    }

    /*
     Problem #2: Is BST?
        ● bool is_bst()
        ● The function returns true if the current binary tree is BST
        ● Describe 2 fundamentally different approaches to check that
            ○ E.g. don’t do it recursive then iterative. This is same idea with different implementation
     */
    bool is_bst2(){
        vector<int> values;
        get_inorder(values);

        for(int i = 1; i < values.size(); ++i)
            if(values[i] < values[i-1])
                return false;
        return true;
    }

    // for keep going up
    BinarySearchTree* get_next(vector<BinarySearchTree*> &ancestors) {
        if (ancestors.size() == 0)
            return nullptr;
        BinarySearchTree* node = ancestors.back();
        ancestors.pop_back();
        return node;
    }

    pair<bool, int> successor(int val){
        vector<BinarySearchTree*> ancestors;

        if(!find_chain(ancestors, val)) //not exist
            return make_pair(false, -1);

        BinarySearchTree* child = get_next(ancestors);

        if(child->right)
            return make_pair(true, child->right->min_value());

        BinarySearchTree* parent = get_next(ancestors);

        while(parent && parent->right == child)
            child = parent, parent = get_next(ancestors);

        if (parent)
            return make_pair(true, parent->data);

        return make_pair(false, -1);
    }
};

BinarySearchTree* GetTree1() {
    BinarySearchTree* tree = new BinarySearchTree(50);
    tree->insert(20);
    tree->insert(60);
    tree->insert(15);
    tree->insert(45);
    tree->insert(70);
    tree->insert(35);
    tree->insert(73);

    tree->insert(14);
    tree->insert(16);
    tree->insert(36);
    tree->insert(58);
    return tree;
}

int main() {
    YASSIN
    FAST
//    solve();

//    BinarySearchTree tree(50);
//    tree.insert(20);
//    tree.insert(45);
//    tree.insert(70);
//    tree.insert(73);
//    tree.insert(35);
//    tree.insert(15);
//    tree.insert(60);

//    tree.print_inorder();
//    if(tree.search(70)) cout<<" true"<<endl;
//    if(tree.search_iterative(70)) cout<<" true"<<endl;
//    if(!tree.search_iterative(80)) cout<<" false"<<endl;

//    vector<int> v { 15, 20, 35, 45, 50, 60, 70, 73, 100 };
//
//    for (int i = 0; i < v.size(); ++i) {
//        cout << v[i] << " ";
//        pair<bool, int> p = tree.successor(v[i]);
//
//        if (p.first)
//            cout << p.second << "\n";
//        else
//            cout << "NA\n";
//
//    }


    BinarySearchTree* tree = GetTree1();

    vector<int> inorder;
    tree->get_inorder(inorder);

    for (int i = 0; i < (int) inorder.size(); ++i) {
        if (inorder[i] == 50)
            continue;	// root

        vector<int> inorder_v2;
        BinarySearchTree* tree = GetTree1();
        tree->delete_value(inorder[i]);
        tree->get_inorder(inorder_v2);

        vector<int> inorder_cpy = inorder;
        inorder_cpy.erase(find(inorder_cpy.begin(), inorder_cpy.end(), inorder[i]));
        assert(inorder_cpy == inorder_v2);
    }


    return 0;
}