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

class MinHeap {
private:
    int *arr{};
    int size{};
    int capacity{1000};

    int left(int node) {
        int p = 2 * node + 1;
        return p >= size ? -1 : p;
    }

    int right(int node) {
        int p = 2 * node + 2;
        return p >= size ? -1 : p;
    }

    int parent(int node) {
        return node == 0 ? -1 : (node - 1) / 2;
    }

    void heapify_up(int childPos) {    // O(logn)
        int parentPos = parent(childPos);
        if (childPos == 0 || arr[parentPos] <= arr[childPos])
            return;
        swap(arr[parentPos], arr[childPos]);
        heapify_up(parentPos);
    }

    void heapify_down(int parentPos) {    // O(logn)
        int left_child = left(parentPos);
        int right_child = right(parentPos);
        if (left_child == -1)
            return;
        if (right_child != -1 && arr[right_child] < arr[left_child])
            left_child = right_child;
        if (arr[parentPos] > arr[left_child]) {
            swap(arr[left_child], arr[parentPos]);
            heapify_down(left_child);
        }
    }

    void heapify() {     // O(n)
        for (int i = size / 2 - 1; i >= 0; --i)
            heapify_down(i);
    }

public:
    MinHeap() : size(0) {
        arr = new int[capacity];
    }

    MinHeap(const vector<int> &v) {
        assert(v.size() <= capacity);
        arr = new int[capacity]{};
        size = v.size();
        for (int i = 0; i < v.size(); ++i)
            arr[i] = v[i];
        heapify();
    }

    ~MinHeap() {
        delete[] arr;
        arr = nullptr;
    }

    void push(int key) {
        assert(size + 1 <= capacity);
        arr[size++] = key;
        heapify_up(size - 1);
    }

    int top() {
        assert(!isEmpty());
        return arr[0];
    }

    void pop() {
        assert(!isEmpty());
        arr[0] = arr[--size];
        heapify_down(0);
    }

    bool isEmpty() {
        return size == 0;
    }

    /*
     Problem #3: Find smaller values
        ● void print_less_than(int val, int parent_pos = 0)
        ● Extend your MinHeap class with the above function
        ● It prints all the values that are < value in the heap
        ○ We can do that by simply iterating on the whole array
        ○ Try to do better
        ● E.g. if we inserted in heap: 2, 17, 22, 10, 8, 37, 14, 19, 7, 6, 5, 12, 25, 30
        ● heap.print_less_than(10); ⇒ 2 5 8 6 7
        ○ Order of output doesn’t matter
     */
    void print_less_than(int val, int parent_pos = 0) {
        if (parent_pos == -1 || arr[parent_pos] >= val)
            return;
        cout << arr[parent_pos] << " ";
        print_less_than(val, left(parent_pos));
        print_less_than(val, right(parent_pos));
    }

    bool is_heap(int parentPos){
        if(parentPos == -1)
            return true;
        int leftChild = left(parentPos);
        int rightChild = right(parentPos);
        if(leftChild != -1 && arr[parentPos] > arr[leftChild])
            return false;
        if(rightChild != -1 && arr[parentPos] > arr[rightChild])
            return false;

        return is_heap(leftChild) && is_heap(rightChild);
    }

    /*
     Problem #4: Is Heap
        ● bool is_heap_array(int *p, int n)
        ● Extend your MinHeap class with the above function
        ● It takes a pointer to array and its length to verify its content represents a heap
        or not
        ● E.g. 2, 5, 12, 7,6, 22, 14, 19, 10, 17, 8, 37, 25, 30
        ○ Is a heap
     */
    bool is_heap_arr(int* p, int n){
        int oldSize = size;
        int* oldArray = arr;

        size = n;
        arr = p;

        bool res = is_heap(0);

        size = oldSize;
        arr = oldArray;

        return res;
    }

    /*
     Problem #5: Heap Sort
        ● Add member function to the MinHeap
        ● void heap_sort(int *p, int n)
        ● Which takes an array and perform in-place sort for its content from small to
        large
        ○ In-place means this array will be used to do the sort without using/creating other array
     */
    void heap_sort(int *p, int n){
        if(n <= 1)
            return;
        int oldSize = size, *oldArray = arr;

        size = n; arr = p;

        heapify();
        while(size--){
            swap(arr[0], arr[size]);
            heapify_down(0);
        }

        for(int i = 0; i < n / 2; ++i)
            swap(arr[i], arr[n-i-1]);

        size = oldSize;
        arr = oldArray;
    }
};

void create_heap_nlogn() {    // O(nlogn)
    vector<int> v{2, 17, 22, 10, 8, 37,
                  14, 19, 7, 6, 5, 12, 25, 30};
    MinHeap heap;
    for (int i = 0; i < v.size(); ++i)    // O(nlogn)
        heap.push(v[i]);    // O(logn)

    heap.print_less_than(20);	// 2 5 8 6 7
    cout<<"\n";
    while (!heap.isEmpty()) {
        cout << heap.top() << " ";
        heap.pop();
    }
}

void create_heap_n() {    // O(n)
    vector<int> v{2, 17, 22, 10, 8, 37,
                  14, 19, 7, 6, 5, 12, 25, 30};
    MinHeap heap(v);
    while (!heap.isEmpty()) {
        cout << heap.top() << " ";
        heap.pop();
    }
}

void is_heap_array() {
    vector<int> v { 2, 17, 22, 10, 8, 37, 14, 19, 7, 6, 5, 12, 25, 30 };
    MinHeap heap(v);

    int arr[] {2, 5, 12, 7,6, 22, 14, 19, 10, 17, 8, 37, 25, 30};
    cout<<heap.is_heap_arr(arr, 14)<<"\n";	// 1
    swap(arr[0], arr[5]);
    cout<<heap.is_heap_arr(arr, 14)<<"\n";	// 0
}

void heap_sort() {
    const int SZ = 14;
    int arr[SZ] { 2, 17, 22, 10, 8, 37, 14, 19, 7, 6, 5, 12, 25, 30};
    MinHeap heap;

    heap.heap_sort(arr, SZ);

    for (int i = 0; i < SZ; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    YASSIN
    FAST
//    solve();

    heap_sort();

    return 0;
}