#include <iostream>
#include <vector>
#include <algorithm>

struct Event {
    int start;
    int end;
};

std::vector<Event> findEvents(const std::vector<Event>& events, int date) {
    std::vector<Event> result;
    for (const Event& event : events) {
        if (event.start <= date && date <= event.end) {
            result.push_back(event);
        }
    }
    return result;
}

int main() {
    std::vector<Event> events = { {1, 5}, {6, 10}, {11, 15} };
    int date = 7;

    std::vector<Event> result = findEvents(events, date);

    for (const Event& event : result) {
        std::cout << "Event starts at " << event.start << " and ends at " << event.end << std::endl;
    }

    return 0;
}