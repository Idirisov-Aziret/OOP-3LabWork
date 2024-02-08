#include <iostream>
#include <string>
#include <ctime>

class Timer {
private:
    int seconds;

public:
    Timer(int s) : seconds(s) {}

    Timer(const std::string& time) : seconds(std::stoi(time)) {}

    Timer(int m, int s) : seconds(m * 60 + s) {}

    void run() {
        std::cout << "Timer started." << std::endl;
        while (seconds > 0) {
            std::cout << "Time remaining: " << seconds << " seconds." << std::endl;
            --seconds;
            std::clock_t start = std::clock();
            while ((std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) < 1) {} 
        }
        std::cout << "Time's up! Ringing!" << std::endl;
    }
};

int main() {
    int minutes, seconds;
    std::cout << "Enter minutes: ";
    std::cin >> minutes;
    while (minutes < 0 || minutes > 59) {
        std::cout << "Minutes must be between 0 and 59. Please enter again: ";
        std::cin >> minutes;
    }
    std::cout << "Enter seconds: ";
    std::cin >> seconds;
    while (seconds < 0 || seconds > 59) {
        std::cout << "Seconds must be between 0 and 59. Please enter again: ";
        std::cin >> seconds;
    }

    Timer timer(minutes, seconds); 
    timer.run();

    return 0;
}


/// Second Task 
#include <iostream>
#include <string>

class Nomenclature {
private:
    std::string productName;
    short int price;
    float retailMarkup;
    int quantity;

public:

    Nomenclature(const std::string& product, short int price, float roznas, int quantity)
        : productName(product), price(price), retailMarkup(roznas), quantity(quantity) {}

 
    ~Nomenclature() {
        std::cout << "Товар удален" << std::endl;
    }

 
    float calculateNetIncome() const {
        float retailPrice = price * (1 + retailMarkup / 100);
        return (retailPrice - price) * quantity;
    }

    void displayProductDetails() const {
        std::cout << "Название товара: " << productName << std::endl;
        std::cout << "Оптовая цена: " << price << std::endl;
        std::cout << "Розничная наценка: " << retailMarkup << "%" << std::endl;
        std::cout << "Количество товаров на складе: " << quantity << std::endl;
    }
};

int main() {

    Nomenclature product("Шоколад", 50, 30.0, 100);

    std::cout << "Данные о товаре:" << std::endl;
    product.displayProductDetails();

    std::cout << "Потенциальный чистый доход: " << product.calculateNetIncome() << std::endl;

    return 0;
}


//Third Task

