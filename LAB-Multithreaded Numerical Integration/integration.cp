    // Parallel Numerical Integration
// YOUR NAME HERE

//  Please insert code where indicated in the code below.  Follow the instructions
//   given in the comments and in the lab description.

#include <iostream>
#include <vector>
#include <array>
#include <math.h>
#include <time.h>
#include "gthread.h"

using namespace std;
gthread_mutex_t m;
//  Write code to declare a global zero-length vector of doubles called 'poly_coeffs'
//   which will be used to store the polynomial coefficients
vector<double> poly_coeffs;

int test_sum;
//  Write code to declare a global new-style array of 10 doubles called 'partial_sums'
//   which will be used to store the result of the subintegrals
double partial_sums[10];


//  Write a function called 'f' which takes a single double argument and returns a
//   double.  This function will calculate the polynomial for any x.
//printf ("7 ^ 3 = %f\n", pow (7.0, 3.0) )


double f(double x)
{
    double sum=0;
    for (int i =0; i<poly_coeffs.size(); i++) {
        sum = sum + poly_coeffs[i]*pow(x,i);
    }
    return sum;
}


//  Write a function called 'analytic_integral' which takes two double arguments:
//   the lower and upper bounds of the integral.
//   This function should calculate the analytic integral of the polynomial
//   and return the result as a double.
double analytic_integral(double low, double high)
{
    double sum=0;
    for (int i =0; i<poly_coeffs.size(); i++) {
        sum = sum+ (poly_coeffs[i]/(i+1))*(pow(high,i+1) - pow(low,i+1));
    }
    return sum;
}


//  Write a function called 'numerical_integral' which takes two double arguments:
//   the lower and upper bounds of the integral, and one integer argument: the number
//   of grid points to use.  This function should numerically calculate the integral
//   of the polynomial and return the result as a double.

double numerical_integral(double low, double high,int points)
{
    double delta = (high-low)/points;
    double sum = 0;
    for (int i = 0; i < points; i++) {
        sum = sum + delta*f(low+i*delta);
    }
    return sum;
}



//  Write a function called 'threaded_numerical_integral' which takes two double arguments:
//   the lower and upper bounds of the integral, and two integer arguments: the number
//   of grid points to use and the thread number (0-9).  It should have no return value (void)
//   but should numerically calculate the integral of the polynomial and store the result
//   in an element of the partial_sums array (the zeroth thread should store in the zeroth
//   element and so on).  The function must contain a call to EndThread() from the gthread
//   library to terminate the thread.

void threaded_numerical_integral(double low, double high,int points,int thread_number)
{
    partial_sums[thread_number] = numerical_integral(low,high,points);
    EndThread();
}



int main()
{
    time_t start_time;
    time_t end_time;
    double computation_time;
    const int N_threads = 10;
    double x_min = 0;
    double x_max = 100;
    double x_min_m, x_max_m, relative_error;
    const int N_points1 = 1000;
    const int N_points2 = 100000000;

    double temp_coeff, x;
    double analytic_result, num_result1, num_result2, num_result2_threaded;
    double rel_error1, rel_error2, rel_error2_threaded;

    cout << "Welcome to the numerical integrator." << endl;

//  We want the user to enter the coefficients of the polynomial to be integrated.
    cout << "Please enter the coefficient of the 0th-degree term of your polynomial: ";
    int n = 0;
//  This is not a great way to handle the situation, but is sufficient for our purposes.
//   It will continue looping as long as the user enters doubles.  If they enter a character
//   the loop will terminate.
    while (cin >> temp_coeff) {
//  Write code here to place temp_coeff at the end of the vector poly_coeffs
        poly_coeffs.push_back(temp_coeff);

        n++;
        cout << "Please enter the coefficient of the term of degree " << n <<
             ", or 'x' to stop: ";
    }

//  Write code here to print out the stored polynomial coefficients so that the user
//   can check if they were entered correctly.

for(double num:poly_coeffs) {
        cout<<num<<"  ";
    }
    cout<<endl;
//  Here we will call your analytic_integral function to calculate the integral
//   using the analytic solution.
//   Uncomment the following three lines after you have written the function analytic_integral.
    analytic_result = analytic_integral(x_min, x_max);
    cout << "The analytically calculated integral of your polynomial is: " <<
         analytic_result << endl;



//  Here we will do the integral numerically with a small number of grid points.
//   We will do this by calling your numerical_integral function.
//   Uncomment the following four lines after you have written the function numerical_integral.
    num_result1 = numerical_integral(x_min, x_max, N_points1);
    cout<<"the num_result1 is: "<<num_result1<<endl;
    cout<<"the distance is: "<<(analytic_result - num_result1);
    rel_error1 = (analytic_result - num_result1) / analytic_result;
    cout << "The relative error of the numerical integration with " << N_points1 << " points is: "
         << rel_error1 << endl;



//  Here we will do the integral numerically again, but  with a large number of
//   grid points.
//   We will do this by calling your numerical_integral function.
//   In addition, we will measure how long it takes for the computer to perform the
//   calculation using the time and difftime functions.
//   Uncomment the following eight lines after you have written the function numerical_integral.
    time(&start_time);
    num_result2 = numerical_integral(x_min, x_max, N_points2);
    time(&end_time);
    computation_time = difftime(end_time, start_time);
    rel_error2 = (analytic_result - num_result2) / analytic_result;
    cout << "The relative error of the numerical integration with " << N_points2 << " points is: "
         << rel_error2 << endl;
    cout << "The computation time with one thread was: " << computation_time << " seconds." << endl;



//  Here we will do the integral numerically again, with a large number of grid points
//   and using 10 threads.  You must use the CreateThread and WaitAllThreads functions
//   from the gthread library.  You should send your threaded_numerical_integral function
//   as an argument to CreateThread.  Write code here similar to the code above to evaluate
//   the computation time and relative error obtained using N_points2 grid points and 10 threads.
//   Print out your results, as above.
    time(&start_time);
    for (int i = 0; i < 10; ++i) {
        double detal = (x_max - x_min)/10;
        CreateThread(threaded_numerical_integral,x_min+detal*i,x_min+detal*(i+1),N_points2/10,i);
    }
    WaitAllThreads();

    for (int i = 0; i < 10; ++i) {
        num_result2_threaded += partial_sums[i];
    }
    time(&end_time);
    computation_time = difftime(end_time, start_time);

    rel_error2_threaded = (analytic_result - num_result2_threaded)/analytic_result;
    cout << "The relative error of the thread integration with " << N_points2 << " points is: "
         << rel_error2_threaded << endl;
    cout << "The computation time with ten thread was: " << computation_time << " seconds." << endl;

}





