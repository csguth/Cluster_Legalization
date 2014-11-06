#ifndef UTIL_H
#define UTIL_H

#include <stdexcept>
#include <exception>

#define EXCEPT_THROW(func, exception) { \
    bool threw = false; \
    try { \
        (func); \
    } catch(exception & e){ \
        threw = true; \
    } \
    if(!threw) QFAIL("Não foi lançada a exceção:("); \
    };


#define EXCEPT_NOT_THROW(func, exception) { \
    try { \
        (func); \
    } catch(exception & e){ \
        QFAIL(e.what()); \
    } \
    };
#endif // UTIL_H
