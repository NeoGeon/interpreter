#ifndef __REGREXENGINE_H_
#define __REGREXENGINE_H_
#include <string>
#include "stat.h"
class RegrexEngine{
public:
RegrexEngine();
~RegrexEngine(){};
bool match(string regrex, string str);
};

#endif
