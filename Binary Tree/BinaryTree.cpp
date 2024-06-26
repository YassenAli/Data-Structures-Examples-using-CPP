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

class BinaryTree {
private:
    int data{};
    BinaryTree *left{};
    BinaryTree *right{};

public:
    BinaryTree(int data) : data(data) {}

    void print_inorder() {
        if (left)
            left->print_inorder();
        cout<<data<<" ";
        if(right)
            right->print_inorder();
    }

    void add(vector<int> values, vector<char> direction) {
        assert(values.size() == direction.size());
        BinaryTree *cur = this;
        for (int i = 0; i < values.size(); ++i) {
            if (direction[i] == 'L') {
                if (!cur->left)
                    cur->left = new BinaryTree(values[i]);
                else
                    assert(cur->left->data == values[i]);
                cur = cur->left;
            } else {
                if (!cur->right)
                    cur->right = new BinaryTree(values[i]);
                else
                    assert(cur->right->data == values[i]);
                cur = cur->right;
            }
        }
    }

    void level_order_traversal1(){
        queue<BinaryTree*> nodes_queue;
        nodes_queue.push(this);

        while(!nodes_queue.empty()){
            BinaryTree* cur = nodes_queue.front();
            nodes_queue.pop();

            cout<<cur->data<<" ";
            if(cur->left)
                nodes_queue.push(cur->left);
            if(cur->right)
                nodes_queue.push(cur->right);
        }
        cout<<"\n";
    }

    void level_order_traversal2(){
        queue<BinaryTree*> nodes_queue;
        nodes_queue.push(this);

        int level = 0;
        while (!nodes_queue.empty()) {
            int sz = nodes_queue.size();

            cout<<"Level "<<level<<": ";
            while(sz--) {
                BinaryTree*cur = nodes_queue.front();
                nodes_queue.pop();

                cout << cur->data << " ";
                if (cur->left)
                    nodes_queue.push(cur->left);
                if (cur->right)
                    nodes_queue.push(cur->right);
            }
            level++;
            cout << "\n";
        }

    }

};

int main() {
    YASSIN
    FAST

//    solve();

    BinaryTree tree(1);

    tree.add( { 2, 4, 8 }, { 'L', 'L', 'L' });
    tree.add( { 2, 4, 9 }, { 'L', 'L', 'R' });
    tree.add( { 2, 5, 10 }, { 'L', 'R', 'L' });
    tree.add( { 2, 5, 11 }, { 'L', 'R', 'R' });

    tree.add( { 3, 6, 12 }, { 'R', 'L', 'L' });
    tree.add( { 3, 6, 13 }, { 'R', 'L', 'R' });
    tree.add( { 3, 7, 14 }, { 'R', 'R', 'L' });
    tree.add( { 3, 7, 15 }, { 'R', 'R', 'R' });

    tree.level_order_traversal1();
    // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
    tree.level_order_traversal2();
    // Level 0: 1
    // Level 1: 2 3
    // Level 2: 4 5 6 7
    // Level 3: 8 9 10 11 12 13 14 15

    return 0;
}