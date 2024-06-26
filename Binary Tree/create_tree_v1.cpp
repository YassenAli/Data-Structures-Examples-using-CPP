#include <bits/stdc++.h>

using namespace std;

#define YASSIN cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define ll long long
#define ull unsigned long long
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define N '\n'
#define d double
#define Max (1e9 + 1)
#define Min (-1e9 - 1)
#define Yes cout<<"YES\n";
#define No cout<<"NO\n";

//void solve() {}

class BinaryTree{
private:
    struct Node{
        int data { };
        Node* left{ };
        Node* right{ };
        Node(int data) : data(data){}
    };
    Node* root;

    void print_inorder(Node* cur){
        if(!cur)
            return;
        print_inorder(cur->left);
        cout<<cur->data<<" ";
        print_inorder(cur->right);
    }

public:
    BinaryTree(int root_val) : root(new Node(root_val)){}

    void print_inorder(){
        print_inorder(root);
        cout<<endl;
    }

    void add(vector<int> values, vector<char> direction){
        assert(values.size() == direction.size());
        Node* cur = this->root;
        for(int i = 0; i < values.size(); ++i){
            if(direction[i] == 'L'){
                if(!cur->left)
                    cur->left = new Node(values[i]);
                else
                    assert(cur->left->data == values[i]);
                cur = cur->left;
            }
            else {
                if(!cur->right)
                    cur->right = new Node(values[i]);
                else
                    assert(cur->right->data == values[i]);
                cur = cur->right;
            }
        }
    }

};

int main() {
    YASSIN FAST

//    solve();

    BinaryTree tree(1);
    tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
    tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
    tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
    tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });

    tree.print_inorder();
    // 7 4 8 2 5 9 1 3 10 6

    return 0;
}