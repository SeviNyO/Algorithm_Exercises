cmake_minimum_required(VERSION 3.29)
project(Algorithm_Exercises)

set(CMAKE_CXX_STANDARD 14)

# Crear ejecutables para cada ejercicio

# Ejercicio 1
add_executable(ejercicio01 "POO/Ejercicio 1/Ejercicio 1/main.cpp"
        competitive_programming/ejercicio_2.cpp)

# Ejercicio 2
add_executable(ejercicio02 W03_Ejercicios/ejercicio2/ejercicio2.cpp)

# Ejercicio 3
add_executable(ejercicio03 W03_Ejercicios/ejercicio3/ejercicio3.cpp)

# Ejercicio 4
add_executable(ejercicio04 W03_Ejercicios/ejercicio4/ejercicio4.cpp)

# PROGRAMACION COMPETITIVA
add_executable(ejercicio_1 competitive_programming/ejercicio_1.cpp
        competitive_programming/ejercicio_1.cpp)

add_executable(ejercicio_2 competitive_programming/ejercicio_2.cpp
        competitive_programming/ejercicio_2.cpp
        competitive_programming/ejercicio_2.cpp)

add_executable(ejercicio_3 competitive_programming/ejercicio_3.cpp)
add_executable(ejercicio_4 competitive_programming/ejercicio_4.cpp
        competitive_programming/ejercicio_4.cpp)
