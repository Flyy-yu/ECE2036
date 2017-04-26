//
// ECE2036 Program 2 - Complex Number Class implementation
// YOUR NAME HERE
//Peiyu Wang
//

#include <iostream>
#include <string>

#include <math.h>

#include "complex.h"
#include "string-parse.h"

using namespace std;


Complex::Complex()
    :real(0),img(0),error(0) {}     // default constructor
Complex::Complex(double re,double im)   //constructor with value augment
    : real(re),img(im),error(0) {}
Complex::Complex(const std::string& aug)//constructor with string
{

    if ((int)(aug.find(","))>0) {
        // if the number in regular form
        real=(ToDouble(aug.substr(0,aug.find(","))));   
        img=(ToDouble(aug.substr(aug.find(",")+1)));
    } else {
        //if the number in polor form
        double value;
        double angle;
        value = ToDouble(aug.substr(0,aug.find(">")));
        angle = ToDouble(aug.substr(aug.find(">")+1));
        angle = angle*M_PI/180.0;
        real = value*cos(angle);
        img = value*sin(angle);
    }
    error=0;
}
void Complex::seterror()
{
    error = 1;
}
// set real value
void Complex::setreal(double re)
{
    real = re;
}
//set img value
void Complex::setimg(double im)
{
    img=im;
}
//get real value
double Complex::getreal()
{
    return real;
}
//get img value
double Complex::getimg()
{
    return img;
}
//if NaN
double Complex::geterror()
{
    return error;
}
//print out the value
void Complex::printcomplex()
{

    if (getimg()==0) {
        cout<<"= "<<getreal()<<endl;
    } else {
        cout <<"= "<< "("<<getreal() << ","<<getimg()<<")"<<endl;
    }
}

//operator overload +
Complex Complex::operator+(Complex comx)
{
    Complex sum;
    sum.setreal(getreal()+comx.getreal());
    sum.setimg(getimg()+comx.getimg());
    return sum;
}
//operator overload -
Complex Complex::operator-(Complex comx)
{
    Complex minor;
    minor.setreal(getreal()-comx.getreal());
    minor.setimg(getimg()-comx.getimg());
    return minor;
}
//operator overload *
Complex operator*(Complex comx,Complex xxx)
{
    Complex times;

    times.setreal(comx.getreal()*xxx.getreal() - comx.getimg()*xxx.getimg());
    times.setimg(comx.getreal()*xxx.getimg() + xxx.getreal()*comx.getimg());


    return times;
}
//operator overload /
Complex operator/(Complex comx,Complex xxx)
{
    Complex result;

    if (xxx.getreal()!=0 || xxx.getimg()!=0) {
        double top = (comx.getreal()*xxx.getreal() + comx.getimg()*xxx.getimg());
        double bot = (xxx.getreal()*xxx.getreal() + xxx.getimg()*xxx.getimg());

        result.setreal(top / bot);

        top = (xxx.getreal()*comx.getimg() - comx.getreal()*xxx.getimg());
        result.setimg(top / bot);

    } else {
        result.seterror();
    }
    return result;

}
// Implement your other member functions here
// Member functions

// Implement your operators here
// Operators
