#pragma once

#include "targetver.h"
#include <assert.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <memory>
#include <cmath>
#include <cstdint>
#include <streambuf>

#include "logging.hpp"

namespace ace {
    class membuf : public std::streambuf
    {
    public:
        membuf(char* mem, size_t length) {
            
            setg(mem, mem, mem + length);
            setp(mem, mem + length);
        }

        std::streampos seekpos(std::streampos pos, std::ios_base::openmode) {
            char *p = eback() + pos;
            if (p >= eback() && p <= egptr())
            {
                setg(eback(), p, egptr());
                return pos;
            }
            else
                return -1;
        }

        std::streampos seekoff(std::streamoff off, std::ios_base::seekdir dir, std::ios_base::openmode) {
            char *p;
            switch (dir)
            {
            case std::ios_base::beg:
                p = eback() + off;
                break;
            case std::ios_base::cur:
                p = gptr() + off;
                break;
            case std::ios_base::end:
                p = egptr() - off;
                break;
            default:
                p = 0;
                break;
            }
            if (p >= eback() && p <= egptr())
            {
                setg(eback(), p, egptr());
                return std::streampos(p - eback());
            }
            else
                return -1;
        }
    };

    template< typename T >
    struct array_deleter
    {
        void operator ()(T const * p)
        {
            delete[] p;
        }
    };

    std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
    std::vector<std::string> split(const std::string &s, char delim);
}