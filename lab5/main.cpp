/*
* Name:             Jai Agarwal
* Date Submitted:   3/6/23
* Lab Section:      002
* Assignment Name:  Lab 5 - Spell check with hashing
*/

#include "stringset.h"
#include <iostream>
#include <fstream>

void testStringset(Stringset& words);
void loadStringset(Stringset& words, string filename);
vector<string> spellcheck(const Stringset& words, string word);

// int main()
// {
//     Stringset wordlist;
//     testStringset(wordlist);
//     return 0;
// }

void testStringset(Stringset& words)
{
    string choice;
    string word;
    do
    {
        cout << "I: insert word" << endl;
        cout << "F: find word" << endl;
        cout << "R: remove word" << endl;
        cout << "P: print words in stringset" << endl;
        cout << "Q: quit" << endl;
        cin >> choice;
        switch (choice[0])
        {
            case 'I':
            case 'i':
            cout << "Enter word to insert: ";
            cin >> word;
            words.insert(word);
            break;
            case 'F':
            case 'f':
            cout << "Enter word to find: ";
            cin >> word;
            if (words.find(word))
            {
                cout << word << " in stringset" << endl;
            }
            else
            {
                cout << word << " not in stringset" << endl;
            }
            break;
            case 'R':
            case 'r':
            cout << "Enter word to remove: ";
            cin >> word;
            words.remove(word);
            break;
            case 'P':
            case 'p':
            vector<list<string>> t = words.getTable();
            int numWords = words.getNumElems();
            int tSize = words.getSize();
            for(int i=0; i<tSize; ++i)
            {
                list<string>::iterator pos;
                for (pos = t[i].begin(); pos != t[i].end(); ++pos)
                {
                    cout << *pos << endl;
                }
            }
            cout << "Words: " << numWords << endl;
        }
    } while (choice[0] != 'Q' && choice[0] != 'q');
}

void loadStringset(Stringset& words, string filename)
{
    ifstream inFile(filename);  // set up input stream
    string word;
    while(getline(inFile, word)){   // read in file and insert words into table
        words.insert(word);
    }
}

vector<string> spellcheck(const Stringset& words, string word)
{
    vector<string> alternatives;    // vector of alternative words
    string alternateWord;
    for (int c = 0; c < word.length(); c++){ // change 1 char at a time
        alternateWord = word;
        for (char i = 97; i <= 122; i++){   // all ascii letter combos
            alternateWord[c] = i;
            if (words.find(alternateWord) && alternateWord != word) // if the value of alternate exists in the list
                alternatives.push_back(alternateWord);              // and it is different than word, push it to alternatives vector
        }
    }

    return alternatives;
}