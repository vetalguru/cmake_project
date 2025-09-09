#include <iostream>

#include "include/sample_header.hpp"

int main(int /*argc*/, char* /*argv*/[]) {
    int result = do_something();
    std::cout << "Result from do_something(): " << result << std::endl;
    return 0;
}
