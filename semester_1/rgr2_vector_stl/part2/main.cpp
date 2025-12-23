#include "train.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

int main() {
    using namespace time_utility;

    std::vector<Train> trains;

    std::ifstream fin("trains.txt");
    if (!fin) {
        std::cerr << "Can't open trains.txt\n";
        return 1;
    }

    size_t id, type_int, dh, dm, th, tm;
    std::string dest;
    while (fin >> id >> type_int >> dest >> dh >> dm >> th >> tm) {
        trains.emplace_back(id, static_cast<TrainType>(type_int), dest, SetTime(dh, dm), SetTime(th, tm));
    }

    std::sort(trains.begin(), trains.end(), [](const Train& a, const Train& b) {
        return a.GetDispatchTime() < b.GetDispatchTime();
    });

    std::cout << "All trains sorted by dispatch time:\n";
    for (const auto& t : trains) t.Print();

    size_t start_h, start_m, end_h, end_m;
    std::cout << "\nEnter start time (HH MM): ";
    std::cin >> start_h >> start_m;
    std::cout << "Enter end time (HH MM): ";
    std::cin >> end_h >> end_m;

    std::time_t start = SetTime(start_h, start_m);
    std::time_t end = SetTime(end_h, end_m);

    std::cout << "\nTrains at this interval:\n";
    for (const auto& t : trains) {
        if (t.GetDispatchTime() >= start && t.GetDispatchTime() <= end) t.Print();
    }

    std::string query_dest;
    std::cout << "\nEnter destination: ";
    std::cin >> query_dest;

    std::cout << "\nTrains to " << query_dest << ":\n";
    for (const auto& t : trains) {
        if (t.GetDestination() == query_dest) t.Print();
    }

    int type_input;
    std::cout << "\nEnter train type (0 - Passenger, 1 - Freight, 2 - High-speed, 3 - Subway, 4 - Specialized): ";
    std::cin >> type_input;
    TrainType query_type = static_cast<TrainType>(type_input);

    std::cout << '\n' << type_input << "trains to " << query_dest << ":\n";
    for (const auto& t : trains) {
        if (t.GetDestination() == query_dest && t.GetType() == query_type) t.Print();
    }

    auto it = std::min_element(trains.begin(), trains.end(), [&](const Train& a, const Train& b){
        if (a.GetDestination() != query_dest) return false;
        if (b.GetDestination() != query_dest) return true;
        return a.GetTravellingTime() < b.GetTravellingTime();
    });
    if (it != trains.end() && it->GetDestination() == query_dest) {
        std::cout << "\nFastest train to " << query_dest << ":\n";
        it->Print();
    } else {
        std::cout << "\nNo trains to " << query_dest << "\n";
    }

    return 0;
}
