//
//  queues.cpp
//  CF.STL_Containers_Queue
//
//  Created by Alan Sampson on 4/10/21.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <string_view>
#include <algorithm>
#include <numeric>
#include <compare>
#include <memory>
#include <type_traits>
#include <queue>
#include <deque>
#include <array>
#include <map>
#include <vector>
#include <stdexcept>
#include <cassert>
#include <cstddef>

using namespace std::literals::string_literals;
using namespace std::literals::string_view_literals;

//  MARK: - Definitions

//  MARK: - Local Constants.
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
//  MARK: namespace konst
namespace konst {

auto delimiter(char const dc = '-', size_t sl = 80) -> std::string const {
  auto const dlm = std::string(sl, dc);
  return dlm;
}

static
auto const dlm = delimiter();

static
auto const dot = delimiter('.');

} /* namespace konst */

#if (__cplusplus > 201707L)
#endif  /* (__cplusplus > 201707L) */

//  MARK: - Function Prototype.
auto C_queue(int argc, char const * argv[]) -> decltype(argc);
auto C_queue_deduction_guides(int argc, char const * argv[]) -> decltype(argc);

//  MARK: - Implementation.
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
/*
 *  MARK: main()
 */
int main(int argc, char const * argv[]) {
  std::cout << "CF.STL_Containers_Queue\n"sv;
  std::cout << "C++ Version: "s << __cplusplus << std::endl;

  std::cout << '\n' << konst::dlm << std::endl;
  C_queue(argc, argv);
  std::cout << '\n' << konst::dlm << std::endl;
  C_queue_deduction_guides(argc, argv);

  return 0;
}

//  MARK: - C_queue
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
//  ================================================================================
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
/*
 *  MARK: C_queue()
 */
auto C_queue(int argc, char const * argv[]) -> decltype(argc) {
  std::cout << "In "s << __func__ << std::endl;

  /// Member functions
  // ....+....!....+....!....+....!....+....!....+....!....+....!
  std::cout << konst::dot << '\n';
  std::cout << "std::queue - constructor"s << '\n';
  {
    std::queue<int> c1;
    c1.push(5);
    std::cout << c1.size() << '\n';

    std::queue<int> c2(c1);
    std::cout << c2.size() << '\n';

    std::deque<int> deq { 3, 1, 4, 1, 5, };
    std::queue<int> c3(deq);
    std::cout << c3.size() << '\n';

    std::cout << '\n';
  };

  /// Element access
  // ....+....!....+....!....+....!....+....!....+....!....+....!
  std::cout << konst::dot << '\n';
  std::cout << "std::queue - first, last"s << '\n';
  {
    auto prime = std::deque { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', };
    auto que = std::queue(prime);
    auto trigger { 0ul };
    while (!que.empty()) {
      auto qval = (trigger++ % 2 == 0) ? que.front() : que.back();
      std::cout << qval << ' ';
      que.pop();
    }
    std::cout << '\n';

    std::cout << '\n';
  };

  /// Capacity
  // ....+....!....+....!....+....!....+....!....+....!....+....!
  std::cout << konst::dot << '\n';
  std::cout << "std::queue - empty"s << '\n';
  {
    std::cout << std::boolalpha;

    std::queue<int> container;

    std::cout << "Initially, container.empty(): "s
              << container.empty() << '\n';

    container.push(42);
    std::cout << "After adding elements, container.empty(): "s
              << container.empty() << '\n';
    container.pop();

    std::cout << "Initially, container.size(): "s
              << container.size() << '\n';

    for (int i_ = 0; i_ < 7; ++i_) {
      container.push(i_);
    }

    std::cout << "After adding elements, container.size(): "s
              << container.size() << '\n';

    std::cout << std::noboolalpha;

    std::cout << '\n';
  };

  /// Modifiers
  // ....+....!....+....!....+....!....+....!....+....!....+....!
  std::cout << konst::dot << '\n';
  std::cout << "std::queue - swap"s << '\n';
  {
    std::queue<int> qi1;
    std::queue<int> qi2;

    auto show = [](auto collection) {
      while (!collection.empty()) {
        auto nr = collection.front();
        collection.pop();
        std::cout << std::setw(2) << nr;
      }
    };

    for (auto x_ : { 0, 1, 2, }) {
      qi1.push(x_);
    }
    show(qi1);
    std::cout << '\n';

    for (auto x_ : { 3, 4, 5, 6, }) {
      qi2.push(x_);
    }
    show(qi2);
    std::cout << '\n';

    std::cout << "qi1 size="sv << qi1.size() << '\n'
              << "qi2 size="sv << qi2.size() << '\n';

    qi1.swap(qi2);

    show(qi1);
    std::cout << '\n';
    show(qi2);
    std::cout << '\n';

    std::cout << "qi1 size="sv << qi1.size() << '\n'
              << "qi2 size="sv << qi2.size() << '\n';

    std::cout << '\n';
  };

  std::cout << std::endl; //  make sure cout is flushed.

  return 0;
}

//  MARK: - C_queue_deduction_guides
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
//  ================================================================================
//  ....+....!....+....!....+....!....+....!....+....!....+....!....+....!....+....!
/*
 *  MARK: C_queue_deduction_guides()
 */
auto C_queue_deduction_guides(int argc, char const * argv[]) -> decltype(argc) {
  std::cout << "In "s << __func__ << std::endl;

  // ....+....!....+....!....+....!....+....!....+....!....+....!
  std::cout << konst::dot << '\n';
  std::cout << "std::queue = deduction guides"s << '\n';
  {

    std::cout << '\n';
  };

std::cout << std::endl; //  make sure cout is flushed.
  return 0;
}
