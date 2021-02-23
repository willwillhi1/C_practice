#include "ball.h"
#include <iostream>
using namespace std;
const float pi = 3.1415;

//ball's functions 
ball::ball()
{
    weight = new float;
    height = new float;
    *weight = 1.0;
    *height = 1.0;
}
void ball::show()
{
    cout << "I am ball" << endl;
}
void ball::set_WH(float m,float n)
{
    weight = new float;
    height = new float;
    *weight = m;
    *height = n;
}
float ball::sphere()
{
    float r = *height/2;
    return 4*pi*r*r;
}
ball::~ball()
{
    delete weight;
    delete height;
}

//basketball's functions
float basketball::volume()
{
    float  r = *height/2;
    return 4/3*pi*r*r*r;
}
void basketball::show()
{
    cout << "I am basketball" << endl;
}



