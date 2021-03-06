/**
 * @file conlogger.cpp
 * @brief Implementation of the "Console Logger" class.
 *
 * @author Maxim <john.jasper.doe@gmail.com>
 * @date 2020
 */

#include "conlogger.hpp"

/** @brief The namespace of the BULKMT project */
namespace bulkmt {
/** @brief The namespace of the IO */
namespace io {

conlogger::conlogger(std::ostream& ostrm, const std::string& str,
                     const common::counter& cnt) noexcept
  : ostrm_(ostrm), str_(std::move(str)), cnt_(cnt) {}

conlogger::~conlogger() noexcept {}

common::counter conlogger::start() noexcept {
  ostrm_ << str_ << '\n' << std::flush;
  return cnt_;
}

} /* io:: */
} /* bulkmt:: */
