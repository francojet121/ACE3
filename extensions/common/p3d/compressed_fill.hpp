#pragma once

#include "ace_common.h"
#include "vector.hpp"

#include "read_helpers.hpp"

namespace ace {
    namespace p3d {
        template<typename T>
        class compressed_fill {
        public:
            compressed_fill() : fill(false), size(0) { }
            compressed_fill(std::fstream &stream_, bool compressed_ = false, bool fill_ = false) : fill(false), size(0) {
                stream_.read((char *)&size, sizeof(uint32_t));
                
                if(fill_)
                    READ_BOOL(fill);

                assert(size < 4095 * 10);
                if (size > 0) {
                    if (fill) {
                        T val;
                        stream_.read((char *)&val, sizeof(T));
                        for (int x = 0; x < size; x++) {
                            data.push_back(val);
                        }
                    }  else {
                       
                        if (size > 1024 && compressed_) {
                            // DECOMPRESS IT FIRST
                            LOG(ERROR) << "CANT DECOMPRESS OMG:";
                            assert(true);
                        } else {
                            for (int x = 0; x < size; x++) {
                                T val;
                                stream_.read((char *)&val, sizeof(T));
                                data.push_back(val);
                            }
                        }
                    }
                }
            }

            uint32_t          size;
            bool              fill;
            std::vector<T>    data;
        };

        template<>
        class compressed_fill<vector3<float>> {
        public:
            compressed_fill() : fill(false), size(0) {}
            compressed_fill(std::fstream &stream_, bool compressed_ = false, bool fill_ = false) : fill(false), size(0) {
                stream_.read((char *)&size, sizeof(uint32_t));
                
                if(fill_)
                    READ_BOOL(fill);
                
                if (fill) {
                    ace::vector3<float> val(stream_);
                    for (int x = 0; x < size; x++) {
                        data.push_back(val);
                    }
                }
                else {
                    if (size > 1024 && compressed_) {
                        // DECOMPRESS IT FIRST
                    }
                    else {
                        for (int x = 0; x < size; x++) {
                            data.push_back(ace::vector3<float>(stream_));
                        }
                    }
                }
            }

            uint32_t          size;
            bool              fill;
            std::vector<ace::vector3<float>>    data;
        };
    }
}