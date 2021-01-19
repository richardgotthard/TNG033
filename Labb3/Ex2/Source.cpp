#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <iomanip>  
#include <set> 

using Table = std::map<std::string, std::set<std::string>>;

struct Counter
{
	Counter(Table &t) : howmany(t) {
	}
	void operator()(const std::string& item)
	{
		std::string key{ item };
		std::sort(key.begin(), key.end());
		howmany[key].insert(item);
	}
public:
	Table &howmany;
};

struct Print_Entry {
	void operator()(const std::string &entry) {
		std::cout << std::left << entry << " ";
	}
};
struct PrintEntry {
	void operator()(const std::pair<const std::string, const std::set<std::string>>&entry) {
		if (entry.second.size() >= 2) {
			std::for_each(entry.second.begin(), entry.second.end(), Print_Entry());
			std::cout << "-> " << entry.second.size() << "\n";
		}
	}
};

int main() {

	std::ifstream myFile("C:\\Users\\adaga376\\Labb3\\Ex1\\Code3\\uppgift2\\uppgift2.txt");

	if (!myFile) {
		std::cout << "couldnt open" << std::endl;
	}

	std::set<std::string> words{};

	std::copy(std::istream_iterator<std::string>{myFile}, std::istream_iterator<std::string>{}, inserter(words, words.end()));

	std::cout << "Numbers of words = " << words.size() << std::endl;

	std::cout << "-- ANAGRAMS -- " << std::endl << std::endl;

	std::cout << "*************************************" << std::endl << std::endl;

	//std::sort(std::begin(words), std::end(words));

	//std::unique_copy(std::begin(words), std::end(words), std::begin(words));

	Table frequentlist;

	Counter anagram_counter(frequentlist);

	std::for_each(std::begin(words), std::end(words), anagram_counter);

	std::cout << "Number anagrams " << frequentlist.size() << "\n";

	std::for_each(frequentlist.begin(), frequentlist.end(), PrintEntry());

	return 0;

}