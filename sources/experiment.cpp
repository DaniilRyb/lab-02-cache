// Copyright 2020 Daniil Rybakov <pochatworld7@gmail.com>
#include <experiment.hpp>
const double half = 0.5;
const int one = 1;
const double oneAndHalf = 1.5;
const size_t powTwo = 2;
const int sixteen = 16;
const int a = 4;
const size_t thousand = 1000;
experiment::experiment() {
  for (size_t counts = half * vectorCacheSize[0];
       counts <= oneAndHalf * vectorCacheSize[2]; counts *= powTwo) {
    CountOfExperiments.push_back(counts);
  }
}
std::vector<double> experiment::DirectExperiment() {
  std::vector<double> vectorDuration;
  for (const auto& i : CountOfExperiments) {
    int* arr = new int[static_cast<int>(i / a)];
    for (size_t j = 0; j < i / a; j += sixteen) {
      k = arr[j];
    }
    std::chrono::system_clock::time_point start =
        std::chrono::system_clock::now();
    for (size_t it = 0; it < thousand; ++it) {
      for (size_t j = 0; j < i / a; j += sixteen) {
        k = arr[j];
      }
    }
    std::chrono::system_clock::time_point end =
        std::chrono::system_clock::now();
    std::chrono::duration<double> duration = end - start;
    vectorDuration.push_back(duration.count());
    delete[] arr;
  }
  return vectorDuration;
}
std::vector<double> experiment::ReverseExperiment() {
  std::vector<double> vectorDuration;
  for (const auto& i : CountOfExperiments) {
    int* arr = new int[static_cast<int>(i / a)];
    for (size_t j = 0; j < i / a; j -= sixteen) {
      k = arr[j];
    }
    std::chrono::system_clock::time_point start =
        std::chrono::system_clock::now();
    for (size_t it = 0; it < thousand; ++it) {
      for (size_t j = 0; j < i / a; j -= sixteen) {
        k = arr[j];
      }
    }
    std::chrono::system_clock::time_point end =
        std::chrono::system_clock::now();
    std::chrono::duration<double> duration = end - start;
    vectorDuration.push_back(duration.count());
    delete[] arr;
  }
  return vectorDuration;
}
std::vector<double> experiment::RandomExperiment() {
  std::vector<double> vectorDuration;
  std::vector<size_t> randomVectorOfIndex;
  for (const auto& i : CountOfExperiments) {
    int* arr = new int[static_cast<int>(i / a)];
    for (size_t j = 0; j < i / a; j += sixteen) {
      k = arr[j];
      randomVectorOfIndex.push_back(j);
    }
    // std::random_device rd;
    std::mt19937 generator(time(NULL));
    std::shuffle(randomVectorOfIndex.begin(), randomVectorOfIndex.end(),
                 generator);
    std::chrono::system_clock::time_point start =
        std::chrono::system_clock::now();
    for (size_t count = 0; count < thousand; ++count) {
      for (const auto& index : randomVectorOfIndex) {
        k = arr[index];
      }
    }
    std::chrono::system_clock::time_point end =
        std::chrono::system_clock::now();
    std::chrono::duration<double> duration = end - start;
    vectorDuration.push_back(duration.count());
    delete[] arr;
  }
  return vectorDuration;
}
size_t experiment::getCounter() { return CountOfExperiments.size(); }
std::ostream& operator<<(std::ostream& os, experiment& exp) {
  std::vector<std::string> Experiments = {"Direction", "Reverse", "Random"};
  os << " investigation" << std::endl;
  os << "  travel_order " << Experiments[0] << std::endl;
  os << " experiments" << std::endl;
  os << " -experiment:" << std::endl;
  for (size_t j = 0; j < exp.getCounter(); ++j) {
    os << "   number " << j + one << std::endl;
    os << "   input_data:" << std::endl;
    os << "     buffer_size: " << exp.CountOfExperiments[j] / oneKByte << " kb"
       << std::endl;
    os << "   results:" << std::endl;
    os << "     direction: " << exp.DirectExperiment()[j] * thousand << " ms"
       << std::endl;
  }
  os << std::endl << std::endl;
  os << " investigation" << std::endl;
  os << "  travel_order " << Experiments[1] << std::endl;
  os << " experiments" << std::endl;
  os << " -experiment:" << std::endl;
  for (size_t j = 0; j < exp.getCounter(); ++j) {
    os << "   number " << j + one << std::endl;
    os << "   input_data:" << std::endl;
    os << "     buffer_size: " << exp.CountOfExperiments[j] / oneKByte << " kb"
       << std::endl;
    os << "   results:" << std::endl;
    os << "     direction: " << exp.ReverseExperiment()[j] * thousand << " ms"
       << std::endl;
  }
  os << std::endl << std::endl;
  os << " investigation" << std::endl;
  os << "  travel_order " << Experiments[2] << std::endl;
  os << " experiments" << std::endl;
  os << " -experiment:" << std::endl;
  for (size_t j = 0; j < exp.getCounter(); ++j) {
    os << "   number " << j + one << std::endl;
    os << "   input_data:" << std::endl;
    os << "     buffer_size: " << exp.CountOfExperiments[j] / oneKByte << " kb"
       << std::endl;
    os << "   results:" << std::endl;
    os << "     direction: " << exp.RandomExperiment()[j] * thousand << " ms"
       << std::endl;
  }
  return os;
}
