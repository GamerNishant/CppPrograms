#include <iostream>
using namespace std;
class sample
{
    int width, height;

public:
    void set_values(int, int);
    int area() { return (width * height); }
    friend sample duplicate(sample);
};
void sample::set_values(int a, int b)
{
    width = a;
    height = b;
}
sample duplicate(sample rectparam)
{
    sample rectres;
    rectres.width = rectparam.width * 2;
    rectres.height = rectparam.height * 2;
    return (rectres);
}
int main()
{
    sample rect, rectb;
    rect.set_values(2, 3);
    rectb = duplicate(rect);
    cout << rectb.area();
    return 0;
}
