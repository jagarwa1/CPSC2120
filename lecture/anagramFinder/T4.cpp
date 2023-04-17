#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> loadWordlist(string filename);
vector<string> anagram(string word, vector<string> wordlist);

int main()
{
    vector<string> wordlist;
    vector<string> anagrams;
    int count = 0;

    wordlist=loadWordlist("wordlist.txt");
    anagrams=anagram("capers", wordlist);

    //ASSERT_EQ(anagrams.size(),9);
    if (anagrams.size() != 9)
    {
        std::cout << "expected/correct value for anagrams.size() is 9, actual value when testing " << anagrams.size() << ".\n";
        return 1;
    }

    std::cout << "Passed" << endl;
}