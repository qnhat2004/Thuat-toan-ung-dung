#include <bits/stdc++.h>
using namespace std;

#define fix fixed << setprecision(5)

// cx + d = 0 -> x = -d/c
void pt_bac1(double c, double d) {
    cout << fix << -d / c;
}

// bx^2 + cx + d = 0
void pt_bac2(double b, double c, double d) 
{
    double delta = c*c - 4*b*d;
    double x1, x2;

    if (delta > 0) {
        x1 = (-c + sqrt(delta)) / 2*b;
        x2 = (-c - sqrt(delta)) / 2*b;
        cout << fix << x1 << "\n" << x2 << endl; 
    }
    
    else if (delta == 0)
        cout <<  fix << -c / 2*b << endl;

    else 
        cout << "Vo nghiem\n";
}

// Cubic polynomial: ax^3 + bx^2 + cx + d = 0
void pt_bac3(double a, double b, double c, double d) 
{
    double delta0 = b*b - 3*a*c;
    double delta1 = 2*b*b*b - 9*a*b*c + 27*a*a*d;
    double C = pow((delta1 + sqrt(delta1*delta1 - 4*delta0*delta0*delta0)) / 2, 1.0/3);
    double x1 = (-b - (C + delta0/C)) / (3*a);
    double x2 = (-b + 0.5*(sqrt(3.0)*C - delta0/C + sqrt(3.0)*sqrt(delta1 + delta0*delta0/C))) / (3*a);
    double x3 = (-b + 0.5*(-sqrt(3.0)*C - delta0/C + sqrt(3.0)*sqrt(delta1 + delta0*delta0/C))) / (3*a);

    cout << fix << x1 << " " << x2 << " " << x3 << endl;
}

int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a || b || c) {
        if (a)
            pt_bac3(a, b, c, d);
        else if (b)
            pt_bac2(b, c, d);
        else
            pt_bac1(c, d);
    }

    else {
        cout << "Phuong trinh vo nghiem";
    }

    return 0;
}