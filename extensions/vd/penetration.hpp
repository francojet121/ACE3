#pragma once

#include "shared.hpp"
#include "vector.hpp"
#include "game.hpp"
#include "vehicle.hpp"

namespace ace {
    namespace vehicledamage {
        namespace penetration {
            class penetration_result {
            public:
                bool            placeholder_1;
                float            linear_depth;
            };

            class base_penetration_model {
            public:
                base_penetration_model(const gamehit_p hit_, vehicle_p &vehicle_) : _hit(hit_), _vehicle(vehicle_) {
                    process();
                }
                virtual bool                        process() { return false; }
                virtual const penetration_result  & result() { return _result; }
                
                virtual bool                complete() { return _complete;  }
            protected:
                gamehit_p                    _hit;
                vehicle_p                _vehicle;
                penetration_result        _result;

                volatile bool            _complete;
            };
        }
    }
}