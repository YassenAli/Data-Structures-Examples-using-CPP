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
    int data { };
    Node* next { };
    Node(int data) : data(data) {}
    ~Node() {
        cout << "Destroy value: " << data <<" at address "<< this<< "\n";
    }
};

class LinkedList {
private:
    Node *head { };
    Node *tail { };
    int length = 0;	// let's maintain how many nodes

    vector<Node*> debug_data;	// add/remove nodes you use

    void debug_add_node(Node* node) {
        debug_data.push_back(node);
    }
    void debug_remove_node(Node* node) {
        auto it = std::find(debug_data.begin(), debug_data.end(), node);
        if (it == debug_data.end())
            cout << "Node does not exist\n";
        else
            debug_data.erase(it);
    }

public:

    // Below 2 deletes prevent copy and assign to avoid this mistake
    LinkedList() {
    }
    LinkedList(const LinkedList&) = delete;
    LinkedList &operator=(const LinkedList &another) = delete;

    void debug_print_address() {
        for (Node* cur = head; cur; cur = cur->next)
            cout << cur << "," << cur->data << "\t";
        cout << "\n";
    }

    void debug_print_node(Node* node, bool is_seperate = false) {
        if (is_seperate)
            cout << "Sep: ";
        if (node == nullptr) {
            cout << "nullptr\n";
            return;
        }
        cout << node->data << " ";
        if (node->next == nullptr)
            cout << "X ";
        else
            cout << node->next->data << " ";

        if (node == head)
            cout << "head\n";
        else if (node == tail)
            cout << "tail\n";
        else
            cout << "\n";
    }
    void debug_print_list(string msg = "") {
        if (msg != "")
            cout << msg << "\n";
        for (int i = 0; i < (int) debug_data.size(); ++i)
            debug_print_node(debug_data[i]);
        cout << "************\n"<<flush;
    }

    string debug_to_string() {
        if (length == 0)
            return "";
        ostringstream oss;
        for (Node* cur = head; cur; cur = cur->next) {
            oss << cur->data;
            if (cur->next)
                oss << " ";
        }
        return oss.str();
    }

    void debug_verify_data_integrity() {
        if (length == 0) {
            assert(head == nullptr);
            assert(tail == nullptr);
        } else {
            assert(head != nullptr);
            assert(tail != nullptr);
            if (length == 1)
                assert(head == tail);
            else
                assert(head != tail);
            assert(!tail->next);
        }
        int len = 0;
        for (Node* cur = head; cur; cur = cur->next, len++)
            assert(len < 10000);	// Consider infinite cycle?
        assert(length == len);
        assert(length == (int)debug_data.size());
    }

    ////////////////////////////////////////////////////////////

    void print() {
        for (Node* cur = head; cur; cur = cur->next)
            cout << cur->data << " " << cur << " ";
        cout << "\n";
    }

    // These 2 simple functions just to not forget changing the vector and length
    void delete_node(Node* node) {
        debug_remove_node(node);
        --length;
        delete node;
    }

    void add_node(Node* node) {
        debug_add_node(node);
        ++length;
    }

    void insert_end(int value) {
        Node* item = new Node(value);
        add_node(item);

        if (!head)
            head = tail = item;
        else
            tail->next = item, tail = item;
    }

    void insert_front(int value) {
        Node* item = new Node(value);
        add_node(item);

        item->next = head;
        head = item;

        if(length == 1)
            tail = head;
    }
    void delete_front() {
        assert(length);
        Node* cur = head->next;
        delete_node(head);
        head = cur;
    }
    ////////////////////////////////////////////////////////////
    Node* get_previous(Node *target){       // O(n) time  -  O(1) MEMORY
        for(Node *cur = head, *prv = nullptr; cur; prv = cur, cur = cur->next)
            if(cur == target)
                return prv;
        return nullptr;
    }

    Node* get_nth(int n) {		// O(n) time - O(1) memory
        int cnt = 0;
        for (Node* cur = head; cur; cur = cur->next)
            if (++cnt == n)
                return cur;

        return nullptr;
    }

    void swap_head_tail(){       // O(n) time  -  O(1) MEMORY
        if(!head || !head->next)
            return;
        Node* prv = get_previous(tail);	// node before tail
        // Let's make current head as tail
        // Link tail's previous to head
        prv->next = head;

        // Let's make current tail as head
        // Link tail to the 2nd node
        tail->next = head->next;

        head->next = nullptr;
        swap(head, tail);	// Set new head and tail

        debug_verify_data_integrity();
    }

    void rotate(int k){		// O(n) time - O(1) memory
    if(length <= 1 || k % length == 0)
    return;	// 0 or 1 elements or useless rotation
        k %= length;
        while(k--){
            Node* prevOfTail = get_previous(tail);
            prevOfTail->next = nullptr;
            tail->next = head;
            head = tail;
            tail = prevOfTail;
        }
    }
    // Create cycle then reset head/tail then disconnect the cycle
    void leftRotate(int k){		// O(n) time - O(1) memory
        if(length <= 1 || k % length == 0)
            return;	// 0 or 1 elements or useless rotation
        k %= length;	// Remove useless cycles
        Node* nth = get_nth(k);
        tail->next = head;      // create cycle

        // reset head/tail
        tail = nth;
        head = nth->next;

        //disconnect the cycle
        tail->next = nullptr;
        debug_verify_data_integrity();
    }
    void remove_duplicates(){		// O(n^2) time - O(1) memory
        if(length <= 1)
            return;
        // Just like 2 nested loops, find all duplicates and delete
        for(Node* cur1 = head; cur1; cur1 = cur1->next)
            for(Node* cur2 = cur1->next, *prv = cur1; cur2; ){
                if(cur1->data == cur2->data){
                    prv->next = cur2->next;
                    delete_node(cur2);
                    cur2 = prv->next;
                }
                else {	// normal move
                    prv = cur2;
                    cur2 = cur2->next;
                }
            }
    }

};

int main() {
    YASSIN FAST

//    solve();

    LinkedList list;

    list.insert_end(1);
//    list.print();
//    list.swap_head_tail();
//    list.print();
    list.insert_end(2);
    list.insert_end(3);
//    list.print();
//    list.swap_head_tail();
//    list.print();
    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(2);
    list.insert_end(1);
    list.insert_end(3);
    list.print();
//    list.swap_head_tail();
//    list.leftRotate(3);
    list.remove_duplicates();
    // some actions
    list.print();

//    string expected = "5 2 1 4 3";
//    string result = list.debug_to_string();
//    if (expected != result) {
//        cout << "no match:\nExpected: " <<
//             expected << "\nResult  : " << result << "\n";
//        assert(false);
//    }
    return 0;
}