//
// Created by andrei on 4/21/23.
//

#include "WordCounter.h"
#include <iostream>
#include <fstream>
#include <algorithm>


WordCounter::WordCounter(std::string filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {

            size_t pos = 0;
            std::string delimiter = " ,.?!";
            while ((pos = line.find_first_of(delimiter)) != std::string::npos) {
                std::string word = line.substr(0, pos);

                word = cleanWord(word);
                std::transform(word.begin(), word.end(), word.begin(), ::tolower);

                if (word.length() > 0) {
                    wordMap[word]++;
                }
                line.erase(0, pos + 1);
            }

            std::string word = cleanWord(line);
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (word.length() > 0) {
                wordMap[word]++;
            }
        }
        inFile.close();
    } else {
        std::cout << "Unable to open file. Error code: " << errno << std::endl;
    }

    for (const auto &entry : wordMap) {
        wordVec.push_back(std::make_pair(entry.second, entry.first));
    }

    std::sort(wordVec.begin(), wordVec.end(), [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
        if (a.first != b.first) {
            return a.first > b.first;
        } else {
            return a.second < b.second;
        }
    });
}


void WordCounter::printSortedWords() {
    for (const auto &entry : wordVec) {
        std::cout << entry.second << " => " << entry.first << std::endl;
    }
}


std::string WordCounter::cleanWord(std::string word) {
    int startIndex = 0;
    while (startIndex < word.length() && !isalpha(word[startIndex])) {
        startIndex++;
    }
    int endIndex = word.length() - 1;
    while (endIndex >= 0 && !isalpha(word[endIndex])) {
        endIndex--;
    }
    return word.substr(startIndex, endIndex - startIndex + 1);
}