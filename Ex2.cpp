#include <iostream>
#include <fstream>
#include <string>
#include <cmath> // Для использования функции округления (std::ceil)

class Road {
private:
    int length_; // Длина дороги в метрах
    int lanes_; // Количество полос на дороге
    std::string name_; // Название дороги
    static constexpr double baseCostPerKm = 10000.0; // Базовая стоимость строительства одного километра дороги
    static constexpr int sectionLength = 100; // Длина одной секции дороги в метрах

public:
    // Конструктор без параметров
    Road() : length_(0), lanes_(0), name_("") {}

    // Конструктор с параметрами
    Road(int length, int lanes, const std::string& name) : length_(length), lanes_(lanes), name_(name) {}

    // Метод для установки значений полей
    void setValues(int length, int lanes, const std::string& name) {
        length_ = length;
        lanes_ = lanes;
        name_ = name;
    }

    // Метод для получения длины дороги
    int getLength() const {
        return length_;
    }

    // Метод для получения количества полос на дороге
    int getLanes() const {
        return lanes_;
    }

    // Метод для получения названия дороги
    std::string getName() const {
        return name_;
    }

    // Метод для вывода информации о дороге
    void printInfo() const {
        std::cout << "Дорога \"" << name_ << "\":" << std::endl;
        std::cout << "Длина: " << length_ << " м" << std::endl;
        std::cout << "Количество полос: " << lanes_ << std::endl;
    }

    // Метод для подсчета стоимости строительства дороги
    double calculateConstructionCost() const {
        double costPerKm = baseCostPerKm * lanes_; // Стоимость строительства за километр дороги, зависящая от количества полос
        return (length_ / 1000.0) * costPerKm; // Стоимость строительства всей дороги в тысячах рублей
    }

    // Метод для сохранения информации о дороге в файл
    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << name_ << std::endl;
            file << length_ << std::endl;
            file << lanes_ << std::endl;
            file.close();
            std::cout << "Информация о дороге сохранена в файл: " << filename << std::endl;
        } else {
            std::cerr << "Ошибка при открытии файла для записи." << std::endl;
        }
    }

    // Метод для объединения двух дорог
    Road merge(const Road& other) const {
        int mergedLength = length_ + other.length_;
        int mergedLanes = std::max(lanes_, other.lanes_);
        return Road(mergedLength, mergedLanes, name_ + " & " + other.name_);
    }

    // Метод для расчета времени проезда по дороге с заданной скоростью
    double calculateTravelTime(int speed) const {
        // Расчет времени проезда в часах
        double timeInHours = static_cast<double>(length_) / (speed * 1000.0 / 3600.0);
        return timeInHours;
    }

    // Метод для вычисления количества необходимых секций дороги
    int calculateNumberOfSections() const {
        return std::ceil(static_cast<double>(length_) / sectionLength);
    }
};

int main() {
    // Создаем дорогу
    Road road(1000, 2, "Дорога");

    // Выводим информацию о дороге
    road.printInfo();

    // Вычисляем и выводим количество секций дороги
    std::cout << "Для дороги необходимо " << road.calculateNumberOfSections() << " секций." << std::endl;

    return 0;
}
