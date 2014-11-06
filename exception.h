#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

namespace Overlap_Removal {

class Invalid_Range : public std::exception
{
public:
    const char * what() const throw()
    {
        return "Invalid Range";
    }
};

class Out_of_Bounds : public std::exception
{
public:
    const char * what() const throw()
    {
        return "Out of Bounds";
    }
};

class Already_Filled : public std::exception
{
public:
    const char * what() const throw()
    {
        return "Already Filled Place";
    }
};

class Range_Too_Big : public std::exception
{
public:
    const char * what() const throw()
    {
        return "Range Too Big";
    }
};

class Not_Enough_Space : public std::exception
{
public:
    const char * what() const throw()
    {
        return "Not Enough Space";
    }
};


}
#endif // EXCEPTION_H
