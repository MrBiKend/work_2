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
    bool isTollRoad_; // Флаг, указывающий, является ли дорога платной

public:
    // Конструктор без параметров
    Road() : length_(0), lanes_(0), name_(""), isTollRoad_(false) {}

    // Конструктор с параметрами
    Road(int length, int lanes, const std::string& name, bool isTollRoad)
        : length_(length), lanes_(lanes), name_(name), isTollRoad_(isTollRoad) {}

    // Метод для установки значений полей
    void setValues(int length, int lanes, const std::string& name, bool isTollRoad) {
        length_ = length;
        lanes_ = lanes;
        name_ = name;
        isTollRoad_ = isTollRoad;
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

    // Метод для получения информации о том, является ли дорога платной
    bool isTollRoad() const {
        return isTollRoad_;
    }

    // Метод для вывода информации о дороге
    void printInfo() const {
        std::cout << "Дорога \"" << name_ << "\":" << std::endl;
        std::cout << "Длина: " << length_ << " м" << std::endl;
        std::cout << "Количество полос: " << lanes_ << std::endl;
        std::cout << (isTollRoad_ ? "Платная дорога" : "Бесплатная дорога") << std::endl;
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
            file << (isTollRoad_ ? "1" : "0") << std::endl; // Записываем 1 для платной дороги и 0 для бесплатной
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
        return Road(mergedLength, mergedLanes, name_ + " & " + other.name_, isTollRoad_ || other.isTollRoad_);
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

    // Метод для расчета общей стоимости проезда по дороге
    double calculateTollCost(double costPerUnitDistance) const {
        return (length_ / 1000.0) * costPerUnitDistance;
    }
};

int main() {
    // Создаем дорогу
    Road road(1000, 2, "Дорога", true); // Пусть дорога будет платной

    // Выводим информацию о дороге
    road.printInfo();

    // Задаем стоимость проезда за единицу расстояния (например, за 1 км)
    double costPerUnitDistance = 0.05; // Пусть стоимость будет 0.05 доллара за 1 км

    // Рассчитываем и выводим общую стоимость проезда по дороге
    std::cout << "Общая стоимость проезда по дороге: $" << road.calculateTollCost(costPerUnitDistance) << std::endl;

    return 0;
}
