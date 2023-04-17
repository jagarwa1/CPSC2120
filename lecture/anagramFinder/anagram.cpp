/*
 * Name:            Jai Agarwal
 * Date Submitted:  3/14/23
 * Assignment Name: Anagram Finder
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> loadWordlist(string filename);

/*Implement the following function:
  anagram() takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map where the key is a specific number of times each
  letter occurs in a word and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/
vector<string> anagram(string word, vector<string> wordlist);

// int main()
// {
//     vector<string> words;
//     vector<string> anagrams;
//     string inputWord;
//     words=loadWordlist("wordlist.txt");
//     cout << "Find single-word anagrams for the following word: ";
//     cin >> inputWord;
//     anagrams = anagram(inputWord, words);
//     for (int i=0; i<anagrams.size(); i++)
//     {
//         cout << anagrams[i] << endl;
//     }
//     return 0;
// }

vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

//Implement this function
vector<string> anagram(string word, vector<string> wordlist)
{
    unordered_map<char, int> choseWord, listWord;  // map for the word that is passed and one for words in the list
    vector<string> anagrams;    // vector to return

    // go through each char in word and hash it into choseWord map
    for (int i = 0; i < word.length(); i++){
        choseWord[word[i]]++;
    }

    for (int j = 0; j < wordlist.size(); j++){ // iterate through word list
        if (wordlist[j].length() == word.length()){ // if current string is the same length as passed word, an anagram is possible
            for (int i = 0; i < wordlist[j].length(); i++){ // go through current string and hash each char into listWord
                listWord[wordlist[j][i]]++;
            }
            if (choseWord == listWord){  // if choseWord == listWord then we have an anagram
                anagrams.push_back(wordlist[j]);
            }
            listWord.clear();
        }
    }

    return anagrams;
}