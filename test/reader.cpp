#include <gtest/gtest.h>
#include <iostream>

// class test_cmd_pool1 : public ::testing::Test {
// protected:
//  std::unique_ptr<std::stringstream> input;
//  std::unique_ptr<std::stringstream> expected;

//  void SetUp() override {
//    input = std::make_unique<std::stringstream>();
//    expected = std::make_unique<std::stringstream>();
//  }

//  void TearDown() override {
//    expected.reset();
//    input.reset();
//  }
//};

// TEST_F(test_cmd_pool, io_test) {
//  *input << "cmd1\ncmd2\ncmd3\ncmd4\ncmd5\n";
//  *expected << "bulk: cmd1, cmd2, cmd3\n" << "bulk: cmd4, cmd5\n";

//  bulkmt::cmd::cmd_pool<> pool;

//  pool.add()
//}

TEST(Test_Reader, test1) {
  std::cout << "Help" << std::endl;
}
