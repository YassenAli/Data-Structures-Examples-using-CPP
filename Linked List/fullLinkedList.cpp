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

    Node(int data) : data(data) {}

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

    void debug_print_node(Node *node, bool is_seperate = false) {
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
            assert(!tail->next);
        }
        int len = 0;
        for (Node *cur = head; cur; cur = cur->next, len++)
            assert(len < 10000);    // Consider infinite cycle?
        assert(length == len);
        assert(length == (int) debug_data.size());
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

    /////////////////////////////////////////////////////////////////

    void print() {
        Node *cur = head;
        while (cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void insert_end(int val) {
        Node *newNode = new Node(val);
        add_node(newNode);
        if (!head)
            head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insert_front(int val) {
        Node *newNode = new Node(val);
        add_node(newNode);
        newNode->next = head;
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
            delete_node(cur);
        }
    }

    void delete_last() {
        if (length <= 1)
            delete_front();
        Node *prv = head;
        while (prv->next->next)
            prv = prv->next;
        delete_node(tail);
        tail = prv;
        tail->next = nullptr;

        debug_verify_data_integrity();
    }

    void delete_nth(int n) {
        if (n < 1 || n > length)
            cout << "Error. No such nth node\n";
        else if (n == 1)
            delete_front();
        else {
            Node *prv = get_nth(n - 1);
            Node *cur = prv->next;
            prv->next = cur->next;
            bool is_tail = cur == tail;
            if (is_tail)
                tail = prv;
            delete_node(cur);
            debug_verify_data_integrity();

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
    list.delete_nth(2);
    list.print();
    return 0;
}