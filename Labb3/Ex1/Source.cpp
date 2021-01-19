#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <iomanip>      

using Word_Freq = std::pair<std::string, int>;

//struct compare_letters {
//	bool operator()(char a, char b) {
//		a = static_cast<char>(tolower(a));
//		b = static_cast<char>(tolower(b));
//
//		return (a < b);
//	}
//};

bool notValid(char c) {
	if (!isalnum(c) && c != '\'') {
		return true;
	}
	return false;
}

std::string sweep(std::string word) {

	std::transform(begin(word), end(word), begin(word), ::tolower);

	word.erase(std::remove_if(word.begin(), word.end(), notValid), word.end());

	return word;
}

struct Counter
{
	std::map<std::string, int> wordCount;
	void operator()(const std::string & item) {
		++wordCount[item];
	}
	operator std::map<std::string, int>() {
		return wordCount;
	}
};


bool sortByVal(const Word_Freq&l, const Word_Freq &r)
{
	//return (a.second > b.second);	

	if (l.second != r.second) {
		return l.second > r.second;
	}
	else {
		return l.first < r.first;
	}
};

struct Printout {
	void operator()(const Word_Freq &w) {
		std::cout << std::left << std::setw(20) << w.first << w.second << std::endl;
	}
};

//typedef std::pair<std::string, int> pair;

int main() {

	std::ifstream myFile("C:\\Users\\adaga376\\Labb3\\Ex1\\Code3\\uppgift1\\uppgift1.txt");

	if (!myFile) {
		std::cout << "couldnt open" << std::endl;
	}

	//std::map<std::string, int> frequency_table;

	//auto inIt = std::istream_iterator<std::string>{ myFile };
	//auto inItend = std::istream_iterator<std::string>{};

	//std::vector<std::string> words{ std::istream_iterator<std::string>{ myFile }, std::istream_iterator<std::string>{} };
	std::vector<std::string> words{};

	std::copy(std::istream_iterator<std::string>{ myFile }, std::istream_iterator<std::string>{}, std::back_inserter(words));

	//std::vector<std::string> words{ inIt, inItend };

	std::sort(std::begin(words), end(words));

	std::transform(begin(words), end(words), begin(words), sweep);

	std::map<std::string, int> frequency_table = std::for_each(std::begin(words), std::end(words), Counter());

	std::cout << "Numbers of words in the file = " << words.size() << std::endl;

	std::cout << "Numbers of unique words in the file = " << frequency_table.size() << std::endl << std::endl;

	std::cout << "*************************************" << std::endl << std::endl;

	std::cout << "Frequency table sorted alphabetically... " << std::endl << std::endl;

	std::for_each(begin(frequency_table), end(frequency_table), Printout());

	/*for (const auto&[word, number] : frequency_table) {
		std::cout << std::left << std::setw(20) << word << number << std::endl;
	}*/

	std::cout << std::endl << std::endl << "Frequency table sorted by frequence ..." << std::endl << std::endl;

	std::vector<std::pair<std::string, int>> vec;

	std::copy(begin(frequency_table), end(frequency_table), back_inserter(vec));

	std::sort(begin(vec), end(vec), sortByVal);

	std::for_each(begin(vec), end(vec), Printout());

	//for (auto const &pair : vec) {
	//		std::cout << std::left << std::setw(20) << pair.first << pair.second << std::endl;
	//}
}

