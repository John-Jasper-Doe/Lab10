/**
 * @file cmdpool.hpp
 * @brief Discription of the class "cmd_pool".
 *
 * @author Maxim <john.jasper.doe@gmail.com>
 * @date 2020
 */

#include "cmdpool.hpp"

/** @brief The namespace of the BULKMT project */
namespace bulkmt {
/** @brief The namespace of the Commands */
namespace cmd {

void cmd_pool::add(const cmd_t&& cmd) {
  if (size() == 0)
    first_cmd_time_ = std::chrono::system_clock::now();

  pool_.emplace_back(std::move(cmd));
}

std::size_t cmd_pool::size() const {
  return pool_.size();
}

first_cmd_time_t cmd_pool::first_cmd_time() const {
  return first_cmd_time_;
}

std::string cmd_pool::as_str() const {
  std::stringstream ss;

  for (auto cit = pool_.cbegin(); cit != pool_.cend(); ++cit) {
    if (cit != pool_.begin())
      ss << ", ";

    ss << (*cit);
  }

  std::string str{"bulk: " + ss.str()};
  return str;
}

void cmd_pool::clear() {
  pool_.clear();
}

} /* cmd:: */
} /* bulkmt:: */
