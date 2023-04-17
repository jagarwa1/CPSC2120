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

  for (int i=0; i<anagrams.size(); ++i)
  {
    if(anagrams[i]=="capers" ||
      anagrams[i]=="crapes" ||
      anagrams[i]=="escarp" ||
      anagrams[i]=="pacers" ||
      anagrams[i]=="parsec" ||
      anagrams[i]=="recaps" ||
      anagrams[i]=="scrape" ||
      anagrams[i]=="secpar" ||
      anagrams[i]=="spacer")
    {
      count++;
    }
  }

  //ASSERT_EQ(count,9);
  if (count != 9)
  {
    std::cout << "expected/correct value for count is 9, actual value when testing " << count << ".\n";
    return 1;
  }

  std::cout << "Passed" << endl;
}