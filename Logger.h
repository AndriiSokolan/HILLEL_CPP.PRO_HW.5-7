#ifndef LOGGER_H
#define LOGGER_H

#include <string>           // ��� ������ �� ��������
#include <initializer_list> // ��� ������ � std::initializer_list
#include <sstream>          // ��� ������ � ��������
#include <fstream>          // ��� ������ � �������
#include <chrono>           // ��� ��������� �������� �������
#include <iomanip>          // ��� �������������� �������

// ������������ ��� ������� ������ �����������
enum class LogLevel {
    INFO,    // �������������� ���������
    WARNING, // ��������������
    ERROR    // ������
};

// ����� Logger ��������� ������� Singleton
class Logger {
public:
    // ����� ��� ��������� ������������� ���������� ������
    static Logger& getInstance();

    // ����� ��� ����������� ��������� � ��������� ������
    void log(const std::string& message, LogLevel level = LogLevel::INFO);

    // ������ ��� ����������� ��������� ������ ����������
    template <typename Container>
    void logContainer(const Container& container);

    // ������������� ��� ����������� std::initializer_list
    template <typename T>
    void logContainer(const std::initializer_list<T>& ilist);

private:
    Logger(); // ��������� �����������: ��������� ��������� ������� ��� ������

    // ����� ��� ��������� �������� ������� � ��������� �������
    std::string getCurrentTime() const;

    // ����� ��� �������������� ������ ����������� � ������
    std::string getLevelString(LogLevel level) const;
};

// ���������� ��������� ������� ��� ����������� �����������
template <typename Container>
void Logger::logContainer(const Container& container) {
    std::ostringstream oss; // ������� ����� ��� ������������ ������
    oss << "[CONTAINER] ";
    for (const auto& elem : container) {
        oss << elem << " "; // ��������� �������� ���������� � ������
    }
    log(oss.str(), LogLevel::INFO); // �������� ���������� ������
}

// ���������� ��������� ������� ��� std::initializer_list
template <typename T>
void Logger::logContainer(const std::initializer_list<T>& ilist) {
    std::ostringstream oss; // ����� ��� ������������ ������
    oss << "[INITIALIZER_LIST] ";
    for (const auto& elem : ilist) {
        oss << elem << " ";
    }
    log(oss.str(), LogLevel::INFO); // �������� ��� INFO
}

#endif // LOGGER_H
