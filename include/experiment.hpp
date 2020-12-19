// Copyright 2020 Daniil Rybakov <pochtaworld7@gmail.com>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <random>
#include <vector>
using namespace std::chrono;
#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#endif  // INCLUDE_HEADER_HPP_
const size_t oneKByte = 1024;
const size_t cacheSize1 = 192, cacheSize2 = 1024, cacheSize3 = 4096;
class experiment {
 public:
  std::vector<size_t> vectorCacheSize = {
      cacheSize1 * oneKByte, cacheSize2* oneKByte, cacheSize3* oneKByte};
  std::vector<size_t> CountOfExperiments = {};
  size_t getCounter();
  experiment();
  std::vector<double> DirectExperiment();
  std::vector<double> ReverseExperiment();
  std::vector<double> RandomExperiment();
  int k = 0;
  friend std::ostream& operator<<(std::ostream& os, experiment& exp);
};
