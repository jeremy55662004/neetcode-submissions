/**
 * TrieNode structure represents each "room" in the Trie.
 * Each node contains an array of pointers to its children (26 letters)
 * and a boolean flag to mark the end of a valid word.
 */
class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        // Initialize all 26 child pointers to nullptr (no path yet)
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;

    /**
     * A helper function that uses Depth First Search (DFS) to navigate the Trie.
     * This is essential for handling the '.' wildcard.
     */
    bool searchHelper(const string& word, int index, TrieNode* node) {
        // Base case: If we have processed all characters in the string
        if (index == word.length()) {
            return node->isEndOfWord;
        }

        char c = word[index];

        // Case 1: Wildcard character '.'
        if (c == '.') {
            // Try every existing child node (every door that is not nullptr)
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr) {
                    // Recursively check if the rest of the word matches from this child
                    if (searchHelper(word, index + 1, node->children[i])) {
                        return true;
                    }
                }
            }
            // If none of the 26 paths work, the word is not found
            return false;
        } 
        // Case 2: Specific letter 'a' - 'z'
        else {
            int i = c - 'a';
            // If the specific path does not exist, return false
            if (node->children[i] == nullptr) {
                return false;
            }
            // Move to the next node and the next character in the string
            return searchHelper(word, index + 1, node->children[i]);
        }
    }

public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) {
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->isEndOfWord = true; // Mark the end of the added word
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        // Start the recursive search from the root at index 0
        return searchHelper(word, 0, root);
    }
};
