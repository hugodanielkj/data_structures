#include <iostream>
#include <vector>
using namespace std;

const int& function(int &y){
    int& x = y;
    return x;
}

int main(){
    vector<int> v;
    v.push_back(3);
    v.push_back(5);
    int& asd = v[0];
    asd = 11;
    for(auto c : v) cout << c << " "; 

    int a[3] = {1,2,3};
    int& x = a[2];
    x = 10;

    for(int i=0;i<3;i++) cout << a[i] << " ";

    return 0;
}