#include <iostream>

// Класс дороги
class Road {
private:
  int length_; // Длина дороги в метрах
  int lanes_; // Количество полос на дороге

public:
  // Конструктор без параметров
  Road() : length_(0), lanes_(0) {}

  // Конструктор с параметрами
  Road(int length, int lanes) : length_(length), lanes_(lanes) {}

  // Метод для установки значений полей
  void setValues(int length, int lanes) {
    length_ = length;
    lanes_ = lanes;
  }

  // Метод для получения длины дороги
  int getLength() const {
    return length_;
  }

  // Метод для получения количества полос на дороге
  int getLanes() const {
    return lanes_;
  }
};

int main() {
  // Получаем данные о дороге
  int length, lanes;
  std::cout << "Введите длину дороги (в метрах): ";
  std::cin >> length;

  std::cout << "Введите количество полос: ";
  std::cin >> lanes;

  // Создаем объект дороги
  Road road(length, lanes);

  // Выводим информацию о дороге
  std::cout << "Длина дороги: " << road.getLength() << " метров" << std::endl;
  std::cout << "Количество полос: " << road.getLanes() << std::endl;

  return 0;
}
