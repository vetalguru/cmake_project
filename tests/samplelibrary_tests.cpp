#include <gtest/gtest.h>
#include "include/sample_header.hpp"
#include <sstream>
#include <string>


TEST(DoSomethingTest, ReturnsCorrectValue) {
    EXPECT_EQ(do_something(), 42);
}

TEST(DoSomethingTest, DoesNotThrow) {
    EXPECT_NO_THROW({
        do_something();
    });
}

TEST(DoSomethingTest, PrintsCorrectMessage) {
    std::ostringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    int result = do_something();
    std::cout.rdbuf(old);

    EXPECT_EQ(result, 42);
    EXPECT_NE(buffer.str().find("Doing something!"), std::string::npos);
}
