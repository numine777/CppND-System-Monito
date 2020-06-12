#include "processor.h"

// TODO: Return the aggregate CPU utilization
void Processor::GetCPUTimes() {
    vector<string> CPUTotals = LinuxParser::CpuUtilization();
    vector<long> NewTotals = {};
    for (string value : CPUTotals) {
        long nvalue = std::stol(value);
        NewTotals.push_back(nvalue);
    }
    idle_time = NewTotals[3];
    total_time = std::accumulate(NewTotals.begin(), NewTotals.end(), 0);
}

float Processor::Utilization() {
    GetCPUTimes();
    float idle_time_delta = idle_time - previous_idle_time;
    float total_time_delta = total_time - previous_total_time;
    previous_idle_time = idle_time;
    previous_total_time = total_time;
    float utilization = (total_time_delta - idle_time_delta) / total_time_delta;
    return utilization;
}