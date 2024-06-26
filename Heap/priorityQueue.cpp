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

void test_priority_queue_max_heap() {
    priority_queue<int> mxHeap;
    mxHeap.push(1);
    mxHeap.push(3);
    mxHeap.push(7);
    mxHeap.push(9);
    mxHeap.push(5);

    while (!mxHeap.empty()) {
        cout << mxHeap.top() << " ";
        mxHeap.pop();
    }

    cout << "\n";
}

void test_priority_queue_min_heap() {
    priority_queue<int, vector<int>, greater<int>> mnHeap;

    mnHeap.push(1);
    mnHeap.push(3);
    mnHeap.push(7);
    mnHeap.push(9);
    mnHeap.push(5);

    while (!mnHeap.empty()) {
        cout << mnHeap.top() << " ";
        mnHeap.pop();
    }
    cout << "\n";

    priority_queue<string, vector<string>, greater<string>> mnHeapString;

    mnHeapString.push("Yassin");
    mnHeapString.push("Ali");
    while (!mnHeapString.empty()) {
        cout << mnHeapString.top() << " ";
        mnHeapString.pop();
    }
    cout << "\n";
}

int main() {
    YASSIN
    FAST
//    solve();

    test_priority_queue_max_heap();
    cout<<endl;
    test_priority_queue_min_heap();

    return 0;
}