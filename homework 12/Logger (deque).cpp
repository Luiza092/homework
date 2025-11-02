#include <iostream>
#include <deque>
#include <string>

class Logger {
private:
	std::deque<std::string> messages;
	size_t maxSize;

public:
	Logger(size_t N) : maxSize(N) {}

	void add(const std::string& m) {
		if(messages.size() == maxSize) {
			messages.pop_front();
		}
		messages.push_back(m);
	}

	void show() const {
		for(const auto& m : messages) {
			std::cout << m << std::endl;
		}
	}
};

int main()
{
	Logger log(3);
	log.add("start");
	log.add("init");
	log.add("run");
	log.add("stop");
	log.show();

	return 0;
}