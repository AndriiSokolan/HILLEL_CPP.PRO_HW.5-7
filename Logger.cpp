#include "Logger.h"
#include <iostream>  // ��� ������ ������ � �������

// ���������� ������ Singleton: ���������� ������������ ��������� ������
Logger& Logger::getInstance() {
    static Logger instance; // ��������� ������������ ��������� ��� ������ ������
    return instance;
}

// ��������� �����������: ������������� �������� �������� �����
Logger::Logger() {}

// ����� ��� ������ ��������� � ���
void Logger::log(const std::string& message, LogLevel level) {
    // ��������� ���� "log.txt" � ������ ����������
    std::ofstream logFile("log.txt", std::ios::app);
    if (logFile.is_open()) {
        // ���������� �������, ����� � ���������
        logFile << getLevelString(level) << " - " << getCurrentTime() << " - " << message << std::endl;
    }
    else {
        // ���� ���� �� ��������, ������� ��������� �� ������ � �������
        std::cerr << "Error opening log file!" << std::endl;
    }
}

// ��������� �������� ������� � ������� "����:������:�������"
std::string Logger::getCurrentTime() const {
    auto now = std::chrono::system_clock::now();            // ������� �����
    auto time_t_now = std::chrono::system_clock::to_time_t(now); // �������������� � time_t
    struct tm timeInfo;
    localtime_s(&timeInfo, &time_t_now);                    // ���������������� ��������������
    std::ostringstream oss;
    oss << std::put_time(&timeInfo, "%H:%M:%S");            // �������������� �������
    return oss.str();                                       // ������� ������� � ���� ������
}

// �������������� ������ ����������� � ������
std::string Logger::getLevelString(LogLevel level) const {
    switch (level) {
    case LogLevel::INFO: return "[INFO]";
    case LogLevel::WARNING: return "[WARNING]";
    case LogLevel::ERROR: return "[ERROR]";
    default: return "[UNKNOWN]";
    }
}
