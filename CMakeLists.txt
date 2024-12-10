cmake_minimum_required(VERSION 2.8.3)
project(rosQT_gui)

add_compile_options(-std=c++11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
# auto processing .ui and moc, however now really woring
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTORCC ON)

# SET(CMAKE_BUILD_TYPE Release)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

catkin_package(
  CATKIN_DEPENDS roscpp rospy std_msgs
)

qt5_wrap_ui(UIC src/mainwindow.ui)
qt5_wrap_cpp(MOC_FILES include/rosQT_gui/mainwindow.h)

add_executable(${PROJECT_NAME}_node
  src/main.cpp
  src/mainwindow.cpp
  ${MOC_FILES}
)

target_sources(${PROJECT_NAME}_node PRIVATE ${UIC})

target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
  Qt5::Widgets
  Qt5::Core
  Qt5::Gui
)
