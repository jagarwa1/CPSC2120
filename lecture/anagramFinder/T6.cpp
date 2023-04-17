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
    anagrams=anagram("olop", wordlist);

    //ASSERT_EQ(anagrams.size(),3);
    if (anagrams.size() != 3)
    {
        std::cout << "expected/correct value for anagrams.size() is 3, actual value when testing " << anagrams.size() << ".\n";
        return 1;
    }

    std::cout << "Passed" << endl;
}