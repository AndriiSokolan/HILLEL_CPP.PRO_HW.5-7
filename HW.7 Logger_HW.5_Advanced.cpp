#include <iostream> // Для вывода данных в консоль
#include <vector>   // Подключаем вектор
#include <list>     // Подключаем список
#include <set>      // Подключаем множество
#include "Logger.h" // Подключаем наш класс логгера

int main() {
    // Создаем контейнеры с данными
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    std::list<int> lst = { 10, 20, 30 };
    std::set<int> st = { 100, 200, 300 };

    // Получаем экземпляр Logger (Singleton)
    Logger& logger = Logger::getInstance();

    // Логируем содержимое контейнеров
    logger.logContainer(vec);  // Логируем вектор
    logger.logContainer(lst);  // Логируем список
    logger.logContainer(st);   // Логируем множество

    // Логируем список инициализации
    logger.logContainer({ 1000, 2000, 3000 });

    // Вывод в консоль для подтверждения успешного выполнения
    std::cout << "Logging complete. Check the log file for details." << std::endl;

    return 0; // Программа завершена успешно
}
