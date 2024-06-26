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



struct Node {
    int data {};
    Node *next {};

    //Pointer to Same type
    Node(int data) : data(data){}

    // Function Find to find value with this signature( find(val) )
    Node* find(int val){
        Node* current = this;
        while(current != nullptr){
            if(current->data == val)
                return current;
            current = current->next;
        }
        return nullptr;
    }
};

// Print forward by while loop
void print1(Node* head){
    while(head != nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

// Print forward by for loop
void print2(Node* head){
    for(int i = 0; head != nullptr; ++i){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

// Print forward recursively
void print3(Node* head){
    if(head == nullptr) {
        cout << endl;
        return;
    }
    cout<<head->data<<" ";
    print3(head->next);
}

// Print backward recursively
void print4_reverse(Node* head){
    if(head == nullptr)
        return;
    print4_reverse(head->next);
    cout<<head->data<<" ";
}

int main() {
    YASSIN
    FAST
//    solve();

    // Create 4 objects and set data
    Node* node1 = new Node(6);
    Node* node2 = new Node(10);
    Node* node3 = new Node(8);
    Node* node4 = new Node(15);

    // Set 4 links

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = nullptr;

    // Output is 15 for all of them
    cout<<node1->next->next->next->data<<endl;  // 15
    cout<<node2->next->next->data<<endl;        // 15
    cout<<node3->next->data<<endl;              // 15
    cout<<node4->data<<endl;                    // 15
    // If you write node->next only will output address

    cout<<node1<<" "<<&node1<<" "<<node1->next<<" "<<&node1->next<<"\n";
    cout<<node2<<" "<<&node2<<" "<<node2->next<<" "<<&node2->next<<"\n";
    cout<<node3<<" "<<&node3<<" "<<node3->next<<" "<<&node3->next<<"\n";
    cout<<node4<<" "<<&node4<<" "<<node4->next<<" "<<&node4->next<<"\n";
    /*
            0x23c0a811260 0x57229ffc48 0x23c0a8115b0 0x23c0a811268
            0x23c0a8115b0 0x57229ffc40 0x23c0a8115d0 0x23c0a8115b8
            0x23c0a8115d0 0x57229ffc38 0x23c0a8115f0 0x23c0a8115d8
            0x23c0a8115f0 0x57229ffc30 0             0x23c0a8115f8
     */

    print1(node1);          // 6 10 8 15

    print2(node1);          // 6 10 8 15

    print3(node1);          // 6 10 8 15

    print4_reverse(node1);  // 15 8 10 6

    cout<<endl<<node1->find(10)->data<<endl; // 10

    return 0;
}