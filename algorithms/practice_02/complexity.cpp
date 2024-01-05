#include <iostream>
using namespace std;

void m(){
    cout << "Hello !" << endl;
}

void alg1(int n){
    int I = 1;
    do {
        int J = 1;
        do {
            int K = 1;
            do {
                m();
                K = K + 1;
            } while (K != J);
            J = J + 1;
        } while (J != I);
        I = I + 1;
    } while (I != n);
}

void alg2(int n ){
    int J = n;
    while (J > 1) {
        m();
        J = J/2;
    }
}

int main(){

    // cout << "alg1(5) " << endl;
    // alg1(5);

    cout << "alg2(6) " << endl;
    alg2(6);

    return 0;
}