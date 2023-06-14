#include <algorithm>
#include <iostream>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::vector;

string generate_uuid_v4() {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  static std::uniform_int_distribution<> dis(0, 15);
  static std::uniform_int_distribution<> dis2(8, 11);
  stringstream ss;
  int i;
  ss << std::hex;
  for (i = 0; i < 8; i++) {
    ss << dis(gen);
  }
  ss << "-";
  for (i = 0; i < 4; i++) {
    ss << dis(gen);
  }
  ss << "-4";
  for (i = 0; i < 3; i++) {
    ss << dis(gen);
  }
  ss << "-";
  ss << dis2(gen);
  for (i = 0; i < 3; i++) {
    ss << dis(gen);
  }
  ss << "-";
  for (i = 0; i < 12; i++) {
    ss << dis(gen);
  };
  return ss.str();
}

template <typename T>
class GameEvent {
 private:
  string action;
  T time;
  string id;

 public:
  GameEvent(string action, T time) : time(time), action(action) {
    id = generate_uuid_v4();
  }
  T getTime() { return time; }
  string getAction() { return action; }
  bool operator==(const GameEvent* event) { return event->id == this->id; }
};

template <typename T>
class GameTimeline {
 private:
  vector<GameEvent<T>*> events;

 public:
  GameTimeline(){};

  void addEvent(GameEvent<T>* event) { events.push_back(event); }

  void removeEvent(GameEvent<T>* event) {
    for (auto it = events.begin(); it != events.end();) {
      if (event == *it) {
        events.erase(it);
      } else {
        it++;
      }
    }
  }

  vector<GameEvent<T>> getEventsAtTime(T time) {
    vector<GameEvent<T>> eventsToReturn;
    for (GameEvent<T>* event : events) {
      cout << event << endl;
      if (event->getTime() == time) {
        eventsToReturn.push_back(*event);
      }
    }

    return eventsToReturn;
  }
};

int main() {
  GameTimeline<int> timeline;
  GameEvent<int> event1("some-action", 10);
  GameEvent<int> event2("othe-action", 10);
  GameEvent<int> event3("more-one-action", 20);

  timeline.addEvent(&event1);

  timeline.addEvent(&event2);
  timeline.addEvent(&event3);

  timeline.removeEvent(&event2);
  vector<GameEvent<int>> my10Events = timeline.getEventsAtTime(10);

  for (GameEvent<int> event : my10Events) {
    cout << event.getAction() << endl;
  }

  return 0;
}