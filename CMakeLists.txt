cmake_minimum_required(VERSION 3.30)
project(projet C)

set(CMAKE_C_STANDARD 99)

add_executable(projet LCaca.c
        colonne.c
        colonne.h
        main.c
        dataframe.c
        dataframe.h
)
