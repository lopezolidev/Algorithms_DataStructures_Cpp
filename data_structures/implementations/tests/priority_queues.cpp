#include <iostream>
#include <queue>

using namespace std;

template <class T>
class MyQueue{
    private:
        queue<T>* priorityQueues;
        int _size;
    public: 
        MyQueue(int n){
            priorityQueues = new queue<T>[n];
            this->_size = 0;
        }
        ~MyQueue(){
            delete[] priorityQueues;
        }
        void enqueue(T z, int prio){
            if(prio < 0 || prio > n - 1){
                cout << "invalid " << endl; return ;
            }
            priorityQueues[prio].push(z);
        }
        T* dequeue(){
            int i = 0;
            while(i < n - 1){
                if(!priorityQueues[i].isEmpty()){
                    T* v = priorityQueues[i].pop();
                    return v;
                }
                i++;
            }
        }

};

int main(){
    return 0;
}