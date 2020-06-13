#include <string>
#include <sstream>
#include <iomanip>

#include "format.h"
using std::ostringstream;
using std::string;
using std::to_string;

using std::string;

string Format::ElapsedTime(long seconds) { 
    ostringstream time;
    time << std::setw( 2 ) << std::setfill( '0' ) << to_string((seconds / 60 / 60)) << ":" << std::setw( 2 ) << std::setfill( '0' ) << to_string((seconds / 60)% 60) <<":" << std::setw( 2 ) << std::setfill( '0' ) << to_string(seconds % 60);
    return time.str(); 
}
