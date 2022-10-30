#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int method_choose( void );
double function ( double x );
void print_result (double a, double b, unsigned int n, double I);
double left_rectangle_method ( double a, double b, unsigned int n);
double right_rectangle_method ( double a, double b, unsigned int n);
double trapezoid_method ( double a, double b, unsigned int n);
double simpss_method ( double a, double b, unsigned int n);

int main()
{

unsigned int variant_of_method;
double a;
double b;
unsigned int n, N;
double I, I1, I2;
const double e = 0.0001;

    printf("\nEnter the left boundary (a): ");
    scanf("%lf", &a);
    printf("\nEnter the right boundary (b): ");
    scanf("%lf", &b);
    printf("\nEnter the number of partition intervals (n): ");
    scanf("%u", &n);

    variant_of_method = method_choose();

    switch(variant_of_method)
    {
    case 1:

    I = left_rectangle_method(a, b, n);
    print_result(a, b, n, I);

    N = 0;
    do
    {
    N = N + 2;
    I1=left_rectangle_method(a, b, N);
    I2=left_rectangle_method(a, b, N+2);
    }
    while( fabs(I2-I1) > e );
    printf("\n\n============================================");
    printf("\n N=%u", N);
    printf("\n============================================");
    printf("\n\nThe calculation of the integral by the Left Rectangles method is finished\n");

    break;

    case 2:

    I = right_rectangle_method(a, b, n);
    print_result(a, b, n, I);

    N = 0;
    do
    {
    N = N + 2;
    I1=left_rectangle_method(a, b, N);
    I2=left_rectangle_method(a, b, N+2);
    }
    while( fabs(I2-I1) > e );
    printf("\n\n============================================");
    printf("\n N=%u", N);
    printf("\n============================================");
    printf("\n\nThe calculation of the integral by the Right Rectangles method is finished\n");

    break;

    case 3:

    I = trapezoid_method(a, b, n);
    print_result(a, b, n, I);

    N = 0;
    do
    {
    N = N + 2;
    I1=left_rectangle_method(a, b, N);
    I2=left_rectangle_method(a, b, N+2);
    }
    while( fabs(I2-I1) > e );
    printf("\n\n============================================");
    printf("\n N=%u", N);
    printf("\n============================================");
    printf("\n\nThe calculation of the integral by the Trapezoid method is finished\n");

    break;


    case 4:

    I = simpss_method(a, b, n);
    print_result(a, b, n, I);

    N = 0;
    do
    {
    N = N + 2;
    I1=left_rectangle_method(a, b, N);
    I2=left_rectangle_method(a, b, N+2);
    }
    while( fabs(I2-I1) > e );
    printf("\n\n============================================");
    printf("\n N=%u", N);
    printf("\n============================================");
    printf("\n\nThe calculation of the integral by the Simps's method is finished\n");

    break;

    }




    return 0;
}


//================================================================================
//Вибір методу

    unsigned int method_choose( void )
{
    unsigned int var;

    printf("\nChoose the method of calculating:");
    printf("\n\n\t1.By Left Rectangles method.");
    printf("\n\t2.By Right Rectangles method.");
    printf("\n\t3.By Trapezoid method.");
    printf("\n\t4.By Simps's method.\n");
    scanf("%u", &var);

    while( var < 1 || var > 4 )
    {
    printf("\n***WARNING! Incorrect variant! Please try again.***\n");
    scanf("%u", &var);
    }

    return var;
}

//=================================================================================
//Функція для якох обчислюється значення інтегралу
    double function ( double x )
{
    double y;

    y = 1/(pow(1.1,2)+(2.2*x)+pow(x,2));//(1.1+x)^2 = 1.1^2 + 2*1.1*x + x^2

    return y;
}

//=================================================================================
//Обрахунок інтегралу за методом лівих прямокутників

    double left_rectangle_method ( double a, double b, unsigned int n)
{
    double h;
    double x;
    double sum = 0;

    h = ( b - a ) / n;
    x = a;

    for ( int k = 0; k <= n-1; k++)
    {
      sum = sum + function(x);
      x = x + h;
    }

    return sum * h;
}

//==================================================================================
//Обрахунок інтегралу за методом правих прямокутників

double right_rectangle_method ( double a, double b, unsigned int n)
{
    double h;
    double x;
    double sum = 0;

    h = ( b - a ) / n;
    x = a;

    for ( int k = 1; k <= n; k++)
    {
      sum = sum + function(x);
      x = x + h;
    }

    return sum * h;
}

//=================================================================================
//Обрахунок інтегралу за методом трапецій

double trapezoid_method ( double a, double b, unsigned int n)
{
    double h;
    double x;
    double sum = 0;

    h = ( b - a ) / n;
    x = a;

    for ( int k = 1; k <= n-1; k++)
    {
      sum = sum + (function(x)+function(x+h))/2;
      x = x + h;
    }

    return sum * h;
}

//=================================================================================
//Обрахунок інтегралу за методом Сімпсона

double simpss_method ( double a, double b, unsigned int n)
{
    double h;
    double x;
    double sum = 0;
    unsigned int k;

    h = ( b - a ) / n;
    x = a;

    for ( int k = 1; k < n-1; k++)
    {
      sum = sum + (function(x)+4*function(x+h/2)+function(x+h))/6;
      x = x + h;
    }

    return sum * h;
}
//=================================================================================
// Вивід результату

void print_result (double a, double b, unsigned int n, double I)
{
    system("cls");
    printf("\n\n+==========================================+");
    printf("\n|                Value input               |");
    printf("\n+==========================================+");
    printf("\n a=%.2lf b=%.2lf n=%u ", a, b, n );
    printf("\n\n+==========================================+");
    printf("\n|                  Result                  |");
    printf("\n+==========================================+");
    printf("\n Integral= %.8lf", I);
    printf("\n============================================");
}

//================================================================================

