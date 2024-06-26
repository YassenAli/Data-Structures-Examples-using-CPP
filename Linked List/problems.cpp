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

    //Pointer to Same type
    Node(int data) : data(data) {}
    ~Node(){
        cout<<"Destroy value: "<<data<<" at address "<<this<<endl;
    }

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

    void insert_end(int value) {
        Node* item = new Node(value);
        if (!head)
            head = tail = item;
        else
            tail->next = item, tail = item;
        ++length;
    }

    void insert_front(int val){		// O(1) time - O(1) memory
        Node* newNode = new Node(val);
        if(!head){
            head = tail = newNode;
            head->next = tail->next = nullptr;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
        ++length;
    }

    void delete_front(){		// O(1) time - O(1) memory
        assert(length);
        Node* cur = head->next;
        delete head;
        head = cur;
        --length;
        if(length <= 1)
            tail = head;
    }

    Node* get_nth_back(int n){		// O(n) time - O(1) memory
        int i = 0;
        for(Node* cur = head; cur; cur = cur->next)
            if(i++ == length - n)
                return cur;
    }

    bool is_same1(const LinkedList &other){
        Node *cur1 = this->head, *cur2 = other.head;
        for(; cur1 && cur2; cur1 = cur1->next, cur2 = cur2->next)
            if(cur1->data != cur2->data
                    )
                return false;
        return !cur1 && !cur2;
    }

    bool is_same(const LinkedList &other){	// using length
        if(this->length == other.length)
            return false;

        for(Node *cur1 = this->head, *cur2 = other.head; cur1 && cur2; cur1 = cur1->next, cur2 = cur2->next)
            if(cur1->data != cur2->data)
                return false;
        return true;
    }



    ~LinkedList(){
        // O(n) time - O(1) memory
        // idea: get next first, remove current head
        while(head){
            Node* cur = head->next;
            delete head;
            head = cur;
        }
    }
};

int main() {
    YASSIN
    FAST

//    solve();

    LinkedList list;
    list.insert_end(6);
    list.insert_end(10);
    list.insert_end(8);
    list.insert_end(15);
    list.insert_front(5);
    list.delete_front();
    list.print();
    list.insert_front(1);
    list.delete_front();
    if(list.get_nth_back(1)->data == 15){
        cout<<"True"<<endl;
    }
    if(list.get_nth_back(2)->data == 8){
        cout<<"True"<<endl;
    }
    list.print();

    return 0;
}