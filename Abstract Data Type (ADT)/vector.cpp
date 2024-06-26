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

    void expandCapacity();

public:
    Vector(int size);

    ~Vector();

    int getSize();

    int get(int idx);

    void set(int idx, int val);

    void print();

    int find(int val);

    int getFront();

    int getBack();

    void pushBack(int val);

    void insert(int idx, int val);
};

void Vector::expandCapacity(){
    // Double the actual array size
    capacity *= 2;
    cout << "Expand capacity to " << capacity << "\n";
    int *arr2 = new int[capacity] { };
    for(int i = 0 ; i < size; ++i)
        arr2[i] = arr[i];   // copy data

    swap(arr, arr2);
    delete[] arr2;
}

Vector::Vector(int size) : size(size) {
    if (size < 0) size = 1;
    capacity = size + 10;
    // The actual size array will
    // be bigger than needed
    arr = new int[capacity]{};
}

Vector::~Vector() {
    delete[] arr;
    arr = nullptr;
}

int Vector::getSize() {
    return size;
}

int Vector::get(int idx) {
    assert(idx >= 0 and idx < size);
    return arr[idx];
}

void Vector::set(int idx, int val) {
    assert(idx >= 0 and idx < size);
    arr[idx] = val;
}

void Vector::print() {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int Vector::find(int val) {
    for (int i = 0; i < size; ++i)
        if (arr[i] == val)
            return i;
    return -1;  // -1 for NOT found
}

int Vector::getFront(){
    return arr[0];
}

int Vector::getBack(){
    return arr[size - 1];
}

void Vector::pushBack(int val){
    //we can't add anymore
    if(size == capacity)
        expandCapacity();
    arr[size++] = val;
}

void Vector::insert(int idx, int val){
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

int main() {
    YASSIN
    FAST
//    solve();
    int n = 2;
    Vector v(n);
    for (int i = 0; i < n; ++i)
        v.set(i, i);

    for (int i = 0; i < 15; ++i)
        v.pushBack(i + 10);

    v.print();

    return 0;
}