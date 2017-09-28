#include <iostream>
#include <glog/logging.h>

int main() {
    google::InitGoogleLogging("sub0");
    FLAGS_logtostderr = true;
    std::cout << "This is sub module0!" << std::endl;
    LOG(INFO) << "Sub0 Found " << 5 << " cookies";
    return 0;
}