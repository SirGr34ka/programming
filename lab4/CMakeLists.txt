cmake_minimum_required(VERSION 3.5) # Минимальная версия CMake

project(lab4) # Имя проекта

find_package(OpenCV REQUIRED) # Поиск пакета OpenCV
add_executable(lab4 main.cpp) # Создание исполняемого файла
target_link_libraries(lab4 ${OpenCV_LIBS}) # Линковка с библиотеками OpenCV