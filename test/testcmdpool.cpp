#include <gtest/gtest.h>
#include <iostream>

#include "cmd/cmdpool.hpp"

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

TEST(test_cmd_pool, test_size) {
  bulkmt::cmd::cmd_pool<> pool;
  ASSERT_EQ(pool.size(), 0);

  pool.add("cmd1");
  ASSERT_EQ(pool.size(), 1);

  pool.add("cmd2");
  ASSERT_EQ(pool.size(), 2);

  pool.clear();
  ASSERT_EQ(pool.size(), 0);
}

TEST(test_cmd_pool, test_as_str) {
  bulkmt::cmd::cmd_pool<> pool;
  pool.add("cmd1");
  pool.add("cmd2");
  pool.add("cmd3");
  pool.add("cmd4");

  std::stringstream ss{"cmd1, cmd2, cmd3, cmd4"};
  ASSERT_EQ(pool.as_str(), ss.str());

  pool.clear();
  pool.add("cmd1");
  pool.add("cmd2");

  ss.str("");
  ss << "cmd1, cmd2";

  ASSERT_EQ(pool.as_str(), ss.str());
}

// TEST_F(test_cmd_pool, io_test) {
//  *input << "cmd1\ncmd2\ncmd3\ncmd4\ncmd5\n";
//  *expected << "bulk: cmd1, cmd2, cmd3\n" << "bulk: cmd4, cmd5\n";

//  bulkmt::cmd::cmd_pool<> pool;

//  pool.add()
//}
