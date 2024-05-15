//
// Created by andrei on 4/21/23.
//

#ifndef OOP8_WORDCOUNTER_H
#define OOP8_WORDCOUNTER_H

#include <string>
#include <vector>
#include <map>

class WordCounter {
private:
    std::map<std::string, int> wordMap;
    std::vector<std::pair<int, std::string>> wordVec;

    std::string cleanWord(std::string word);
public:

    WordCounter(std::string filename);

    void printSortedWords();
};

#endif //OOP8_WORDCOUNTER_H
