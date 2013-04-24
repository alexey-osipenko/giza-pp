#include "compat.h"
#include <string.h>

#ifdef WIN32

int strcasecmp(const char* s1, const char* s2) {
    return stricmp(s1, s2);
}

#endif // WIN32
