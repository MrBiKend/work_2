#include <iostream>
#include <string>

// Класс дороги
class Road {
private:
  int length_; // Длина дороги в метрах
  int lanes_; // Количество полос на дороге
  std::string name_; // Название дороги

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

  // Метод для изменения длины дороги
  void setLength(int length) {
    length_ = length;
  }

  // Метод для изменения количества полос на дороге
  void setLanes(int lanes) {
    lanes_ = lanes;
  }
};

int main() {
  // Получаем данные о дороге
  int length, lanes;
  std::string name;
  std::cout << "Введите название дороги: ";
  std::cin.ignore();
  std::getline(std::cin, name);

  std::cout << "Введите длину дороги (в метрах): ";
  std::cin >> length;

  std::cout << "Введите количество полос: ";
  std::cin >> lanes;

  // Создаем объект дороги
  Road road(length, lanes, name);

  // Выводим информацию о дороге
  road.printInfo();

  // Изменяем длину и количество полос
  int newLength, newLanes;
  std::cout << "Введите новую длину дороги: ";
  std::cin >> newLength;
  road.setLength(newLength);

  std::cout << "Введите новое количество полос: ";
  std::cin >> newLanes;
  road.setLanes(newLanes);

  // Выводим обновленную информацию о дороге
  std::cout << "\nОбновленная информация о дороге:" << std::endl;
  road.printInfo();

  return 0;
}
