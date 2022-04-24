CC = g++ -std=c++11
CFLAGS = -Wall

Trie.o: Trie.cpp Trie.h 
	$(CC) $(CFLAGS) -c Trie.cpp

Node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) -c Node.cpp

Trie: Node.o Trie.o
	$(CC) $(CFLAGS) -o Trie Node.o Trie.o

TrieTest: Trie.o TrieTest.cpp
	$(CC) $(CFLAGS) -o TrieTest Trie.o TrieTest.cpp

test: Trie.o tests.cpp
	$(CC) $(CFLAGS) -o Test Trie.o tests.cpp

Run:
	./TrieTest wordTest.txt wordComp.txt

clean:
	rm -f *.o *.a TrieTest