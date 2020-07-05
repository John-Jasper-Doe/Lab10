/**
 * @file controller.hpp
 * @brief Discription of the class "Controller".
 *
 * @details
 * The controller is a class "Observer". He receives a notification of a change
 * in the "Subject" and processes the information received.
 *
 * @author Maxim <john.jasper.doe@gmail.com>
 * @date 2020
 */

#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

#include <memory>
#include <string>
#include "common/cmdpool.hpp"
#include "common/counter.hpp"
#include "utils/observer.hpp"

/** @brief The namespace of the BULKMT project */
namespace bulkmt {
/** @brief The namespace of the Core */
namespace core {

/** @brief The controller is a class "Observer" */
class controller final : public utils::observer<std::string>,
                         public std::enable_shared_from_this<controller> {
  /** @brief Depth of nesting commands. */
  std::size_t depth_{0};

  /** @brief the count commands per block. */
  std::size_t commands_per_block_{0};

  common::counter counter_{};

  std::unique_ptr<common::cmd_pool> pool_;

  //  std::unique_ptr<jjd::logger> logger_;   /**< - pointer of the logger. */
  //  jjd::pool<std::string> pool_;           /**< - the pool of the commands. */
  //  std::shared_ptr<jjd::reader> reader_;   /**< - the reader from console. */
  //  std::ofstream log_file_;                /**< - file for logging. */

  //    static bool init_logger_; /**< - switcher to initialize log-file. */

public:
  /** @brief The default constructor. */
  controller() = default;

  /** @brief The default distructor. */
  virtual ~controller() noexcept override;

  /**
   * @brief Update on the change in the state of the subject.
   * @param [in] str - data from subject.
   */
  void update(const std::string& str) override;

  /** @brief Start the process of receiving data. */
  void start();

  /** @brief Resetting data from the command pool. */
  void flush();

  /**
   * @brief Setter to install number of commands in the block.
   * @param [in] value - number.
   */
  void set_commands_per_block(size_t value) noexcept {
    commands_per_block_ = value;
    //    pool_.set_pool_size(value);
  }

  /**
   * @brief Setter to install the reader.
   * @param [in] rdr - pointer to the reader.
   */
  //  void set_reader(std::shared_ptr<jjd::reader> rdr) noexcept {
  //    reader_ = rdr;
  //  }
};

} /* core:: */
} /* bulkmt:: */

#endif /* CONTROLLER_HPP_ */
