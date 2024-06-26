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
    int size { };
    int top { };
    int* arr { };
public:
    Stack(int size): size(size), top(-1){
        arr = new int[size];
    }
    ~Stack(){
        delete[] arr;
    }

    void push(int val){
        assert(!isFull());
        arr[++top] = val;
    }

    int pop(){
        assert(!isEmpty());
        return arr[top--];
    }

    int peek(){
        assert(!isEmpty());
        return arr[top];
    }

    bool isFull(){
        return top == size - 1;
    }

    bool isEmpty(){
        return top == -1;
    }

    void display(){
        for(int i = top; i >= 0; --i){
            cout << arr[i] << " ";
        }
        cout<< endl;
    }


};

int main(){
    YASSIN FAST

    Stack stk(3);
    stk.push(10);
    stk.push(20);
    stk.push(30);

    if (!stk.isFull())
        stk.push(50);
    else
        cout << "Full Stack\n";
    stk.display();	// 30 20 10
    cout << stk.peek() << "\n";	// 30

    while (!stk.isEmpty()) {
        cout << stk.peek() << " ";
        stk.pop();
    } // 30 20 10

    return 0;
}