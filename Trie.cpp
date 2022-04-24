/**
 * @file Trie.cpp
 * @author Ryan Vreeke (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-02-12
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <string>
#include <vector>
#include <iostream>
#include "Trie.h"

/**
 * @brief constructs a trie
 */
Trie::Trie()
{
    word = false;
}

/**
 * @brief destroys trie
 */
Trie::~Trie()
{
    for (int i = 0; i < 26; i++)
    {
        delete letters[i]; // delete all letters of the heap
    }
}

/**
 * @brief creates a copy of trie. Ex: Trie trie = oldTrie.
 */
Trie::Trie(const Trie &other)
{
    word = other.word;
    *letters = *other.letters;
}

/**
 * @brief assigns one trie to another. This does not point to the same trie; makes another trie with same
 *values
 */
Trie &Trie::operator=(Trie other)
{
    std::swap(letters, other.letters);
    std::swap(word, other.word);
    return *this;
}

/**
 * @brief Adds a word to the trie
 */
void Trie::addAWord(string aWord)
{
    if (aWord.length() == 0)
    {
        return;
    }

    char c = aWord[0];
    string temp;
    if (aWord.length() > 1)
    {
        temp = aWord.substr(1);

        if (isNotIn(c))
        {
            letters[getAscii(c)] = new Trie();
            letters[getAscii(c)]->addAWord(temp);
        }
        else
        {
            letters[getAscii(c)]->addAWord(temp);
        }
    }
    else
    {
        if (isNotIn(c))
        {
            letters[getAscii(c)] = new Trie();
            letters[getAscii(c)]->word = true;
        }
        else
        {
            return;
        }
    }
}

bool Trie::isAWord(string aWord)
{
    if (aWord.length() == 0)
    {
        return false;
    }
    char c = aWord[0];
    if (aWord.length() == 1)
    {
        if (isNotIn(c))
        {
            return false;
        }
        else
        {
            return letters[getAscii(c)]->word;
        }
    }
    string nextWord = aWord.substr(1);

    if (isNotIn(c))
    {
        return false;
    }
    else
    {
        return letters[getAscii(c)]->isAWord(nextWord);
    }

    return false;
}

vector<string> Trie::allWordsStartingWithPrefix(string prefix)
{
    vector<string> words;
    getWords(prefix, words, prefix); // takes in the original prefix and the location that you need to get to before you start appending and looking for words
    /*

    if(isAWord(prefix)){
        words.push_back(prefix);
    }*/
    return words;
}

void Trie::getWords(string prefix, vector<string> &words, string loc)
{
    if (loc.length() >= 1) // if loc is larger than one then it needs to keep going down the Trie
    {
        string temp = loc.substr(1);
        char c = loc[0];

        if (!isNotIn(c))
        {
            letters[getAscii(c)]->getWords(prefix, words, temp);
        }
    }
    else
    { // we are at the end of the prefix

        for (int i = 0; i < 26; i++)
        {
            if (letters[i] != 0)
            {
                string nextPrefix = (prefix + char(i + 97));
                if (letters[i]->word)
                {
                    words.push_back(nextPrefix);
                }
                letters[i]->getWords(nextPrefix, words, loc);
            }
        }
    }
}

int Trie::getAscii(char c)
{
    return (c - 97);
}

bool Trie::isNotIn(char c)
{
    return letters[getAscii(c)] == 0;
}
