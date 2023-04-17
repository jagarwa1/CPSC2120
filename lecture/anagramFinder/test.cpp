#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){

    string word = "steak";
    string word2 = "stakes";
    unordered_map<char, int> choseWord, listWord;
    hash<char> hash;
    int location;
    char c = 'a';
    int i = 0;
    int val;
    for (int i = 0; i < word.length(); i++){
        choseWord.insert(make_pair(word[i], word[i]));
    }
    
    // for (int i = 0; i < word2.length(); i++){
    //     listWord.insert(make_pair(word2[i], word2[i]));
    // }

    for (int i = 0; i < word2.length(); i++){ // go through current string and hash each char into listWord
        listWord[word2[i]]++;
    }

    for (int i = 0; i < listWord.size(); i++){
        cout << i << ": " << listWord[i] << endl;
    }

    if (choseWord == listWord){
        cout << "equal!\n";
        exit(1);
    }

}