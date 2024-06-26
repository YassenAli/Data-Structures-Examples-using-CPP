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

class Stack{
private:
    struct Node{
        int data { };
        Node* next { };
        Node(int data) : data(data) { }
    };
    Node* head { };
public:
    ~Stack(){
        while(!isEmpty())
            pop();
    }

    int pop() {
        assert(!isEmpty());
        int element = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return element;
    }

    bool isEmpty(){
        return !head;
    }

    int peek() {
        assert(!isEmpty());
        int element = head->data;
        return element;
    }

    void push(int val){
        // By design: always new node = head
        // Great match with stack!
        Node* item = new Node(val);
        item->next = head;
        head = item ;
        // Tip: This code works as long as machine has more RAM
        // In industry: You may check if return is null (can't create) or not.
    }

    void display(){
        for(Node* cur = head ; cur ; cur = cur->next)
            cout<<cur->data<<" ";
        cout<<endl;
    }

};

int main(){
    YASSIN FAST

    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);

    stk.display();	// 30 20 10
    cout << stk.peek() << "\n";	// 30

    while (!stk.isEmpty())
        cout << stk.pop() << " ";
    // 30 20 10

    return 0;
}