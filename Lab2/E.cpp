#include <iostream>
#include <cmath>
#include <iomanip>

double mean(double psi[], double pdf[], double const dv, unsigned size)
{
    if(size == 1)
    {
        return (psi[0]*pdf[0]*dv);
    }
    else
    {
         return mean(psi, pdf, dv, size / 2) + mean(psi +size / 2, pdf + size/2, dv, size - size / 2);
    }
}

int main()
{
    double const f_pi = 3.14159265359f;
    unsigned size = 1000000;
    double T = 0.f;
    std::cout <<"Enter T: ";
    std::cin >> T;
    double min = -T;
    double max = T;
    double dv = (max - min)/size;
    double v = min;
    double *pdf = nullptr, *psi = nullptr;
    pdf = new double[size];
    psi = new double[size];

    for (long long int i = 0; i < size; i++)
    {
         psi[i] = fabs(v);
         pdf[i] = exp(-v*v/T)/sqrt(T*f_pi);
         v += dv;

    }
    std::cout<<std::setprecision(10)<<mean(psi, pdf, dv, size)<<std:: endl;
    delete[] psi;
    delete[] pdf;
    return 0;

}
