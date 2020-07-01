/**
 * @file bulkmt.cpp
 * @brief Main file in this project.
 *
 * @author Maxim <john.jasper.doe@gmail.com>
 * @date 2020
 */

/* See the license in the file "LICENSE.txt" in the root directory. */

#include <iostream>
#include "version.hpp"

/** @brief Main entry point */
int main(int argc, char* argv[]) {
  std::cout << "BULKMT v." << BULKMT_MAJOR << "." << BULKMT_MINOR << "." << BULKMT_PATCH << "\n";
  std::cout << "  Make by Maxim <john.jasper.doe@gmail.com>" << std::endl;

  (void)argc;
  (void)argv;
}
