#include <iostream>
#include <cmath>
float mean(float psi[], float pdf[], float const dv, unsigned size)
{
     if(size == 1)
    {
        return fma(fma(psi[0], pdf[0], 0), dv, 0);
    }
    else
    {
         return fma(mean(psi, pdf, dv, size / 2), 1 , mean(psi +size / 2, pdf + size/2, dv, size - size / 2));
    }
}

int main()
{
    float const f_pi = 3.14159265359f;
    unsigned size = 100000;
    float min = -1000;
    float max = 1000;
    float dv = (max - min)/size;
    float v = min;
    float T = 0.f;
    std::cout <<"Enter T: ";
    std::cin >> T;
    float *pdf = nullptr, *psi = nullptr;
    pdf = new float[size];
    psi = new float [size];

    for (long long int i = 0; i < size; i++)
    {
         psi[i] = fabs(v);
         pdf[i] = exp(-v*v/T)/sqrt(T*f_pi);
         v += dv;
    }
    std::cout<<mean(psi, pdf, dv, size)<<std:: endl;
    delete[] psi;
    delete[] pdf;
    return 0;

}


