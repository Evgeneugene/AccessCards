#ifndef HWACCESS_LEVEL_H
#define HWACCESS_LEVEL_H
#include <string>
#define toString( name ) # name
enum Level {NoLevel = 0, Blue, Green, Yellow, Red};
using namespace std;
const char* levelNames[] =
        {
                toString( NoLevel ),
                toString( Blue ),
                toString( Green ),
                toString( Yellow ),
                toString( Red )
        };           //This is for printing enumerations as strings;
string printLevel( Level l )
{
    return levelNames[ l ];
}


#endif //HWACCESS_LEVEL_H
