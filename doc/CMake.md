#CMake
INCLUDE_DIRECTORIES默认值是空

子目录中CMakeLists文件继承父目录的变量设置，如果在父目录中通过target_link_libraries动态链接某个库，子目录也可以

反过来子目录编译得到的lib也可以在父目录中使用

CMAKE_MODULE_PATH默认是空，可以设置让cmake从指定目录中找Find<package>.cmake，如果cmake在自己的默认目录中找不到的话。比如在mac中<br>
cmake的module目录为/usr/local/Cellar/cmake/3.9.3_1/share/cmake/Modules<br>

##OpenSSL
CMake的Module中有FindOpenSSL，不过不一定找到的openssl的库，比如mac上用brew安装的openssl，它的安装信息为
```bash
This formula is keg-only, which means it was not symlinked into /usr/local,
because Apple has deprecated use of OpenSSL in favor of its own TLS and crypto libraries.

If you need to have this software first in your PATH run:
  echo 'export PATH="/usr/local/opt/openssl/bin:$PATH"' >> ~/.bash_profile

For compilers to find this software you may need to set:
    LDFLAGS:  -L/usr/local/opt/openssl/lib
    CPPFLAGS: -I/usr/local/opt/openssl/include
For pkg-config to find this software you may need to set:
    PKG_CONFIG_PATH: /usr/local/opt/openssl/lib/pkgconfig
```
而FindOpenSSL文档上给了建议
```bash
Set OPENSSL_ROOT_DIR to the root directory of an OpenSSL installation. Set OPENSSL_USE_STATIC_LIBS to TRUE to 
look for static libraries. Set OPENSSL_MSVC_STATIC_RT set TRUE to choose the MT version of the lib.
```
因此启动CMake时可以加上-DOPENSSL_ROOT_DIR=/usr/local/opt/openssl
