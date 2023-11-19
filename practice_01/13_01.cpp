/*
Suppose that you use a language wich sole arithmethic operations are +, -, /; design a recursive function which, given two real numbers A and B, returns the evaluation of A * B
*/

#include <iostream>

using namespace std;

int intSum(int a, int b){
    if(b > 0){
        if(b - 1 == 0) return a;
        if(b > 0) return a + intSum(a, b - 1); 
    }
    if(b < 0){
        if(b + 1 == 0) return - a;
        return - a + intSum(a, b + 1);
    }

    return a + b ;
} // integers multiplication

float specialSum(float x, int n){
    if(n -1 == 0) return x;
    cout << "x: " << x << endl;
    return x + specialSum(x, n -1);
} // in case the multiplier is 10

float convert(float x, int m, int& c){
    float x_1 = x;
    float x_2 = specialSum(x, m);
    // cout << "x_1 " << x_1 << ", x_2 " << x_2 << ", ((x_2/10) - x_1) == 0 ";
    // if((x_2/m - x_1) == 0) cout << "TRUE" << endl;

    cout << "x_2 " << x_2 / m << endl;

    if((x_2/10 - x_1) > 0 && (x_2/10 - x_1) < 1){
        return x_2;
    }

    return  convert(x_2, m, c);
    
    //flag
    return -1;
}  // WORK IN PROGRESS... 

int power(int m, int n){
    if(n - 1 == 0) return m;
    return intSum(m, power(m, n-1));
}   // function to emulate power of a number

float sum(int a, float b){
    int m = 10;
    int c = 0;
    // b = convert(b, m, c);
    m = intSum(m, c);
    int s = 0;
    s = sum(a, b);

    float result = s / m;

    c = 0;
    m = 0;

    return result; 
}

float sum(float a, int b){
    int m = 10;
    int c = 0;
    // a = convert(a, m, c);
    m = intSum(m, c);
    int s = 0;
    s = sum(a, b);

    float result = s / m;
    
    c = 0;
    m = 0;

    return result;
}

float fsum(float a, float b){
    int m = 10;
    int c = 0;

    a = convert(a, m, c);
    b = convert(b, m, c);

    // m = power(m, c);

    int s = 0;
    // s = intSum(a, b);
    // float result = s / float(m);



    return b;
}

int main(){

    cout << "Multiply two numbers" << endl;
    cout << "What do you wish to do ?" << endl;
    cout << "1 - multiply integers " << endl;
    cout << "2 - multiply floats " << endl;
    int v = 0;
    cin >> v;

    if(v == 1){
    int a = 0, b = 0;
    cout << "insert number a: ";
    cin >> a;
    cout << endl;
    cout << "insert number b: ";
    cin >> b;
    cout << endl;
    cout << "Multiplicaction of " << a << " * " << b << " is ";

    if(b == 0 || a == 0){ 
        cout << 0;
    } else if(a - int(a) == 0 && b - int(b) == 0){
        cout << intSum(a, b);
    } else {
        cout << intSum(a, b);
    }

    } else if(v == 2){
        float c = 0, d = 0;
        cout << "insert number c: ";
        cin >> c;
        cout << endl;
        cout << "insert number d: ";
        cin >> d;
        cout << endl;

        cout << "Multiplicaction of " << c << " * " << d << " is ";


        

        if(c == 0 || d == 0){ 
            // cout << 0;
        } else {
            cout << fsum(c, d);
        }
    }
    
    return 0;
}