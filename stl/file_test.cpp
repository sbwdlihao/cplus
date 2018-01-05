//
// Created by bencong on 2017/11/27.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <fstream>

using namespace std;

TEST(file, write) {
  // 能成功往文件中写入一个字符h
  // 但是如果没有加ate则是从头开始写，
  fstream *s = new  fstream("/tmp/fstream_test", s->binary | s->out | s->app);
  *s << "abc";
  s->put('d');
  const char *a = "hello";
  s->write(a, strlen(a));
  s->flush();
  s->close();
  delete s;
}

TEST(file, read_write) {
  // 开启读写模式是能写入成功的
  fstream *s = new  fstream("/tmp/fstream_test", s->binary | s->in | s->out | s->app);
  const char *a = "hello";
  s->write(a, strlen(a));
  s->flush();
  s->close();
  delete s;
}

// 如果获取文件的长度
TEST(file, file_length) {
  fstream *s = new  fstream("/tmp/fstream_test_length2", s->binary | s->in);
  if (s->is_open()) {
//    s->seekg(s->end); 这种写法不对，如果是一个空的文件，获取的g是2
    s->seekg(0, s->end);
    std::cout << "g = " << s->tellg() << std::endl;
  }
  s->close();
  delete s;
}

// 起初文件不存在，然后读这个空文件
TEST(file, read_empty_write) {
  fstream *s = new  fstream("/tmp/fstream_test", s->binary | s->in | s->out | s->app);
  if (s->is_open()) {
    s->seekg(0, std::ios_base::end);
    std::cout << "g = " << s->tellg() << std::endl;
    int l = s->tellg();
    if (l > 0) {
      // 如果文件有内容，g和p的值是相同的，比如文件中有hello，g=p=5
      std::cout << "g = " << s->tellg() << std::endl;
      std::cout << "p = " << s->tellp() << std::endl;
      // 调用了seekg(beg)之后p也被置为0
      s->seekg(std::ios_base::beg);
      std::cout << "seekg good = " << s->good() << std::endl; // good = 1显示成功
      std::cout << "g = " << s->tellg() << std::endl;
      std::cout << "p = " << s->tellp() << std::endl;
      char buffer[l];
      while(s->peek() != EOF) {
        s->read(buffer, l);
        std::cout << "state = " << s->rdstate() << std::endl;
        std::cout << "read good = " << s->good() << std::endl;
        std::cout << "read num = " << s->gcount() << std::endl;
        std::cout << "g = " << s->tellg() << std::endl;
        std::cout << "p = " << s->tellp() << std::endl;
      }
    }
  }
  // 此时在文件末尾
  std::cout << "state = " << s->rdstate() << std::endl;
  // 清除eof状态，如果不清除，后续写入就不会成功
  s->clear();
  std::cout << "state = " << s->rdstate() << std::endl;
  s->seekp(0, s->end);
  std::cout << "seekp good = " << s->good() << std::endl;
  const char *a = "hello";
  s->write(a, strlen(a));
  std::cout << "write good = " << s->good() << std::endl; // good = 0
  // 写入成功后，p和g都向前进，比如在文件是空的情况下写入hello，p=q=5
  std::cout << "g = " << s->tellg() << std::endl;
  std::cout << "p = " << s->tellp() << std::endl;
  s->flush();
  s->close();
  delete s;
}

// 测试打开的文件是否能重命名，测试结果是可以的，不需要先关闭文件再重命名
TEST(file, rename) {
  fstream *s = new  fstream("/tmp/fstream_name0", s->binary | s->out | s->app);
  if (std::rename("/tmp/fstream_name0", "/tmp/fstream_name1") == 0) {
    std::cout << "rename success" << std::endl;
  }
  s->close();
}

void* PersistThread(void *arg) {
  auto *params = (std::vector<void*>*)arg;
  auto *s = (fstream*)((*params)[0]);
  s->put('h');
  s->flush();
  s->close();
  delete s;
  s = nullptr;
}

TEST(file, write_in_thread) {
  fstream *s = new  fstream("/tmp/fstream_test_thread", s->binary | s->out | s->trunc);
  auto args = new std::vector<void*>;
  args->push_back((void*)s);
  pthread_t pt;
  pthread_create(&pt, NULL, &PersistThread, (void*)args);
  // 主线程调用pthread_exit，这样主线程退出后，子线程不会自动退出，否则子线程会自动退出
  pthread_exit(NULL);
}