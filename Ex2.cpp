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
  std::cout << "Дорога \"" << road.getName() << "\":" << std::endl;
  std::cout << "Длина: " << road.getLength() << " м" << std::endl;
  std::cout << "Количество полос: " << road.getLanes() << std::endl;

  return 0;
}
