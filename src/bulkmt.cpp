/**
 * @file bulkmt.cpp
 * @brief Main file in this project.
 *
 * @author Maxim <john.jasper.doe@gmail.com>
 * @date 2020
 */

/* See the license in the file "LICENSE.txt" in the root directory. */

#include <iostream>
#include "core/controller.hpp"
#include "io/reader.hpp"
#include "version.hpp"

/** @brief Main entry point */
int main(int argc, char* argv[]) {
  std::cout << "BULKMT v." << BULKMT_MAJOR << "." << BULKMT_MINOR << "." << BULKMT_PATCH << "\n";
  std::cout << "  Make by Maxim <john.jasper.doe@gmail.com>" << std::endl;

  if (argc - 1 != 1) {
    std::cerr << "\n[ERROR]: Invalid argument" << std::endl;
    std::cout << "\nUsing: \n  bulkmt <commands per block>" << std::endl;
    return EXIT_FAILURE;
  }

  std::istream& input = std::cin;
  std::ostream& ostrm_stat = std::cout;
  std::ostream& ostrm_log = std::cout;

  std::unique_ptr<bulkmt::io::ireader> rd = std::make_unique<bulkmt::io::reader>(input);
  std::shared_ptr<bulkmt::core::controller> controller = std::make_shared<bulkmt::core::controller>(
      std::stoul(argv[1]), std::move(rd), ostrm_stat, ostrm_log);

  controller->start();

  return EXIT_SUCCESS;
}
