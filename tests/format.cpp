#include <gpch.h>
#include <gtest/gtest.h>

TEST(CmakeTools, Format) {
  EXPECT_NO_THROW(format("Integer: {}", 42));
  EXPECT_NO_THROW(fmt("Integer: {}", 42));
  EXPECT_NO_THROW(format("String: {}", "data"));
  EXPECT_NO_THROW(fmt("String: {}", "data"));
  EXPECT_NO_THROW(format("None"));
  EXPECT_NO_THROW(fmt("None"));
}
