#pragma once

#include "vehicle.hpp"

using namespace ace::simulation;

namespace ace {
    namespace vehicledamage {
        vehicle::vehicle(ace::simulation::object_p object_) : object(object_) {}

        std::vector<ace::vector3<float>> vehicle::selection_position(const uint32_t lod, const std::string &name, const SELECTION_SEARCH_TYPE searchType) {
            named_selection_p selection;
            std::vector<ace::vector3<float>> result;

            if ((selection = selection_by_name(lod, name)) == nullptr)
                return result;

            switch (searchType) {
                case SELECTION_SEARCH_TYPE::AVERAGE_CENTER: {
                    ace::vector3<float> average;
                    std::vector<ace::vector3<float>> results;

                    for (auto & a : selection->vertices) {
                        for (auto & b : selection->vertices) {
                            if (a != b) {
                                average = average + ace::vector3<float>::lerp(static_cast<ace::vector3<float>>(*a), static_cast<ace::vector3<float>>(*b), 0.5f);
                            }
                        }
                    }

                    average = average / results.size();
                    result.push_back(average);

                    break;
                }  
            }
            

            return result;
        }

        ace::simulation::named_selection_p vehicle::selection_by_name(const uint32_t lod, const std::string &name) {
            named_selection_p result;
            
            std::map<std::string, named_selection_p>::iterator iter = object->lods[lod]->selections.find(name);
            if (iter == object->lods[lod]->selections.end()) {
                return nullptr;
            }
            result = iter->second;

            return result;
        }
    }
};