#include <iostream>
#include <cmath>
float mean(float psi[], float pdf[], float const dv, unsigned size)
{
    float sum = 0.0;
    float mistake = 0.0;
    float sum_mistake = 0.0;
    for(unsigned i = 0; i < size; i++)
   {
        float y = psi[i]*pdf[i]*dv - mistake;
        float t = sum + y;
        mistake = (t-sum) - y;
        sum_mistake += mistake;
        sum = t;
   }
   std::cout<<sum_mistake<<std::endl;
   return sum;
}




int main()
{
    float const f_pi = 3.14159265359f;
    unsigned size = 10000;
    float T = 0.f;
    std::cout <<"Enter T: ";
    std::cin >> T;
    float min = -T;
    float max = T;
    float v = min;
    float dv = (max - min)/size;
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
