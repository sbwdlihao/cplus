#include <iostream>
#include <glog/logging.h>

int main() {
    google::InitGoogleLogging("main");
    FLAGS_logtostderr = true;
    std::cout << "Hello, World!" << std::endl;
    LOG(INFO) << "Found " << 5 << " cookies";
    return 0;
}