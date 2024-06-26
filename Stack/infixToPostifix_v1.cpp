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

typedef char type;

class Stack {
private:
    // Tip: We can make this struct internally
    struct Node {
        type data { };
        Node* next { };
        Node(int data) :
                data(data) {
        }
    };

    Node *head { };

public:
    ~Stack() {
        while (!isEmpty())
            pop();
    }
    void display() {
        for (Node* cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }

    void push(type value) {
        Node* item = new Node(value);
        item->next = head;
        head = item;
    }

    type pop() {
        assert(!isEmpty());
        int element = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return element;
    }

    type peek() {
        assert(!isEmpty());
        int element = head->data;
        return element;
    }

    int isEmpty() {
        return !head;
    }
};

int precedence(char op){
    if(op == '+' || op == '-')
        return 1;
    else if (op == '/' || op == '*')
        return 2;
    return 0;
}

string infixToPostfix(string& infix) {
    string Postfix;
    Stack operators;

    for(int i = 0; i < infix.size(); ++i){
        if(isdigit(infix[i])){
            Postfix.push_back(infix[i]);
        }
        else {
            while(!operators.isEmpty() && precedence(infix[i]) <= precedence(operators.peek())){
                Postfix.push_back(operators.pop());
            }
            operators.push(infix[i]);
        }
    }
    while(!operators.isEmpty())
        Postfix.push_back(operators.pop());
    return Postfix;
}

int main() {
    YASSIN FAST
//    solve();

    string equation;
    cin>>equation;
    cout<<infixToPostfix(equation);

    return 0;
}