#pragma once
// IWYU pragma: begin_keep
#include <algorithm>
#include <any>
#include <array>
#include <atomic>
#include <barrier>
#include <bit>
#include <chrono>
#include <cmath>
#include <complex>
#include <coroutine>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <exception>
#include <forward_list>
#include <fstream>
#include <functional>
#include <future>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <numeric>
#include <optional>
#include <queue>
#include <random>
#include <ranges>
#include <semaphore>
#include <set>
#include <shared_mutex>
#include <stack>
#include <string>
#include <string_view>
#include <thread>
#include <tuple>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <variant>
#include <vector>

// Root project version information autoinclude
#if __has_include(<version.h>)
#  include <version.h>
#endif

// std::format OR fmt::format
#if __has_include(<format>)
#  include <format>
#else
#  if __has_include(<fmt/format.h>)
#    include <fmt/core.h>
#    include <fmt/format.h>
#    include <fmt/ranges.h>
#  else
#    error No standard formatting headers found
#  endif
#endif
// IWYU pragma: end_keep

/**
 * Format a string using a given format string and arguments.
 *
 * If the `std::format` header is available, this function will use it.
 * Otherwise, it will use the fmt library.
 *
 * @param fmt_str The format string.
 * @param args The arguments to pass to the format function.
 *
 * @return The formatted string.
 */
template<typename... Args>
inline std::string format(const char fmt_str[], Args&&... args) {
  if constexpr (!sizeof...(Args)) {
    return fmt_str;
  }
#ifdef __cpp_lib_format
  return std::vformat(fmt_str, std::make_format_args(args...));
#else
#  if __has_include(<fmt/format.h>)
  return fmt::vformat(fmt_str, fmt::make_format_args(args...));
#  else
  static_assert(false && "No std::format or fmt::format available. Link to fmt library first.");
  return {};
#  endif
#endif
}

/*
template<typename... Args>
inline std::string fmt(const char fmt_str[], Args&&... args) {
  if constexpr (sizeof...(Args)) {
    format(fmt_str, std::forward<Args...>(args...));
  }
  return fmt_str;
}
*/