#include <iostream>
#include <string>
#include "Trie.h"
#include <vector>

void testAdd(Trie &trie, vector<string> words);
void testIsAWord(Trie &trie, vector<string> words);

int main(int argc, char const *argv[])
{
    Trie trie;

    trie.addAWord("cat");
    trie.addAWord("cast");
    trie.addAWord("dog");

    //std::cout << trie.isAWord("ca") << std::endl;

    for(string s : trie.allWordsStartingWithPrefix("ca")){
        std::cout << s;
    }
    std::cout << trie.allWordsStartingWithPrefix("ca").size() << std::endl;

    return 0;
}

void testAdd(Trie &trie, vector<string> words)
{

    for (string s : words)
    {
        std::cout << s << std::endl;
        trie.addAWord(s);
    }
}

void testIsAWord(Trie &trie, vector<string> words)
{
    for (string s : words)
    {
        std::cout << trie.isAWord(s) << std::endl;
    }

    std::cout << trie.isAWord("sldkfjasdlkfjsa");
}
