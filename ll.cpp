#include <iostream>
#include <string>
using namespace std;

template<class T>
class Node {
public:
    Node(const T& num): next(NULL), val(num) {}
    T val;
    Node* next;
};

template<class T>
class linkedListIterator;

template<class T>
class linkedList {
private:
    Node<T>* FirstP;
    Node<T>* LastP;
    int size;
public:
    typedef linkedListIterator<T> iterator;

    iterator begin(){ return iterator(FirstP); }
    iterator end(){ return iterator(NULL); }

    linkedList();
    void push_back(const int& a);   // 3 -> null
    void imprime();
    void imprime(Node<T>* aux);
    Node<T>* getFirstP(){return FirstP;}
    void destroy();
    void create();

    const T& operator[](const int& i);
    linkedList<T>& operator=(const linkedList<T>&);

    friend ostream& operator<<(ostream& o, const linkedList& l){
        Node<T>* aux = l.FirstP;
        while(aux != NULL){
            o << aux->val << " -> ";
            aux = aux->next;
        }
        o << "nullptr\n";
        return o;
    }
};

template<class T>
class linkedListIterator{
friend class linkedList<T>;
public:
    linkedListIterator(Node<T>* _ptr): ptr(ptr) {}

    T& operator*() { return ptr->val; }

    linkedListIterator<T> operator++(int){
        linkedListIterator<T> oldIt = *this;        // Don't know if works
        ptr = ptr->next;
        return oldIt;
    }

    linkedListIterator<T> operator++(){
        ptr = ptr->next;
        return *this;
    }

private:
    Node<T>* ptr;
};

template<class T>
linkedList<T>& linkedList<T>::operator=(const linkedList& other){
    if(this == &other) return *this;    // If copying list to itself
    else if(other.FirstP == NULL){ destroy();create();return *this; }     // If other list is empty
    else{   
        if(FirstP!=NULL)    // Destroy only if list is empty
            destroy();
        size = other.size;
        FirstP = LastP = new Node<T>(other.FirstP->val);
        Node<T>* aux = other.FirstP->next;
        while(aux){
            LastP->next = new Node<T>(aux->val);
            LastP = LastP->next;
            aux = aux->next;
        }
        return *this;
    }
}

template<class T>
const T& linkedList<T>::operator[](const int& i){
    Node<T>* aux = FirstP;
    for(int j=0;j<i;j++) aux = aux->next;
    return aux->val;
}

template<class T>
void linkedList<T>::create(){   // cannot call this function if ll already exists
    FirstP = LastP= NULL;
    size=0;
}

// ERROR
template<class T>
linkedList<T>::linkedList(){   // cannot call this function if ll already exists
    FirstP = LastP= NULL;
    size=0;
}

template<class T>
void linkedList<T>::destroy(){
    Node<T>* aux = FirstP;
    while(aux){
        aux = aux->next;
        delete FirstP;
        FirstP = aux;
    }
}

template<class T>
void linkedList<T>::imprime(){
    Node<T>* aux = FirstP;
    while(aux){
        cout << aux->val << " -> ";
        aux = aux->next;
    }
    cout << "NULL\n";
}

template<class T>
void linkedList<T>::imprime(Node<T>* aux){
    if(!aux){
        cout << "NULL\n";
        return;
    } 
    cout << aux->val << " -> ";
    imprime(aux->next);
}

template<class T>
void linkedList<T>::push_back(const int& a){
    if(FirstP==NULL){
        FirstP=LastP=new Node<T>(a);    // new Node returns the adress of the new Node created
        size++;
    } else {
        LastP->next = new Node<T>(a);
        LastP = LastP->next;
        size++;
    }
    /*
    } else {
        Node** aux = &FirstP;
        while(*aux){aux = &((*aux)->next);}
        *aux = new Node(a);
        size++;
    }
    */
}

int main(){
    linkedList<int> l;
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);

    linkedList<int> a;
    linkedList<int> j;
    //j = a = l;

    l.push_back(1);
    a.push_back(9);

    //linkedListIterator<int> it(l.begin());
    cout << l;
    linkedList<int>::iterator it = l.begin();
    cout << *it << endl;
    it++;
    cout << *it << endl;

    return 0;
}