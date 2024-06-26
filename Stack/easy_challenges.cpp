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
    else if(op == '^')
        return 3;
    return 0;
}

string infixToPostfix(string& infix) {
    string Postfix;
    Stack operators;

    infix.push_back('-');
    operators.push('#');

    for(int i = 0; i < infix.size(); ++i){
        if(isdigit(infix[i]) || isalpha(infix[i])){
            Postfix.push_back(infix[i]);
        }
        else if(infix[i] == '(')
            operators.push(infix[i]);
        else if(infix[i] == ')'){
            while(operators.peek() != '(')
                Postfix.push_back(operators.pop());
            operators.pop();
        }
        else {
            while(precedence(infix[i]) < precedence(operators.peek()) || (precedence(infix[i]) == precedence(operators.peek()) && infix[i] != '^'))
                Postfix.push_back(operators.pop());
            operators.push(infix[i]);
        }
    }
    return Postfix;
}

int main() {
    YASSIN FAST
//    solve();

    string equation;
    cin >> equation;  // 2+(3*(4-5*2)*(9/3+6))
    cout << infixToPostfix(equation);
/*
Assume: no spaces, positive single digits, only + - * /
1+2+3   ==>    12+3+
1+2*3   ==>    123*+
2*3+4   ==>    23*4+
1+3*5-8/2   ==>     135*+82/-
2+3*4-5*6+7		==>		234*+56*-7+
2+(3*(4-5*2)*(9/3+6)) ==>  23452*-*93/6+*+
4^3^2 ==> 432^^
5+4^3^2-9   ==> 5432^^+9-
a+B*2-c   ==>    aB2*+c-
a+b*(c^d-e)^(f+g*h)-i  ==> abcd^e-fgh*+^*+i-
1+2^3^4*5-6  ==> 1234^^5*+6-
(1+2)^3^(4*5-6)^2+1		==> 12+345*6-2^^^1+
 */
    return 0;
}