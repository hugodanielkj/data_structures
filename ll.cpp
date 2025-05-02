#include <iostream>
#include <string>
using namespace std;

template<class T>
struct Node {
    Node(const int& num): next(NULL), val(num) {}
    T val;
    Node* next;
};

template<class T>
class linkedList {
private:
    Node<T>* FirstP;
    Node<T>* LastP;
    int size;
public:
    linkedList();
    void push_back(const int& a);   // 3 -> null
    void imprime();
    void imprime(Node<T>* aux);
    Node<T>* getFirstP(){return FirstP;}
    void destroy();

    const T& operator[](const int& i);

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
const T& linkedList<T>::operator[](const int& i){
    Node<T>* aux = FirstP;
    for(int j=0;j<i;j++) aux = aux->next;
    return aux->val;
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
    cout << l;
    l.push_back(3);
    cout << l;
    l.push_back(4);
    cout << l;
    l.push_back(5);
    cout << l;
    cout << endl;
    Node<int>* aux = l.getFirstP();
    l.imprime(aux);
    cout << l[2] << endl;
    l.destroy();
    cout << l;
    return 0;

    return 0;
}