#CMake
INCLUDE_DIRECTORIES默认值是空

子目录中CMakeLists文件继承父目录的变量设置，如果在父目录中通过target_link_libraries动态链接某个库，子目录也可以

CMAKE_MODULE_PATH默认是空，可以设置让cmake从指定目录中找Find<package>.cmake，如果cmake在自己的默认目录中找不到的话。比如在mac中<br>
cmake的module目录为/usr/local/Cellar/cmake/3.9.3_1/share/cmake/Modules<br>

