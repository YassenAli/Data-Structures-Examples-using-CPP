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

// Order:

void ConstantOrder1() {
    // O(1)
    int start = 6;
    int end = 100;

    int mid = (end - start) / 2;

    if (mid % 2 == 0)
        --mid;
}

void ConstantOrder2() {
    int start = 7;
    int end = 0;

    for (int i = 0; i < 1000; ++i)
        end += end * 2 + start;
}

void linear1(int n) {	// O(n)
    int sum = 0;
    for (int i = 0; i < n; i++) {
        // All below are O(1)
        int x = 2 + 3 * 4;
        sum += i;
        sum += 2;
        sum += x;
    }
}

void linear2(int n) { // O(n)
    for (int i = 0; i < 10 * n; i++)
        ConstantOrder1();

    for (int i = 0; i < 5 * n; i++)
        ConstantOrder1();

}

void quadratic1(int n) { // O(n^2)
    int cnt = 0;
    for (int i = 0; i < 5 * n; ++i) {
        for (int j = 0; j < 3 * n; ++j) {
            cnt++;
            ConstantOrder1();
        }
    }
}

void quadratic2(int n) { // O(n^2)
    int cnt = 0;
    for (int i = 0; i < 5 * n; ++i) {
        for (int j = 0; j < 3 * n; ++j) {
            cnt++;
            ConstantOrder1();
        }
    }
    for (int i = 0; i < 10 * n; i++)
        ConstantOrder1();
}

void quadratic3(int n) { // O(n^2)
    int cnt = 0;
    for (int i = 0; i < 5 * n; ++i) {
        for (int j = 0; j < 3 * n; ++j) {
            for (int k = 0; k < 1000; ++k) {
                cnt++;
                ConstantOrder1();
            }
        }
    }
    for (int i = 0; i < 10 * n; i++)
        ConstantOrder1();
}

void quadratic4(int n) { // O(n^2)
    for (int i = 0; i < 10 * n; i++)
        ConstantOrder1();

    for (int i = 0; i < 3 * n * n; i++)
        ConstantOrder1();
}

void cubic1(int n) { // O(n^3)
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                cnt++;
            }
        }
    }
}

void cubic2(int n) { // O(n^3)
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                cnt++;

    for (int i = 0; i < 1000 * n; ++i)
        for (int j = 0; j < 1000 * n; ++j)
            cnt++;
}

void f(int n) { // O(n^6)
    int cnt = 0;
    for (int i = 0; i < n * n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n * n * n; ++k)
                cnt++;

}

void f1(int n) { // O(n^3)
    int cnt = 0;
    for (int i = 0; i < n * n; ++i)
        for (int j = 0; j < n; ++j)
            cnt++;
}

void f2(int n) { // O(n^4)
    for (int i = 0; i < n; ++i)
        f1(i);	// n^3
}

void f3(int n, int m) {		// O(nm)
    int cnt = 0;
    for (int i = 0; i < 2 * n; ++i)
        for (int j = 0; j < 3 * m; ++j)
            cnt++;
}

void f4(int n, int m) {		// O(nm + n^3)
    int cnt = 0;
    for (int i = 0; i < 2 * n; ++i)
        for (int j = 0; j < 3 * m; ++j)
            cnt++;

    for (int i = 0; i < n * n * n; ++i)
        cnt++;
}

void f11(int n = 1000) { 	// O(n^3)
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                cnt++;

    // cnt = 1000,000,000
}

void f22(int n = 1000) { 	// O(n^3)
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            for (int k = j; k < n; ++k)
                cnt++;

    // cnt 167,167000
}

// Space:

int* func1(int n) { // Total O(n) memory, O(n^2) time

    // This line: O(n) time and O(n) memory
    int *p = new int[n] {};

    for (int i = 0; i < n; ++i)	// O(n) time
        p[i] = i;

    int sum = 0;	// O(n^2) time
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum += p[i];
        }
    }
    return p;
}

int* func2() { // Total O(1) memory, O(1) time
    int n = 10000;
    int *p = new int[n] {};

    for (int i = 0; i < n; ++i)
        p[i] = i;

    int sum = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            sum += p[i];
    return p;
}

int* f3B(int n) {	// O(n) time/memory
    return new int[n] {};
}

void f3A(int n) {
    // O(n^2) time but still O(n) memory
    for (int i = 1; i < n; ++i) {
        int *p = f3B(n);
        delete [] p;
    }
}

int* f4B(int n) {	// O(n) time/memory
    return new int[n] {};
}

void f4A(int n) {
    // O(n^2) time & memory
    for (int i = 1; i < n; ++i) {
        int *p = f3B(n);
        // we accumulate memory!
    }
}

void f5(int n) {	// O(n) time/memory
    int* p1 = new int[10 * n] {};
    int *p2 = new int[20 * n] {};
}

void f6(int n, int m) {	// O(n+m) time/memory
    int *p1 = new int[10 * n] {};
    int *p2 = new int[20 * m] {};
}

int f7B(int *arr, int n) {
    // O(1) memory excluding parameters with reference
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += arr[i];
    return sum;
}

void f7A(int n) {
    int *x = new int[n];	// O(n) memory
    f7B(x, n);	// O(1) memory
}

// This take the vector by reference
int f8B(vector<int> & v, int f) {
    // O(n) time and O(1) memory
    int sum = 0;
    for (int i = 0; i < v.size(); ++i)
        sum += v[i] * f;
    return sum;
}

void f8A(int n) {
    //vector of n numbers: O(n) memory
    vector<int> v(n, 1);

    // O(n^2) time and O(1) memory
    for (int i = 0; i < n; ++i)
        f8B(v, i);
}

// This take the vector by copy so will take O(n) memory
int f9B(vector<int> v, int f) {
    // O(n) time and O(n) memory
    // The vector n items will be copied each time!
    int sum = 0;
    for (int i = 0; i < v.size(); ++i)
        sum += v[i] * f;
    return sum;
}

void f9A(int n) {
    //vector of n numbers: O(n) memory
    vector<int> v(n, 1);

    // O(n^2) time and O(n) memory
    for (int i = 0; i < n; ++i)
        f9B(v, i);
}

// This computes the factorial by loop so will take less memory
int factorial1(int n) {
    // O(n) time and O(1) memory
    int res = 1;
    for (int i = 1; i <= n; ++i)
        res *= i;
    return res;
}

// This computes the factorial by recursion so will take more memory
int factorial2(int n) {
    // O(n) time and O(n) memory
    if(n <= 1)
        return 1;

    int subres = factorial1(n-1);
    return n * subres;
}

// This function delete the memory after recursion statement so will take  more memory. (n recursion calls)
void f10(int n) {	// O(n^2) memory
    if(n <= 0)
        return;
    int *p = new int[n];	// O(n) memory
    f10(n-1);
    delete[] p;
}

// This function delete the memory after creating it so will take less memory.
void f111(int n) {	// O(n) memory
    if(n <= 0)
        return;
    int *p = new int[n];	// O(n) memory
    delete[] p;
    f10(n-1);

}

int main() {
    YASSIN
    FAST
//    solve();

    return 0;
}