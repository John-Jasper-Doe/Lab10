/**
 * @file controller.cpp
 * @brief The implementation of the class "Controller".
 *
 * @author Maxim <john.jasper.doe@gmail.com>
 * @date 2020
 */

#include "controller.hpp"
#include <iostream>
#include "common/counter.hpp"
#include "io/conlogger.hpp"
#include "io/filelogger.hpp"

/** @brief The namespace of the BULKMT project */
namespace bulkmt {
/** @brief The namespace of the Core */
namespace core {

controller::controller(std::size_t cmd_per_block) noexcept : commands_per_block_(cmd_per_block) {}

controller::~controller() noexcept {
  if (pool_->size() > 0 && depth_ == 0)
    flush();

  std::cout << "All stats: " << counter_.as_str(true) << std::endl;
}

void controller::update(const std::string& str) {
  if (!str.empty()) {
    counter_.inc_str();

    if (str == "{") {
      if (depth_ == 0) {
        flush();
        ++depth_;
      }
      else
        ++depth_;
    }
    else if (str == "}") {
      if (depth_ == 0)
        throw std::runtime_error("invalid closed block without opened ones");
      else {
        --depth_;

        if (depth_ == 0) {
          counter_.inc_blk();
          flush();
        }
      }
    }
    else {
      counter_.inc_cmd();
      pool_->add(std::move(str));

      if (depth_ == 0 && pool_->size() == commands_per_block_)
        flush();
    }
  }
}

void controller::flush() {
  if (pool_->size() > 0) {
    common::counter diff = counter_ - prev_cnt_;
    std::string str = pool_->as_str();
    pool_->clear();

    io::filelogger fl(str, pool_->first_cmd_time(), diff);
    io::conlogger cl(std::cout, str, diff);

    file_pool_.push([&fl]() { return fl.start(); });
    console_pool_.push([&cl]() { return cl.start(); });

    prev_cnt_ = counter_;
  }
}

} /* core:: */
} /* bulkmt:: */
