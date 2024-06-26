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
    int *arr {nullptr};
    int size {0};           // user size
    int capacity { };       // actual size

    void expandCapacity(){
        // Double the actual array size
        capacity *= 2;
        cout << "Expand capacity to "
             << capacity << "\n";
        int *arr2 = new int[capacity] { };
        for(int i = 0 ; i < size; ++i)
            arr2[i] = arr[i];   // copy data

        swap(arr, arr2);
        delete[] arr2;
    }

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
        //we can't add anymore
        if(size == capacity)
            expandCapacity();
        arr[size++] = val;
    }

    void insert(int idx, int val){
        assert(0 <= idx && idx < size);

        // we can't add anymore
        if(size == capacity)
            expandCapacity();

        // Shift all the data to right first
        for(int i = size-1; i >= idx; --i)
            arr[i+1] = arr[i];

        arr[idx] = val;
        ++size;
    }
};


int main() {
    YASSIN
    FAST
//    solve();
    int n = 5;
    Vector v(n);
    for(int i = 0; i < n; ++i)
        v.set(i, i);

    v.insert(0, 25);    //25 0 1 2 3 4
    v.print();
    v.insert(5, 13);    //25 0 1 2 3 13 4
    v.print();

    return 0;
}