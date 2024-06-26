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

void test_vector(){
    vector<int> v;

    v.push_back(30);
    v.push_back(10);
    v.push_back(20);
    // Now we have 3 elements only

    for(int i = 0; i < v.size(); ++i){
        cout<<v[i]<<" ";	// 30 10 20
    }
    cout<<endl;

    // vector of 3 strings
    vector<string> vec_str {"Yassin", "Ali", "me"};

}

void test_stack(){
    stack<string> s;
    s.push("Mamdouh");
    s.push("Ali");
    s.push("Yassin");

    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    cout<<endl;
    // Yassin Ali Mamdouh
}

void test_queue(){
    queue <int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout<<"Last element in Queue: "<<q.back()<<endl;

    cout<<"Queue elements: ";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    queue<string> q_names;
    q_names.push("Yassin");
    string name = q_names.front();
}

void test_pairs(){
    pair<int, string> p = make_pair(10, "Yassin");

    cout<<p.first<<" "<<p.second<<endl; // 10 Yassin
    p.first += 3;

    pair<float, pair<int, string>> p2 = make_pair(20.5, p);
    cout<<p2.second.first<<endl; // 13
    p = p2.second;

    vector<pair<int, string>> v;
    v.push_back(p);
}

int main() {
    YASSIN FAST

//    solve();

    test_pairs();

    return 0;
}