#include <iostream>
#include <cmath>

double findArea(double radius, double height) {
    return 2* M_PI *radius * (radius + height);
}

double findArea(double radius) {
    return 4 *M_PI *std::pow(radius, 2);
}

double findArea(int side) {
    return 6 *std::pow(side, 2);
}

int main() {
    double cylRadius, cylHeight;
    double sphRadius;
    int Side;

    std::cout<<"Enter radius and height of the cylinder: ";
    std::cin>>cylRadius >> cylHeight;
    std::cout<<"Surface area of the cylinder: " <<findArea(cylRadius, cylHeight) <<" square units" <<std::endl;

    std::cout<<"Enter radius of the sphere: ";
    std::cin>>sphRadius;
    std::cout<<"Surface area of the sphere: " <<findArea(sphRadius) <<" square units" <<std::endl;

    std::cout<<"Enter side length of the cube: ";
    std::cin>>Side;
    std::cout<<"Surface area of the cube: " <<findArea(Side) <<" square units" <<std::endl;

    return 0;
}