/**
 * @file controller.cpp
 * @brief The implementation of the class "Controller".
 *
 * @author Maxim <john.jasper.doe@gmail.com>
 * @date 2020
 */

#include "controller.hpp"

/** @brief The namespace of the BULKMT project */
namespace bulkmt {
/** @brief The namespace of the Core */
namespace core {

controller::~controller() noexcept {
  if (pool_->size() > 0 && depth_ == 0)
    flush();
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
    std::string str = pool_->as_str();
    pool_->clear();
  }
}

} /* core:: */
} /* bulkmt:: */
