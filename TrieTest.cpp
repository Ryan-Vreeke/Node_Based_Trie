/**
 * @file TrieTest.cpp
 * @author Ryan Vreeke (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Trie.h"


/**
 * @brief tests for the trie class 
 * take in two files, one with the words to add and another with the list of words to compare agians
 * call command like ./TrieTest somefile.txt someother.txt
 */
using namespace std;
int main(int argc, char const *argv[])
{
    if (argc > 3 || argc < 2)
    {
        std::cout << "Invalid number of arguments" << std::endl;
        return 0;
    }
    std::cout << argv[1] << std::endl;
    std::cout << argv[2] << std::endl;

    string build = argv[1];
    string test = argv[2];

    vector<string> words;

    fstream file;
    string word;
    Trie trie;

    // adds words to trie
    file.open(build.c_str());
    while (file >> word)
    {
        trie.addAWord(word);
    }

    file.close();




    // compares words to trie
    file.open(test.c_str());
    while (file >> word)
    {
        cout << word;
        if (trie.isAWord(word))
        {
            cout << " is found" << endl;
        }
        else
        {
            cout << " is not found, did you mean:" << endl;
            vector<string> allPre = trie.allWordsStartingWithPrefix(word);
            for (string related : allPre)
            {
                cout << "   ";
                cout << related << endl;
            }
        }
    }

    file.close();

    // rule of three testing
    Trie copy = trie; // copy

    for (string words : trie.allWordsStartingWithPrefix(""))
    {
        if (!copy.isAWord(words))
        {
            cout << "Error: Was not copied" << endl;
        }
    }

    copy.~Trie();

    Trie assign; // assign
    assign.addAWord("bird");
    assign.addAWord("spongebob");
    assign.addAWord("mysterydungeon");
    assign = trie;
    if (assign.isAWord("bird") || assign.isAWord("spongebob") || assign.isAWord("mysterydungeon"))
    {
        cout << "Error: Was not assigned" << endl;
    }
    for (string words : trie.allWordsStartingWithPrefix(""))
    {
        if (!assign.isAWord(words))
        {
            cout << "Error: Was not assigned" << endl;
        }
    }

    assign.~Trie();

//https://www.cplusplus.com/doc/tutorial/exceptions/ for try-catch test on destructor
  try
  {
      assign.isAWord("bird");
      throw "Assign does not exist";
  }
  catch (string error)
  {
    cout << error << endl;
  }

  try
  {
      copy.isAWord("bird");
      throw "Copy does not exist";
  }
  catch (string error)
  {
    cout << error << endl;
  }

    return 0;
}

