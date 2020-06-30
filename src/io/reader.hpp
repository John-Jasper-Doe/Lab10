/**
 * @file reader.hpp
 * @brief Discription of the class "Reader".
 *
 * @details
 * Description of the class "Reader", which in the "Observer" pattern
 * implements the "Subject". The class "Reader" is inherited from the template
 * "Subject" and performs the function of receiving data from the input stream
 * and notifies all observers who are subscribed to it.
 *
 * @author Maxim <john.jasper.doe@gmail.com>
 * @date 2020
 */

#ifndef READER_HPP_
#define READER_HPP_

#include "ireader.hpp"

/** @brief The namespace of the BULKMT project */
namespace bulkmt {
/** @brief The namespace of the IO */
namespace io {

/** @brief The reader class */
class reader final : public io::ireader {
  std::istream& istrm_;  /**< - the input stream. */

public:
  /**
   * @brief The constructor with parameters.
   * @param [in] istrm - the input stream.
   */
  explicit reader(std::istream& istrm) noexcept;

  /** @brief Loop to read data from the input stream. */
  void read_cycle();
};

} /* io:: */
} /* bulkmt:: */

#endif /* READER_HPP_ */