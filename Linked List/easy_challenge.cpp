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

    void insert_end(int value) {
        Node* item = new Node(value);
        if (!head)
            head = tail = item;
        else
            tail->next = item, tail = item;
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

    void swap_pairs(){		// O(n) time - O(1) memory
//        if(!length)
//            cout<<"Empty!";
//        else if(length == 1)
//            return;
//        else {
        // For each 2 consecutive, swap data and jump cur->next->next
        for (Node* cur = head; cur; cur = cur->next){
            if(cur->next) {
                swap(cur->data, cur->next->data);
                cur = cur->next;
            }
        }
//        }
    }

    void reverse(){		// O(n) time - O(1) memory
        LinkedList other;
        for(Node* cur = head; cur; cur = cur->next){
            other.insert_front(cur->data);
        }
        swap(other, *this);
    }

    void reverse2() {		// O(n) time - O(1) memory
        if (length <= 1)
            return;

        tail = head;
        Node *prv = head;
        head = head->next;
        while (head) {
            // store & reverse link
            Node* next = head->next;
            head->next = prv;

            // move step
            prv = head;
            head = next;
        }
        // Finalize head and tail
        head = prv;
        tail->next = nullptr;
    }

    void delete_next_node(Node* node) {
        // Delete the next of the current node
        // Handle if next is tail case
        assert(node);

        Node* to_delete = node->next;
        bool is_tail = to_delete == tail;

        // node->next in middle to delete
        node->next = node->next->next;

        delete to_delete;
        if (is_tail)
            tail = node;
    }

    void delete_even_positions() {		// O(n) time - O(1) memory
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        Node* cur = head;
        while (cur && cur->next) {
            Node* to_delete = cur->next;
            cur->next = cur->next->next;
            delete to_delete;
            cur = cur->next;
        }
    }

    void insert_sorted(int val){		// O(n) time - O(1) memory
        // 3 special cases for simplicity
        if(!head || val <= head->data)
            insert_front(val);
        else if (tail->data <= val)
            insert_end(val);
        else {
            Node* newNode = new Node(val);
            Node *cur = head;
            while (cur->next && cur->next->data < val)
                cur = cur->next;
            newNode->next = cur->next;
            cur->next = newNode;
        }
        ++length;
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
    list.insert_front(55);
    list.insert_front(55);
    cout<<"linked list: ";
    list.print();
    list.reverse();
    list.print();
    list.reverse2();
    list.print();
    cout<<"\n\ndeleted even position: \n";
    list.delete_even_positions();
    list.print();

    LinkedList list2;
    list2.insert_sorted(10);
    list2.insert_sorted(2);
    list2.insert_sorted(30);
    list2.insert_sorted(4);
    list2.insert_sorted(1);
    list2.print();



    return 0;
}