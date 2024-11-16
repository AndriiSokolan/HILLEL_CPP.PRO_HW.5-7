# Минимальная версия CMake
cmake_minimum_required(VERSION 3.10)

# Название проекта
project(LoggerAdvanced)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем исполняемый файл с указанием нового имени основного файла
add_executable(LoggerAdvanced
    "HW.7 Logger_HW.5_Advanced.cpp"
    Logger.cpp
)

# Подключаем заголовочные файлы
target_include_directories(LoggerAdvanced PUBLIC "${PROJECT_SOURCE_DIR}")
