#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int p) {
    this->pid = p;
    this->cpu = CpuUtilization();
}

// TODO: Return this process's ID
int Process::Pid() { return pid; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() { 
    vector<long> data = LinuxParser::CpuUtilization(this->pid);
    float utime = (float)data[0];
    float stime = (float)data[1];
    float cutime = (float)data[2];
    float cstime = (float)data[3];
    starttime = (float)data[4];
    float total_time = utime + stime + cutime + cstime;
    float seconds = UpTime() - (starttime / (float) sysconf(_SC_CLK_TCK));

    return (total_time/(float)sysconf(_SC_CLK_TCK))/seconds; 
}

// TODO: Return the command that generated this process
string Process::Command() { return LinuxParser::Command(pid); }

// TODO: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(pid); }

// TODO: Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(pid); }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return starttime / sysconf(_SC_CLK_TCK); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const { return cpu > a.cpu; }