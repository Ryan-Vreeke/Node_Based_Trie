/**
 * @file Trie.h
 * @author Ryan Vreeke(you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-02-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;
class Trie
{
private:
    Trie *letters[26] = {};

public:
    bool word; // bool to determin if we are at a word in a trie
    /**
     * @brief Construct a new Trie object
     *
     */
    Trie();
    /**
     * @brief Destroy the Trie object
     *
     */
    ~Trie();
    /**
     * @brief Construct a new Trie object
     *
     * @param other
     */
    Trie(const Trie &other);
    /**
     * @brief
     *
     * @param other
     * @return Trie&
     */
    Trie &operator=(Trie other);
    /**
     * @brief
     * add words into the trie
     * @param aWord
     */
    // a=097 - z=122
    void addAWord(string aWord);

    /**
     * @brief
     * returns ia aword is a word in the trie
     * @param aWord
     * @return true
     * @return false
     */

    bool isAWord(string aWord);

    /**
     * @brief
     *  finds all words starting with the prefix and returns them as a vector
     * @param prefix
     * @return vector<string>
     */
    vector<string> allWordsStartingWithPrefix(string prefix);

private:
    /**
     * @brief Get the Ascii object
     * this is a helper method that will return the ascii number for a given letter from a-z
     *
     * @param c
     * @return int
     */
    int getAscii(char c);
    /**
     * @brief
     * will determin if a branch containing the char c is in the trie
     * @param c
     * @return true
     * @return false
     */
    bool isNotIn(char c);
    /**
     * @brief Get the Words object
     * helper method to return the prefix of words recursively. this will get called by allwordstartingwithprefix
     * places all the words that start with the prefix into a vector
     * 
     * @param prefix 
     * @param words 
     * @param loc 
     */
    void getWords(string prefix, vector<string> &words, string loc);
};

#endif