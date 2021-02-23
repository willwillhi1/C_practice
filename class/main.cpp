//g++ -o ball main.cpp ball.cpp
#include <iostream>
#include "ball.h"
using namespace std;

int main(){
    //basketball x;
    //ball *y[2];  
    ball *x = new basketball; //by pointer
    float m = 1.2,n = 1.5;
    x->show();    //print "I am basketball by virtual function"
    x->set_WH(m,n);
    cout << "the ball's sphere is:" << x->sphere() << endl;
    //cout << "the basketball's volume is:" << x->volume() << endl;
    //x.~ball();
}


