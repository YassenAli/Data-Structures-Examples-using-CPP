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
    Node *head{};
    Node *tail{};
    int length = 0;    // let's maintain how many nodes

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

    ////////////////////////////////////////////////////////////

    void print() {
        for (Node *cur = head; cur; cur = cur->next)
            cout << cur->data << " " ;//<< cur << " ";
        cout << "\n";
    }

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

    void insert_end(int value) {
        Node *item = new Node(value);
        add_node(item);

        if (!head)
            head = tail = item;
        else
            tail->next = item, tail = item;
    }

    void insert_front(int value) {
        Node *item = new Node(value);
        add_node(item);

        item->next = head;
        head = item;

        if (length == 1)
            tail = head;
    }

    void delete_front() {
        assert(length);
        Node *cur = head->next;
        delete_node(head);
        head = cur;
    }

    int size(){
        return length;
    }
};

class Queue{
private:
    LinkedList list;
    int size { };
//    int front { };
//    int rear { };
    int addedElements { };
//    int *arr { };
public:
    Queue(int size) : size(size){
//        arr = new int[size];
    }

//    ~Queue(){
//        delete[] arr;
//    }

    int next(int pos){
        ++pos;
        if(pos == list.size())     // efficient way
            pos = 0;
        return pos;
        //return (pos + 1) % size;	//  Or shorter way
    }

    void enqueue(int val){
        list.insert_end(val);
        ++addedElements;
    }

    int dequeue(){
        list.delete_front();
        --addedElements;
    }

    void display(){
        list.print();
    }

    bool isEmpty(){
        return list.size() == 0;
    }

    bool isFull(){
        return addedElements == size;
    }
};

int main() {
    YASSIN FAST
//    solve();

    Queue qu(6);
    assert(qu.isEmpty());
    qu.display();

    for (int i = 1; i <= 6; ++i) {
        assert(!qu.isFull());
        qu.enqueue(i);
        qu.display();
    }
    assert(qu.isFull());

    for (int i = 1; i <= 6; ++i) {
        assert(!qu.isEmpty());
        qu.dequeue();
        //qu.display();
    }

    for (int i = 1; i <= 6; ++i) {
        assert(!qu.isFull());
        qu.enqueue(i);
        qu.display();
    }

    qu.dequeue();
    assert(!qu.isFull());
    qu.enqueue(7);
    assert(qu.isFull());
    qu.display();

    qu.dequeue();
    qu.dequeue();
    assert(!qu.isFull());
    qu.enqueue(8);
    assert(!qu.isFull());
    qu.display();
    qu.enqueue(9);
    assert(qu.isFull());
    qu.display();

    for (int i = 1; i <= 6; ++i) {
        assert(!qu.isEmpty());
        qu.dequeue();
        qu.display();
    }

    return 0;
}