#include <iostream>
using namespace std;

template <class T>
class myVec{
public:
    myVec();    // Default Constructor
    myVec(const myVec&);    // Constructor by copy

    const T& operator[](int pos) const;     // Read-only

    int size() const;
    void push_back(const T);
private:
    int dataSize;
    int dataCapacity;
    T* data;
};

template <class T>
const T& myVec<T>::operator[](int pos) const{

}

//Constructors

template <class T>
myVec<T>::myVec(){
    dataCapacity = 10;
    data = new T[10];
    dataSize = 0; 
}

template <class T>
myVec<T>::myVec(const myVec& v){
    if(dataCapacity >= v.dataCapacity){
        dataCapacity = v.dataCapacity;
        dataSize = v.dataSize;
        for(int i=0;i<v.dataSize;i++) data[i] = v.data[i];
    } else {
        T* aux = new T[v.dataCapacity];
        for(int i=0;i<v.dataSize;i++) aux[i] = v.data[i];
        delete[] data;
        data = aux;
        dataCapacity = v.dataCapacity;
        dataSize = v.dataSize;
    }
}

template <class T>
myVec<T>::myVec(){}


template <class T>
int myVec<T>::size() const { return dataSize; }


template <class T>
void myVec<T>::push_back(const T elem){
    if(dataSize+1 <= dataCapacity) data[dataSize++] = elem;
    else {
        T* aux = new T[dataCapacity*=2];
        for(int i=0;i<dataSize;i++) aux[i] = data[i];
        delete[] data;
        data = aux;
    }
}

int main(){
    myVec<int> m;
    m.push_back(1);
    //cout << m[1];

    return 0;
}