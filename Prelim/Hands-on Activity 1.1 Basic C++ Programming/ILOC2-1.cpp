#include <iostream>

double kelvinToFahrenheit(double kelvin);

int main(){

    double kelvin = 300;

    std::cout << "The Kelvin temperature is: " << kelvin << std::endl;
    std::cout << "The temperature in Fahrenheit is: " << kelvinToFahrenheit(kelvin) << std::endl;

    return 0;
}

double kelvinToFahrenheit(double kelvin){
    double fahrenheit = (kelvin - 273.15) * 9/5 + 32;
    return fahrenheit;
}