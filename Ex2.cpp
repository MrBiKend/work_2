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

  // Метод для слияния двух дорог
  Road merge(const Road& other, const std::string& newName) const {
    int mergedLength = length_ + other.length_;
    int mergedLanes = std::max(lanes_, other.lanes_);
    return Road(mergedLength, mergedLanes, newName);
  }
};

int main() {
  // Создаем две дороги
  Road road1(1000, 2, "Дорога 1");
  Road road2(1500, 3, "Дорога 2");

  // Объединяем дороги
  Road mergedRoad = road1.merge(road2, "Объединенная дорога");

  // Выводим информацию о дорогах
  road1.printInfo();
  std::cout << std::endl;
  road2.printInfo();
  std::cout << std::endl;

  // Выводим информацию о объединенной дороге
  mergedRoad.printInfo();

  return 0;
}
