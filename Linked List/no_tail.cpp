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
    int data{};
    Node *next{};

    // Pointer to Same type
    Node(int data) : data(data) {}
    ~Node(){
        cout<<"Destroy value: "<<data<<" at address "<<this<<endl;
    }
};

class LinkedList {
private:
    Node *head{};
//    Node *tail{};
//    int length = 0;        // let's maintain how many nodes

public:
    void print() {
        // DON'T change head itself
        for (Node* cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }

    void add_element(int val){
        Node* cur = new Node(val);
        cur->next = head;
        head = cur;
    }

    Node* get_tail(){		// O(n) time - O(1) memory
        if(!head)
            return nullptr;
        Node* cur = head;

        // stop at cur->next, as this will be the tail
        while(cur){
            if(!cur->next){
                return cur;
            }
            cur = cur->next;
        }
    }

//    ~LinkedList(){
//        // O(n) time - O(1) memory
//        // idea: get next first, remove current head
//        while(head){
//            Node* cur = head->next;
//            delete head;
//            head = cur;
//        }
//    }
};

int main() {
    YASSIN
    FAST

//    solve();

    LinkedList list;
    list.add_element(10);
    list.add_element(20);
    list.add_element(30);
    list.add_element(40);
    list.add_element(50);
    list.add_element(60);

    list.print();	// 60 50 40 30 20 10
    cout<<list.get_tail()->data<<endl;	// 10

    return 0;
}