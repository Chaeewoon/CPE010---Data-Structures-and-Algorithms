#include <iostream>
#include <cmath>

class Triangle{
    private:
        double totalAngle, angleA, angleB, angleC, sideA, sideB, sideC;
    public:
        Triangle(double A, double B, double C, double side1, double side2, double side3);
        void setAngles(double A, double B, double C);
        const bool validateTriangle();
        double computePerimeter();
        double computeArea();
        void triangleInfo();

};


int main(){
    Triangle set1(40, 30, 110, 5, 5, 5);
    if(set1.validateTriangle()){
        std::cout << "The shape is a valid triangle.\n";
    }   else{
            std::cout << "The shape is NOT a valid triangle.\n";
    }

    std::cout << "The perimeter is: " << set1.computePerimeter() << std::endl;
    std::cout << "The area is: " << set1.computeArea() << std::endl;
    set1.triangleInfo();

    return 0;
}


Triangle::Triangle(double A, double B, double C, double side1, double side2, double side3){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;

    sideA = side1;
    sideB = side2;
    sideC = side3;
}


void Triangle::setAngles(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;
}


const bool Triangle::validateTriangle() {
    return (totalAngle <= 180);
}

double Triangle::computePerimeter(){
    return sideA + sideB + sideC;
}

double Triangle::computeArea(){
    double sP = (sideA + sideB + sideC) / 2;
    return sqrt(sP * (sP - sideA) * (sP - sideB) * (sP - sideC));
}

void Triangle::triangleInfo(){
    if(angleA < 90 && angleB < 90 && angleC < 90){
        std::cout << "This is an acute triangle.\n";
    }
    else if(angleA > 90 || angleB > 90 || angleC > 90){
        std::cout << "This is an obtuse triangle.\n";
    }
    else{
        std::cout << "Others\n";
    }
}