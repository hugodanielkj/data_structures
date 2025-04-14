#include <iostream>
using namespace std;

template <class T>
class myVec{
public:
    myVec();
    int size(){ return _size; };
private:
    int _size;
    int _capacity;
    T* _v;
};

template <class T>
int myVec<T>::size(){ return _size; }

int main(){
    myVec<int> m;
    cout << m.size() << endl;

    return 0;
}