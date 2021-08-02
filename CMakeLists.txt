cmake_minimum_required(VERSION 3.14)

project(Hexagon_Task_Server LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QT_REQUIRED_LIBS Core Network)

find_package(QT NAMES Qt5 Qt6 COMPONENTS ${QT_REQUIRED_LIBS} REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS ${QT_REQUIRED_LIBS} REQUIRED)


add_executable(Hexagon_Task_Server
  main.cpp
  mytcpserver.h mytcpserver.cpp
  httpsocket.h httpsocket.cpp
  httpresponse.h httpresponse.cpp
  httprequest.h httprequest.cpp
  requestdispatcher.h requestdispatcher.cpp
)
foreach(suffix ${QT_REQUIRED_LIBS})
    target_link_libraries(Hexagon_Task_Server Qt${QT_VERSION_MAJOR}::${suffix})
endforeach()

