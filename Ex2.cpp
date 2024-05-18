#include <iostream>

// Класс дороги
class Road {
private:
  int length; // Длина дороги в метрах
  int lanes; // Количество полос на дороге

public:
  // Конструктор без параметров
  Road() {}

  // Метод для установки значений полей с клавиатуры
  void setValuesFromInput() {
    std::cout << "Введите длину дороги (в метрах): ";
    std::cin >> length;

    std::cout << "Введите количество полос: ";
    std::cin >> lanes;
  }

  // Метод для получения длины дороги
  int getLength() {
    return length;
  }

  // Метод для получения количества полос на дороге
  int getLanes() {
    return lanes;
  }
};

int main() {
  // Создаем объект дороги
  Road road;

  // Устанавливаем значения полей с клавиатуры
  road.setValuesFromInput();

  // Выводим информацию о дороге
  std::cout << "Длина дороги: " << road.getLength() << " метров" << std::endl;
  std::cout << "Количество полос: " << road.getLanes() << std::endl;

  return 0;
}

