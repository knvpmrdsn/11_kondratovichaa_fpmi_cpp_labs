#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include "time_utility.h"

using TrainId = size_t;
using namespace time_utility;

enum class TrainType { PASSENGER, FREIGHT, HIGH_SPEED, SUBWAY, SPECIALIZED };

class Train {
private:
    TrainId id_;
    TrainType type_;
    std::string destination_;
    std::time_t dispatch_time_;
    std::time_t travelling_time_;

    std::string TypeToString() const {
        switch (type_) {
            case TrainType::PASSENGER:
                return "Passenger";
            case TrainType::FREIGHT:
                return "Freight";
            case TrainType::HIGH_SPEED:
                return "High-speed";
            case TrainType::SUBWAY:
                return "Subway";
            case TrainType::SPECIALIZED:
                return "Specialized";
            default:
                return "Unknown";
        }
    }

    std::string TimeToString(const std::time_t& t) const {
        std::tm* tm_ptr = std::localtime(&t);
        int hours = tm_ptr->tm_hour;
        int minutes = tm_ptr->tm_min;

        std::string s;
        if (hours < 10)
            s += '0';
        s += std::to_string(hours);
        s += ':';
        if (minutes < 10)
            s += '0';
        s += std::to_string(minutes);
        return s;
    }

public:
    Train() = default;
    Train(TrainId id, TrainType type, const std::string& dest, std::time_t dispatch,
          std::time_t travel)
        : id_(id),
          type_(type),
          destination_(dest),
          dispatch_time_(dispatch),
          travelling_time_(travel) {
    }

    TrainId GetId() const {
        return id_;
    }
    TrainType GetType() const {
        return type_;
    }
    std::string GetDestination() const {
        return destination_;
    }
    std::time_t GetDispatchTime() const {
        return dispatch_time_;
    }
    std::time_t GetTravellingTime() const {
        return travelling_time_;
    }

    void Print() const {
        std::cout << "Train " << id_ << ": " << TypeToString() << " to " << destination_
                  << ", departs at " << TimeToString(dispatch_time_) << ", travelling time "
                  << TimeToString(travelling_time_) << '\n';
    }
};
