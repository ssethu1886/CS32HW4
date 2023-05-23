

#ifndef WordTree_h
#define WordTree_h

#include <iostream>
#include <string>

typedef std::string WordType;

struct WordNode {
 WordType m_data;
 WordNode *m_left;
 WordNode *m_right;
    int count;
    
    WordNode(WordType v){
        m_data = v;
        count = 1;
        m_left = nullptr;
        m_right = nullptr;
    }
                         
 // You may add additional data members and a constructor
 // in WordNode
};

class WordTree {
 private:
 WordNode *root;
    
//helper function for destructor, frees memory in tree
    void FreeTree(WordNode *rhs);
      
//helper for copy constructor
    WordNode* copyHelper (WordNode *cur);
    
// helper for << overloader
    void outputHelper (std::ostream &out, const
                       WordTree& rhs);
// helper for totalWords
    int totalHelper(WordNode* cur) const;

    // helper for distinctWords
        int distinctHelper(WordNode* cur) const;
 public:
 // default constructor
 WordTree() : root(nullptr) { };

 // copy constructor
 WordTree(const WordTree& rhs);

 // assignment operator
 const WordTree& operator=(const WordTree& rhs);
 // Inserts v into the WordTree
 void add(WordType v);
    
 // Returns the number of distinct words / nodes
    
    int distinctWords() const;
     // Returns the total number of words inserted, including
     // duplicate values
     int totalWords() const;

     // Prints the WordTree
     friend std::ostream& operator<<(std::ostream &out, const
    WordTree& rhs);
     // Destroys all the dynamically allocated memory in the
     // tree
     ~WordTree();
    };

#endif /* WordTree_h */
