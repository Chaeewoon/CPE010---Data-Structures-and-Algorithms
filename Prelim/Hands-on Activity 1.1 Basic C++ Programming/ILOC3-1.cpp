#include <iostream>
#include <cmath>

double distanceTwoPoints(double x1, double y1, double x2, double y2);

int main(){
    double x1, y1, x2, y2;

    std::cout << "Enter the first distance(x): ";
    std::cin >> x1;
    std::cout << "Enter the first distance(y): ";
    std::cin >> y1;

    std::cout << "\nEnter the second distance(x): ";
    std::cin >> x2;
    std::cout << "Enter the second distance(y): ";
    std::cin >> y2;

    std::cout << "\nThe distance between the two points is: " << distanceTwoPoints(x1, y1, x2, y2) << std::endl;

    return 0;
}

double distanceTwoPoints(double x1, double y1, double x2, double y2){
    double distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    return distance;
}