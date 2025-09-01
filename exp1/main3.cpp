#include <iostream>
#include <cmath>
using namespace std;
using std::cout;
using std::cin;
double findArea(double radius, double height) {
    return 2* M_PI *radius * (radius + height);
}
double findArea(double radius) {
    return 4 *M_PI *pow(radius, 2);
}
double findArea(int side) {
    return 6 *pow(side, 2);
}
int main() {
    double cylRadius, cylHeight;
    double sphRadius;
    int Side;
    cout<<"Enter radius and height of the cylinder: ";
    cin>>cylRadius >> cylHeight;
    cout<<"Surface area of the cylinder: " <<findArea(cylRadius, cylHeight) <<" square units" <<std::endl;
    cout<<"Enter radius of the sphere: ";
    cin>>sphRadius;
    cout<<"Surface area of the sphere: " <<findArea(sphRadius) <<" square units" <<std::endl;
    cout<<"Enter side length of the cube: ";
    cin>>Side;
    cout<<"Surface area of the cube: " <<findArea(Side) <<" square units" <<std::endl;
    return 0;
}