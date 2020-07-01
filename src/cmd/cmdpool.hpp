/**
 * @file cmdpool.hpp
 * @brief Discription of the class "cmd_pool".
 *
 * @details
 * Class description "Pool". This class is intended for storing commands and
 * their further reset to the console or to a file.
 *
 * @author Maxim <john.jasper.doe@gmail.com>
 * @date 2020
 */

#ifndef CMDPOOL_HPP_
#define CMDPOOL_HPP_

#include <chrono>
#include <sstream>
#include <string>
#include <vector>

/** @brief The namespace of the BULKMT project */
namespace bulkmt {
/** @brief The namespace of the Commands */
namespace cmd {

/** @brief Alias of the commands pool of type. */
using cmd_t = std::string;
/** @brief Alias of the commands pool of type. */
using cmd_pool_t = std::vector<cmd_t>;
/** @brief Alias of the time of the first command added to the pool. */
using first_cmd_time_t = std::chrono::time_point<std::chrono::system_clock>;

/**
 * @brief The template class "cmd_pool".
 * @tparam SIZE - size data in pool (default = 5)
 */
template <std::size_t SIZE = 5>
class cmd_pool final {
  /** @brief The pool of the commands. */
  std::vector<std::string> pool_{};

  /** @brief The first command time. */
  first_cmd_time_t first_cmd_time_{};

public:
  /** @brief The constructor. */
  cmd_pool() = default;

  /** @brief The default distructor. */
  ~cmd_pool() = default;

  /**
   * @brief Adding a command to the pool.
   * @param command [in] - the command.
   */
  void add(const cmd_t&& cmd) {
    if (size() == 0)
      first_cmd_time_ = std::chrono::system_clock::now();

    pool_.emplace_back(std::move(cmd));
  }

  /**
   * @brief Number of the commands in the pool.
   * @return Pool size.
   */
  std::size_t size() const {
    return pool_.size();
  }

  /**
   * @brief Gte first command time.
   * @return First command time.
   */
  first_cmd_time_t first_cmd_time() const {
    return first_cmd_time_;
  }

  /**
   * @brief Get the pool of the commands as string.
   * @return String of the commands.
   */
  const std::string as_str() const {
    std::stringstream ss;

    for (auto cit = pool_.cbegin(); cit != pool_.cend(); ++cit) {
      if (cit != pool_.begin())
        ss << ", ";

      ss << (*cit);
    }

    return ss.str();
  }

  /** @brief Clear the pool. */
  void clear() {
    pool_.clear();
  }
};

} /* cmd:: */
} /* bulkmt:: */

#endif /* CMDPOOL_HPP_ */
