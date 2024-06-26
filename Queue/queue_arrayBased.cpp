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

class Queue{
private:
    int size { };
    int front { };
    int rear { };
    int addedElements { };
    int *arr { };
public:
    Queue(int size) : size(size){
        arr = new int[size];
    }

    ~Queue(){
        delete[] arr;
    }

    int next(int pos){
        ++pos;
        if(pos == size)     // efficient way
            pos = 0;
        return pos;
        //return (pos + 1) % size;	//  Or shorter way
    }

    void enqueue(int val){
        assert(!isFull());
        arr[rear] = val;
        rear = next(rear);
        ++addedElements;
    }

    int dequeue(){
        assert(!isEmpty());
        int del = arr[front];
        front = next(front);
        --addedElements;
        return del;
    }

    void display(){
        cout<<"Front "<<front<<" - rear "<<rear<<"\t";
        if(isFull())
            cout<<"full"<<endl;
        else if(isEmpty()){
            cout<<"empty"<<endl;
            return;
        }
        for(int i = 0, cur = front; i < addedElements; cur = next(cur), ++i)
            cout<<arr[cur]<<" ";
        cout<<endl;
    }

    bool isEmpty(){
        return addedElements == 0;
    }

    bool isFull(){
        return addedElements == size;
    }


};

int main() {
    YASSIN FAST
//    solve();

    Queue qu(6);
    assert(qu.isEmpty());
    qu.display();

    for (int i = 1; i <= 6; ++i) {
        assert(!qu.isFull());
        qu.enqueue(i);
        qu.display();
    }
    assert(qu.isFull());

    for (int i = 1; i <= 6; ++i) {
        assert(!qu.isEmpty());
        qu.dequeue();
        //qu.display();
    }

    for (int i = 1; i <= 6; ++i) {
        assert(!qu.isFull());
        qu.enqueue(i);
        qu.display();
    }

    qu.dequeue();
    assert(!qu.isFull());
    qu.enqueue(7);
    assert(qu.isFull());
    qu.display();

    qu.dequeue();
    qu.dequeue();
    assert(!qu.isFull());
    qu.enqueue(8);
    assert(!qu.isFull());
    qu.display();
    qu.enqueue(9);
    assert(qu.isFull());
    qu.display();

    for (int i = 1; i <= 6; ++i) {
        assert(!qu.isEmpty());
        qu.dequeue();
        qu.display();
    }

    return 0;
}