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

  for (int i=0; i<anagrams.size(); ++i)
  {
    if(anagrams[i]=="loop" ||
      anagrams[i]=="polo" ||
      anagrams[i]=="pool")
    {
      count++;
    }
  }

  //ASSERT_EQ(count,3);
  if (count != 3)
  {
    std::cout << "expected/correct value for count is 3, actual value when testing " << count << ".\n";
    return 1;
  }

  std::cout << "Passed" << endl;
}