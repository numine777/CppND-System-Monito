#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "linux_parser.h"
#include <vector>
#include <string>
#include <numeric>
#include <unistd.h>

using std::string;
using std::vector;

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp
  void GetCPUTimes();

  // TODO: Declare any necessary private members
 private:
   long idle_time{0};
   long total_time{0};
   long previous_idle_time{0};
   long previous_total_time{0};
};

#endif