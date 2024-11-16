#include "Logger.h"
#include <iostream>  // Для вывода ошибок в консоль

// Реализация метода Singleton: возвращает единственный экземпляр класса
Logger& Logger::getInstance() {
    static Logger instance; // Создается единственный экземпляр при первом вызове
    return instance;
}

// Приватный конструктор: предотвращает создание объектов извне
Logger::Logger() {}

// Метод для записи сообщения в лог
void Logger::log(const std::string& message, LogLevel level) {
    // Открываем файл "log.txt" в режиме добавления
    std::ofstream logFile("log.txt", std::ios::app);
    if (logFile.is_open()) {
        // Записываем уровень, время и сообщение
        logFile << getLevelString(level) << " - " << getCurrentTime() << " - " << message << std::endl;
    }
    else {
        // Если файл не открылся, выводим сообщение об ошибке в консоль
        std::cerr << "Error opening log file!" << std::endl;
    }
}

// Получение текущего времени в формате "часы:минуты:секунды"
std::string Logger::getCurrentTime() const {
    auto now = std::chrono::system_clock::now();            // Текущее время
    auto time_t_now = std::chrono::system_clock::to_time_t(now); // Преобразование в time_t
    struct tm timeInfo;
    localtime_s(&timeInfo, &time_t_now);                    // Потокобезопасное преобразование
    std::ostringstream oss;
    oss << std::put_time(&timeInfo, "%H:%M:%S");            // Форматирование времени
    return oss.str();                                       // Возврат времени в виде строки
}

// Преобразование уровня логирования в строку
std::string Logger::getLevelString(LogLevel level) const {
    switch (level) {
    case LogLevel::INFO: return "[INFO]";
    case LogLevel::WARNING: return "[WARNING]";
    case LogLevel::ERROR: return "[ERROR]";
    default: return "[UNKNOWN]";
    }
}
