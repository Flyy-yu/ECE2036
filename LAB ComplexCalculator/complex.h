//
// ECE20360 Program 2 - Complex Number Class decaration
// YOUR NAME HERE>Peiyu Wang
//

// Class declaration for Complex number class
// ECE3090 Lab 1

#include <iostream>
#include <string>
class Complex {

friend Complex operator*(Complex comx,Complex xxx);
friend Complex operator/(Complex comx,Complex xxx);

private:
	double real,img,error;

public:
	Complex();
	Complex(double re, double im); 
  Complex(const std::string& aug);
    void seterror();
	  void setreal(double re);
    void setimg(double im);
    void printcomplex();
    double getreal();
    double getimg();
    double geterror();
    Complex operator+(Complex comx);
    Complex operator-(Complex comx);
  // Define your constructors here
  // Constructors
  // Define the other required member functions here
  // Member Functions
  // Define your operator overloads here if using member function overloads
  // Define your Data Members here
  // Data Members
public:
};

Complex operator*(Complex comx,Complex xxx);
Complex operator/(Complex comx,Complex xxx);
    
// Define your operator overloads here if using non-member function
// operator overloads.







