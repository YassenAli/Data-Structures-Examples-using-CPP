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
//    ~Node(){
//        cout<<"Destroy value: "<<data<<" at address "<<this<<endl;
//    }
};

class LinkedList {
private:
    Node *head{};
    Node *tail{};
    int length = 0;        // let's maintain how many nodes

public:
    void print() {
        // DON'T change head itself
        for (Node* cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }

    void insert_front(int val){		// O(1) time - O(1) memory
        Node *newNode = new Node(val);
        if(!head){
            head = tail = newNode;
            head->next = tail->next = nullptr;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        ++length;
    }

    void delete_first(){
        if(head) {
            Node *cur = head->next;
            delete head;
            head = cur;

            if(!head)
                tail = nullptr;
        }
        else{
            cout<<"linked list has no item to delete it";
        }
    }

    Node *get_nth(int n) {
        int cnt = 0;
        for (Node* cur = head; cur; cur = cur->next)
            if (++cnt == n)
                return cur;

        return nullptr;
    }

    void delete_last(){
        if(length <= 1){
            delete_first();
            return;
        }
        // Get the node before tail: its order is length-1 node
        Node* previous = get_nth(length - 1);
        delete tail;
        tail = previous;
        tail->next = nullptr;
    }

    void delete_nth_node(int n){
        if(n < 1 || n > length){
            return;
        }
        // Connect the node before nth with node after nth
        Node *previous = get_nth(n-1);
        Node *cur = previous->next;
        bool is_tail = get_nth(n) == tail;
        // connect before node with after
        previous->next = cur->next;
        if(is_tail){
            tail = previous;
        }
        delete cur;
    }

    // Bug fixing for this function
    void delete_next_node(Node* node) {
        Node* to_delete = node->next;
        bool is_tail = to_delete == tail;
        // node->next in middle to delete
        node->next = node->next->next;
        delete to_delete;

        if(is_tail)
            tail = node;
    }

    void delete_node_with_key(int val){
        if (!length)
            cout << "Empty list!\n";
        else if (head->data == val)
            delete_first();
        else {
            Node *cur = head;
            for (; cur->next->data != val; cur = cur->next);
            Node *previous = cur;
            cur = cur->next;
            bool is_tail = cur == tail;
            if (is_tail) {
                previous->next = nullptr;
                tail = previous;
            } else previous->next = cur->next;
            delete cur;
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
    YASSIN FAST

//    solve();

    LinkedList list;
    list.insert_front(5);
    list.insert_front(15);
    list.insert_front(25);
    list.insert_front(35);
    list.insert_front(45);
    cout<<"linked list: ";
    list.print();
    list.delete_last();
    cout<<endl<<"after deleted last element: ";
    list.print();
    list.delete_nth_node(2);
    cout<<endl<<"after deleted second element: ";
    list.print();
    list.delete_first();
    cout<<endl<<"after deleted first element: ";
    list.print();
    list.insert_front(55);
    list.insert_front(65);
    list.insert_front(55);
    list.insert_front(35);
    list.print();
    list.delete_node_with_key(15);
    cout<<endl<<"after deleted value 15: ";
    list.print();
    return 0;
}