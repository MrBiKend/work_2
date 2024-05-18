#include <iostream>
#include <fstream>
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

  // Метод для слияния двух дорог
  Road merge(const Road& other, const std::string& newName) const {
    int mergedLength = length_ + other.length_;
    int mergedLanes = std::max(lanes_, other.lanes_);
    return Road(mergedLength, mergedLanes, newName);
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

  // Метод для загрузки информации о дороге из файла
  void loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
      std::getline(file, name_);
      file >> length_;
      file >> lanes_;
      file.close();
      std::cout << "Информация о дороге загружена из файла: " << filename << std::endl;
    } else {
      std::cerr << "Ошибка при открытии файла для чтения." << std::endl;
    }
  }
};

int main() {
  // Создаем дорогу
  Road road(1000, 2, "Дорога");

  // Сохраняем информацию о дороге в файл
  road.saveToFile("road.txt");

  // Создаем новый объект дороги
  Road newRoad;

  // Загружаем информацию о дороге из файла
  newRoad.loadFromFile("road.txt");

  // Выводим информацию о новой дороге
  std::cout << "\nИнформация о новой дороге:" << std::endl;
  newRoad.printInfo();

  return 0;
}
