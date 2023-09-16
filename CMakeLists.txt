# CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# project 项目名
project(ComputerRoomMS)

# 设置为Debug模式 默认为Release
set(CMAKE_BUILD_TYPE "Debug")

# 设置以防止target_sources报错
cmake_policy(SET CMP0076 NEW)

# 设置源文件变量
set(SOURCES 
    src/main.cpp
    src/mainMenu.cpp
    src/student.cpp
    src/teacher.cpp
    src/manager.cpp
    src/loginIn.cpp
    src/globalConstant.cpp
    src/computerRoom.cpp
)

# 设置txt文件变量
set(DATA_FILES
    dataFile/admin.txt    
    dataFile/student.txt    
    dataFile/computerRoom.txt    
    dataFile/teacher.txt    
    dataFile/order.txt    
)

# 添加可执行文件目录
add_executable(ComputerRoomMS ${SOURCES})

# 头文件包含目录
target_include_directories(ComputerRoomMS PUBLIC ${PROJECT_SOURCE_DIR}/include)

# txt文件
target_sources(ComputerRoomMS PUBLIC ${DATA_FILES})