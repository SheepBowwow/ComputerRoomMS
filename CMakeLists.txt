# CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# project 名称
project(ComputerRoomMS)

# 设置CMake 构建版本，默认为 Release
set(CMAKE_BUILD_TYPE "Debug")

# 设置CMP0076策略为NEW，以使用新的默认行为 避免 target_sources 警告
cmake_policy(SET CMP0076 NEW)

# 创建变量 SOURCE 包含所有 cpp 文件
set(SOURCES 
    src/main.cpp
    src/mainMenu.cpp
    src/student.cpp
    src/teacher.cpp
    src/manager.cpp
    src/loginIn.cpp
)

# 创建变量 DATA_FILES 包含 txt 文件 用于读写数据
set(DATA_FILES
    dataFile/admin.txt    
    dataFile/student.txt    
    dataFile/computerRoom.txt    
    dataFile/teacher.txt    
    dataFile/order.txt    
)

# 用所有的源文件生成一个可执行文件 因为这里定义了SOURCE变量，所以就不需要罗列cpp文件了
add_executable(ComputerRoomMS ${SOURCES})

# 设置包含头文件 (库) 路径
target_include_directories(ComputerRoomMS PUBLIC ${PROJECT_SOURCE_DIR}/include)

# 指定 txt 文件
# target_sources(ComputerRoomMS PUBLIC ${DATA_FILES})