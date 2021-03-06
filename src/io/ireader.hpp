/**
 * @file ireader.hpp
 * @brief Discription of the interface class "IReader".
 *
 * @author Maxim <john.jasper.doe@gmail.com>
 * @date 2020
 */

#ifndef IREADER_HPP_
#define IREADER_HPP_

#include <string>
#include "utils/subject.hpp"

/** @brief The namespace of the BULKMT project */
namespace bulkmt {
/** @brief The namespace of the IO */
namespace io {

class ireader : public utils::subject<std::string> {
public:
  virtual void read_cycle() = 0;
};

} /* io:: */
} /* bulkmt:: */

#endif /* IREADER_HPP_ */
