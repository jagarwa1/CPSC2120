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
  anagrams=anagram("steak", wordlist);

  for (int i=0; i<anagrams.size(); ++i)
  {
    if(anagrams[i]=="skate" ||
      anagrams[i]=="stake" ||
      anagrams[i]=="steak" ||
      anagrams[i]=="takes" ||
      anagrams[i]=="teaks")
    {
      count++;
    }
  }

  //ASSERT_EQ(count,5);
  if (count != 5)
  {
    std::cout << "expected/correct value for count is 5, actual value when testing " << count << ".\n";
    return 1;
  }

  std::cout << "Passed" << endl;
}