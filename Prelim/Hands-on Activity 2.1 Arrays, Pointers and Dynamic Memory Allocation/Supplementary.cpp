#include <iostream>
#include <string>

//Problem 1
class Fruits{
    private:
        std::string fruitsName;
        int fruitsPrice;
        int fruitsQuantity;
    public:
    //constructor
    Fruits(std::string newName = "Blank", int newPrice = 0, int newQuantity = 0){
            fruitsName = std::move(newName);
            fruitsPrice = newPrice;
            fruitsQuantity = newQuantity;
        }
    //deconstructor
    ~Fruits(){
    }
    //copy constructor
    Fruits (const Fruits &copyFruit){
        fruitsName = copyFruit.fruitsName;
        fruitsPrice = copyFruit.fruitsPrice;
        fruitsQuantity = copyFruit.fruitsQuantity;              
    }
    //copy assignment operator
    Fruits& operator=(const Fruits& copy){
        if(this != &copy){
            fruitsName = copy.fruitsName;
            fruitsPrice = copy.fruitsPrice;
            fruitsQuantity = copy.fruitsQuantity;
        }
        return *this;
    }

    //sum
    double calculateSum(){
        return fruitsPrice * fruitsQuantity;
    }

    //details
    void printFruits(){
        std::cout << "Fruit Name: " << fruitsName << std::endl;
        std::cout << "Fruit Price: " << fruitsPrice << std::endl;
        std::cout << "Fruit Quantity: " << fruitsQuantity << std::endl;
        std::cout << "" << std::endl;  
    }
};

class Vegetables{
    private:
        std::string vegetableName;
        int vegetablePrice;
        int vegetableQuantity;

    public:
    //constructor
    Vegetables(std::string newName = "JohnPork", int newPrice = 0, int newQuantity = 0){
        vegetableName = std::move(newName);
        vegetablePrice = newPrice;
        vegetableQuantity = newQuantity;
    }

    //deconstructor
    ~Vegetables(){
    }

    //copy constructor
    Vegetables (const Vegetables &copyVegetable){
        vegetableName = copyVegetable.vegetableName;
        vegetablePrice = copyVegetable.vegetablePrice;
        vegetableQuantity = copyVegetable.vegetableQuantity;
    }

    Vegetables& operator=(const Vegetables& copy){
        if(this != &copy){
            vegetableName = copy.vegetableName;
            vegetablePrice = copy.vegetablePrice;
            vegetableQuantity = copy.vegetableQuantity;
        }
        return *this;
    }

    //sum 
    double calculateSum(){
        return vegetablePrice * vegetableQuantity;
    }

    //details
    void printVegetables(){
        std::cout << "Vegetable Name: " << vegetableName << std::endl;
        std::cout << "Vegetable Price: " << vegetablePrice << std::endl;
        std::cout << "Vegetable Quantity: " << vegetableQuantity << std::endl;
        std::cout << "" << std::endl;  
    }
};

int main(){
    //Problem 2
    const int fvSize = 2;
    double total = 0;

    Fruits* fruitList[fvSize];
    Vegetables* vegetablesList[fvSize];

    std::string fruitsName[fvSize] = {"Apple", "Banana"};
    int fruitPrice[fvSize] = {10, 10};
    int fruitQuantity[fvSize] = {7, 8};

    std::string vegetablesName[fvSize] = {"Broccoli", "Lettuce"};
    int vegetablesPrice[fvSize] = {60, 50};
    int vegetablesQuantity[fvSize] = {12, 10};

    for(int i = 0; i < fvSize; i++){
       fruitList[i] = new Fruits(fruitsName[i], fruitPrice[i], fruitQuantity[i]);
    }

    for(int i = 0; i < fvSize; i++){
        fruitList[i]->printFruits();
    }

    for(int i = 0; i < fvSize; i++){
       vegetablesList[i] = new Vegetables(vegetablesName[i], vegetablesPrice[i], vegetablesQuantity[i]);
    }

    for(int i = 0; i < fvSize; i++){
        vegetablesList[i]->printVegetables();
    }

    //Problem 3
    //Fruits
    for(int i = 0; i < fvSize; i++){
        total = total + fruitList[i]->calculateSum();
    }
    //Vegetables
    for(int i = 0; i < fvSize; i++){
        total = total + vegetablesList[i]->calculateSum();
    }

    std::cout << "\nTotal Amount: PHP " << total << std::endl;

    //Problem 4
    delete vegetablesList[1];
    vegetablesList[1] = nullptr;

    std::cout << "\nAfter deleting Lettuce:\n";

    
    for(int i = 0; i < fvSize; i++){
        fruitList[i]->printFruits();
    }

    for(int i = 0; i < fvSize - 1; i++){
        vegetablesList[i]->printVegetables();
    }

    return 0;
}