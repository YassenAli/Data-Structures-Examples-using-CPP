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

    // Function Find to find value with this signature( find(val) )
    Node *find(int val) {
        Node *current = this;
        while (current != nullptr) {
            if (current->data == val)
                return current;
            current = current->next;
        }
        return nullptr;
    }
};

class LinkedList {
private:
    Node *head { };
    Node *tail { };
    int length = 0;		// let's maintain how many nodes
public:

//    LinkedList() {}

    void print() {
        for (Node *cur = head;cur != nullptr; cur = cur->next)
            cout << cur->data << " ";
        cout << endl;
    }

    void insert_end(int val){
        Node* item = new Node(val);

        if(!head)
            head = tail = item;
        else{
            tail->next = item;
            tail = item;
        }
    }

    Node* get_nth(int n){
        int cnt = 0;
        for(Node* cur = head; cur; cur = cur->next)
            if(++cnt == n)
                return cur;
        return nullptr;	// still more steps needed - NOT found
    }

    int search(int val){
        int i = 0;
        for(Node* cur = head; cur; cur = cur->next, i++)
            if(cur->data == val)
                return i;
        return -1;
    }

    int search_improved(int val){
        int i = 0;
        Node *prev = nullptr;
        for(Node *cur = head; cur; cur = cur->next, i++) {
            if (cur->data == val) {
                if (!prev)
                    return i;
                swap(cur->data, prev->data);
                return i - 1;
            }
            prev = cur;
        }
        return -1;
    }

    int search_improved_version2(int val){
        int i = 0;
        for(Node *cur = head, *prev = nullptr; cur; prev = cur, cur = cur->next, i++)
            if(cur->data == val) {
                if(!prev)
                    return i;
                swap(cur->data, prev->data);
                return i - 1;
            }
        return -1;
    }

    ~LinkedList(){
        delete head;
        delete tail;
    }
};

void test(LinkedList &list) {
    list.print();

    int n = 2;
    Node* res = list.get_nth(n);

    if (res == nullptr)
        cout << "the element number "<<n<<" is none\n";
    else
        cout << "the element number "<<n<<" is : " << res->data << "\n";

    cout << list.search(15) << "\n";
    cout << list.search_improved(15) << "\n";

    list.print();
    cout << "************************\n";
}

int main() {
    YASSIN
    FAST
//    solve();

    LinkedList list;

    test(list);

    list.insert_end(6);
    list.insert_end(10);
    list.insert_end(8);
    list.insert_end(15);

    test(list);

    return 0;
}