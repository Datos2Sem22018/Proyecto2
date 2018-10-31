cmake_minimum_required(VERSION 3.10)
project(Proyecto2)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp
        Juego/Aliado/Aliado.cpp Juego/Aliado/Aliado.h
        Juego/Enemigo/Enemigo.cpp Juego/Enemigo/Enemigo.h
        Juego/Mapa/Obstaculo.cpp Juego/Mapa/Obstaculo.h
        Juego/Interfaz/PantallaP/PantallaP.cpp Juego/Interfaz/PantallaP/PantallaP.h
        Juego/Rutas/Rutas.cpp Juego/Rutas/Rutas.h
        Juego/Interfaz/Start/StartW.cpp Juego/Interfaz/Start/StartW.h
        Juego/Mapa/Mapa.cpp Juego/Mapa/Mapa.h)


set(EXECUTABLE_NAME "Proyecto2")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

#add_definitions(-DRES="Resources/")
add_executable(${PROJECT_NAME} ${SOURCE_FILES})


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()