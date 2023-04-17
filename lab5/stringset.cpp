/*
 * Name:            Jai Agarwal
 * Date Submitted:  3/6/23
 * Lab Section:     002
 * Assignment Name: Lab 5 - Spell check with hashing
 */

#include "stringset.h"
#include <iostream>

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const
{
    return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
    return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
    return size;
}

void Stringset::insert(string word)
{
    int location;
    hash<string> hash;
    size = table.size();
    vector<list<string>> oldTable;
    if (num_elems == size){ // if table needs to grow
        oldTable = table;
        table.clear();
        size = num_elems*2;     // double the size
        table.resize(size);
        for (auto v : oldTable){   // rehash elements
            for (auto l : v){
                location = hash(l) % size;
                table[location].push_back(l);
            }
        }
    }
    oldTable.clear();
    
    if (find(word)){    // if word is aready in table then return
        return;
    }
    else {  // else, add it
        location = hash(word) % size;
        table[location].push_back(word);    // push word into list at table[location]
        ++num_elems;        // increment number of elements
    }
}

bool Stringset::find(string word) const
{
    int location;
    hash<string> hash;
    location = hash(word) % size;
    for (auto l : table[location]){ // l iterator is for list traversal
        if (l == word)       // if word is present
            return true;
    }
    return false;
}

void Stringset::remove(string word)
{
    int location;
    hash<string> hash;
    if (find(word)){    // if the word exists
        location = hash(word) % size;   // rehash word to get same index location
        table[location].remove(word);   // look through table[location] list for the word and remove it
        --num_elems;                    // decrement number of elements 
    }
    else{
        return;
    }
}