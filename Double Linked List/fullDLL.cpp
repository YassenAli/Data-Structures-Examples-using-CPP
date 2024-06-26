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

struct Node {
    int data{};
    Node *next{};
    Node* prev { };

    Node(int data) : data(data) {}

    void set(Node* next, Node* prev) {
        this->next = next;
        this->prev = prev;
    }

    ~Node() {
        cout << "Destroy value: " << data << " at address " << this << "\n";
    }
};

class LinkedList {
    Node *head{};
    Node *tail{};
    int length = 0;

    vector<Node *> debug_data;    // add/remove nodes you use

    void debug_add_node(Node *node) {
        debug_data.push_back(node);
    }

    void debug_remove_node(Node *node) {
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

    LinkedList(const LinkedList &) = delete;

    LinkedList &operator=(const LinkedList &another) = delete;

    void debug_print_address() {
        for (Node *cur = head; cur; cur = cur->next)
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

        if (node->prev == nullptr)
            cout << "X\t";
        else
            cout << node->prev->data << "\t";

        cout << " <= [" <<node->data << "]\t => \t";

        if (node->next == nullptr)
            cout << "X\t";
        else
            cout << node->next->data << "\t";

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
        cout << "************\n" << flush;
    }

    string debug_to_string() {
        if (length == 0)
            return "";
        ostringstream oss;
        for (Node *cur = head; cur; cur = cur->next) {
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
            assert(!head->prev);
            assert(!tail->next);
        }
        int len = 0;
        for (Node* cur = head; cur; cur = cur->next, len++) {
            if (len == length-1)	// make sure we end at tail
                assert(cur == tail);
        }

        assert(length == len);
        assert(length == (int )debug_data.size());

        len = 0;
        for (Node* cur = tail; cur; cur = cur->prev, len++) {
            if (len == length-1)	// make sure we end at head
                assert(cur == head);
        }
        cout << "\n";
    }

    /////////////////////////////////////////////////////////////////

    // These 2 simple functions just to not forget changing the vector and length
    void delete_node(Node *node) {
        debug_remove_node(node);
        --length;
        delete node;
    }

    void add_node(Node *node) {
        debug_add_node(node);
        ++length;
    }

    void print_reversed()  {
        for (Node* cur = tail; cur; cur = cur->prev)
            cout << cur->data << " ";
        cout << "\n";
    }

    /////////////////////////////////////////////////////////////////

    void print() {
        Node *cur = head;
        while (cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void link(Node* first, Node* second){
        if(first)
            first->next = second;
        if(second){
            second->prev = first;
        }
    }

    void insert_end(int val) {
        Node *newNode = new Node(val);
        add_node(newNode);
        if (!head)
            head = tail = newNode;
        else {
            link(tail, newNode);
            tail = newNode;
        }
    }

    void insert_front(int val) {
        Node *newNode = new Node(val);
        add_node(newNode);
        link(newNode, head);
        head = newNode;
        if (length == 1)
            tail = head;
    }

    Node *get_nth(int n) {
        int cnt = 0;
        for (Node *cur = head; cur; cur = cur->next) {
            if (++cnt == n)
                return cur;
        }
        return nullptr;
    }

    void delete_front() {
        assert(length);
        if (head) {
            Node *cur = head;
            head = head->next;
            head->prev = nullptr;
            delete_node(cur);
        }
    }

    void delete_last() {
        if (length <= 1)
            delete_front();
        Node *prv = tail->prev;
        delete_node(tail);
        tail = prv;
        tail->next = nullptr;

        debug_verify_data_integrity();
    }

    Node *delete_and_link(Node *cur){
        link(cur->prev, cur->next);
        delete_node(cur);
        return cur->prev;
    }

    void delete_node_with_key(int val) {
        if (!length)
            return;
        else if (head->data == val)
            delete_front();
        else {
            for (Node *cur = head; cur; cur = cur->next) {
                if (cur->data == val) {
                    cur = delete_and_link(cur);
                    if (!cur->next)	// we removed last node!
                        tail = cur;
                    break;
                }
            }
            debug_verify_data_integrity();
        }
    }

    void embed_after(Node *previous, int val){
        Node *mid = new Node(val);
        ++length;
        debug_add_node(mid);

        Node *after = previous->next;
        link(previous, mid);
        link(mid, after);
    }

    void insert_sorted(int val){
        if(!length || val <= head->data)
            insert_front(val);
        else if(tail->data <= val)
            insert_end(val);
        else{
            for(Node *cur = head; cur; cur = cur->next){
                if(val <= cur->data){
                    embed_after(cur->prev, val);
                    break;
                }
            }
        }
    }

    int search(int val) {
        int idx = 0;
        for (Node *cur = head; cur; cur = cur->next, ++idx) {
            if (cur->data == val)
                return idx;
        }
        return -1;
    }
};

int main() {
    YASSIN
    FAST
//    solve();
    LinkedList list;

    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(3);
    list.insert_end(4);
    list.insert_end(5);
    list.print();
    list.delete_node_with_key(2);
    list.print();
    return 0;
}