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

class MinHeap{
private:
    int *arr{ };
    int size { };
    int capacity { 1000 };

    int left(int node){
        int p = 2 * node + 1;
        return p >= size ? -1 : p;
    }

    int right(int node){
        int p = 2 * node + 2;
        return p >= size ? -1 : p;
    }

    int parent(int node){
        return node == 0 ? -1 : (node - 1)/2;
    }

    void heapify_up(int childPos){	// O(logn)
        int parentPos = parent(childPos);
        if(childPos == 0 || arr[parentPos] <= arr[childPos])
            return;
        swap(arr[parentPos], arr[childPos]);
        heapify_up(parentPos);
    }

    void heapify_down(int parentPos){	// O(logn)
        int left_child = left(parentPos);
        int right_child = right(parentPos);
        if(left_child == -1)
            return;
        if(right_child != -1 && arr[right_child] < arr[left_child])
            left_child = right_child;
        if(arr[parentPos] > arr[left_child]) {
            swap(arr[left_child], arr[parentPos]);
            heapify_down(left_child);
        }
    }

    void heapify(){     // O(n)
        for(int i = size/2 - 1; i >= 0; --i)
            heapify_down(i);
    }

public:
    MinHeap() : size(0) {
        arr = new int[capacity];
    }

    MinHeap(const vector<int> &v){
        assert(v.size() <= capacity);
        arr = new int[capacity] { };
        size = v.size();
        for(int i = 0; i < v.size(); ++i)
            arr[i] = v[i];
        heapify();
    }

    ~MinHeap(){
        delete[] arr;
        arr = nullptr;
    }

    void push(int key){
        assert(size + 1 <= capacity);
        arr[size++] = key;
        heapify_up(size-1);
    }

    int top(){
        assert(!isEmpty());
        return arr[0];
    }

    void pop(){
        assert(!isEmpty());
        arr[0] = arr[--size];
        heapify_down(0);
    }

    bool isEmpty(){
        return size == 0;
    }
};

class MaxHeap{
private:
    MinHeap heap;

    vector<int> multiply_neg1(const vector<int> &v){
        vector<int> res = v;
        for(int i = 0; i < v.size(); ++i)
            res[i] *= -1;
        return res;
    }
public:
    MaxHeap(){
    }

    MaxHeap(const vector<int> &v) : heap(multiply_neg1(v)){
    }

    int top(){
        return -heap.top();
    }

    void push(int key){
        heap.push(-key);
    }

    void pop(){
        heap.pop();
    }

    bool isEmpty(){
        return heap.isEmpty();
    }
};

void create_heap_nlogn(){	// O(nlogn)
    vector<int> v { 2, 17, 22, 10, 8, 37,
                    14, 19, 7, 6, 5, 12, 25, 30 };
    MaxHeap heap;
    for(int i = 0; i< v.size(); ++i)	// O(nlogn)
        heap.push(v[i]);	// O(logn)
    while(!heap.isEmpty()){
        cout<<heap.top()<<" ";
        heap.pop();
    }
}

void create_heap_n(){	// O(n)
    vector<int> v { 2, 17, 22, 10, 8, 37,
                    14, 19, 7, 6, 5, 12, 25, 30 };
    MaxHeap heap(v);
    while(!heap.isEmpty()){
        cout<<heap.top()<<" ";
        heap.pop();
    }
}

int main() {
    YASSIN
    FAST
//    solve();

    MaxHeap heap;
    vector<int> v { 2, 17, 22, 10, 8, 37, 14, 19, 7, 6, 5, 12, 25, 30 };

    create_heap_n();

    return 0;
}