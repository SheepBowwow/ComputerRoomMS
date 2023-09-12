# CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# project 名称
project(ComputerRoomMS)

# 设置CMake 构建版本，默认为 Release
set(CMAKE_BUILD_TYPE "Debug")

# 创建变量 SOURCE 包含所有 cpp 文件
set(SOURCES 
    src/main.cpp
    src/mainMenu.cpp
    src/student.cpp
)

# 用所有的源文件生成一个可执行文件 因为这里定义了SOURCE变量，所以就不需要罗列cpp文件了
add_executable(ComputerRoomMS ${SOURCES})

# 设置包含头文件 (库) 路径
target_include_directories(ComputerRoomMS PUBLIC ${PROJECT_SOURCE_DIR}/include)