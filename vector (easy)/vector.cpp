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

class Vector {
private:
    int *arr = nullptr;
    int size = 0;
public:
    Vector(int size) : size(size) {
        if (size < 0) size = 1;
        arr = new int[size]{};
    }

    ~Vector() {
        delete[] arr;
        arr = nullptr;
    }

    int getSize() {
        return size;
    }

    int get(int idx) {
        assert(idx >= 0 and idx < size);
        return arr[idx];
    }

    void set(int idx, int val) {
        assert(idx >= 0 and idx < size);
        arr[idx] = val;
    }

    void print() {
        for (int i = 0; i < size; ++i)
            cout << arr[i] << " ";
        cout << "\n";
    }

    int find(int val) {
        for (int i = 0; i < size; ++i)
            if (arr[i] == val)
                return i;
        return -1;
    }

    int getFront(){
        return arr[0];
    }

    int getBack(){
        return arr[size - 1];
    }

    void pushBack(int val){
        // Add element to the end of the vector
        // 1) create a new array of bigger size
        int *arr2 = new int[size + 1];    // size+1 steps
        // 2) copy old data
        for(int i = 0; i < size; ++i)     // 3size+1 steps
            arr2[i] = arr[i];
        // 3) add the new element and increase size
        arr2[size++] = val;				// 2 steps
        // 4) change the pointers
        swap(arr, arr2);					// 3 steps
        // 5) remove the useless data
        delete[] arr2;						// size steps
        // Total: 5size + 7 ==> approximately size steps
    }
};


int main() {
    YASSIN
    FAST
//    solve();
    int n = 10;
    Vector v(n);
    for(int i = 0; i < n; ++i)
        v.set(i, i);
    v.pushBack(15);
    v.pushBack(17);
    v.pushBack(19);
    v.print();
    // 0 1 2 3 15 17 19

    cout<<v.find(5)<<" "<<v.find(55); // 5 -1

    for (int i = 0; i < 1000000; ++i) {
        v.pushBack(i);
    } // take too much time!!!

    v.print();

    return 0;
}