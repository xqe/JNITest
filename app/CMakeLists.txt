#指定需要CMAKE的最小版本
cmake_minimum_required(VERSION 3.4.1)

#设置生成的so动态库最后输出的路径  ps：PROJECT_SOURCE_DIR表示src所在目录，即目录..\JNITest\app
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/libs/${ANDROID_ABI})

#设置头文件搜索路径（和此txt同个路径的头文件无需设置），可选
#INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/common)

#指定用到的系统库或者NDK库或者第三方库的搜索路径，可选。
#LINK_DIRECTORIES(/usr/local/lib)

add_library( # Sets the name of the library.
             cmake_test_lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/cmake_test.cpp)

target_link_libraries( # Specifies the target library.
                       cmake_test_lib

                       # Links the target library to the log library
                       # included in the NDK.
                        log )