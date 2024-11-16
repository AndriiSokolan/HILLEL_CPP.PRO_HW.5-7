#ifndef LOGGER_H
#define LOGGER_H

#include <string>           // Для работы со строками
#include <initializer_list> // Для работы с std::initializer_list
#include <sstream>          // Для работы с потоками
#include <fstream>          // Для работы с файлами
#include <chrono>           // Для получения текущего времени
#include <iomanip>          // Для форматирования времени

// Перечисление для задания уровня логирования
enum class LogLevel {
    INFO,    // Информационное сообщение
    WARNING, // Предупреждение
    ERROR    // Ошибка
};

// Класс Logger реализует паттерн Singleton
class Logger {
public:
    // Метод для получения единственного экземпляра класса
    static Logger& getInstance();

    // Метод для логирования сообщений с указанием уровня
    void log(const std::string& message, LogLevel level = LogLevel::INFO);

    // Шаблон для логирования элементов любого контейнера
    template <typename Container>
    void logContainer(const Container& container);

    // Специализация для логирования std::initializer_list
    template <typename T>
    void logContainer(const std::initializer_list<T>& ilist);

private:
    Logger(); // Приватный конструктор: запрещает создавать объекты вне класса

    // Метод для получения текущего времени в строковом формате
    std::string getCurrentTime() const;

    // Метод для преобразования уровня логирования в строку
    std::string getLevelString(LogLevel level) const;
};

// Реализация шаблонной функции для логирования контейнеров
template <typename Container>
void Logger::logContainer(const Container& container) {
    std::ostringstream oss; // Создаем поток для формирования строки
    oss << "[CONTAINER] ";
    for (const auto& elem : container) {
        oss << elem << " "; // Добавляем элементы контейнера в строку
    }
    log(oss.str(), LogLevel::INFO); // Логируем полученную строку
}

// Реализация шаблонной функции для std::initializer_list
template <typename T>
void Logger::logContainer(const std::initializer_list<T>& ilist) {
    std::ostringstream oss; // Поток для формирования строки
    oss << "[INITIALIZER_LIST] ";
    for (const auto& elem : ilist) {
        oss << elem << " ";
    }
    log(oss.str(), LogLevel::INFO); // Логируем как INFO
}

#endif // LOGGER_H
