#include <string>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct Trie {
  bool end;
  bool is_next;
  Trie* digit[10];

  Trie() {
    end = false;
    is_next = false;
    for (int i = 0; i  < 10; i++) {
      digit[i] = NULL;
    }
  }

  void insert(const char* s) {
    if (!*s) {
      if (!is_next) this->end = true;
      return;
    }
    int next = *s - '0';
    if (!digit[next]) {
      digit[next] = new Trie;
      this->end = false;
      this->is_next = true;
      }
    digit[next]->insert(s+1);
  }

  bool find(const char* s) {
    if (!*s) {
      if (end) return true;
      return false;
    }
    int next = *s - '0';
    if (!digit[next]) return false;
    return digit[next]->find(s+1);
  }
};

bool solution(vector<string> phone_book) {
    bool answer = true;
    Trie* root = new Trie;
    for (int i = 0; i < phone_book.size(); i++) {
        root->insert(phone_book[i].c_str());
    }
    for (int i = 0; i < phone_book.size(); i++) {
        if (root->find(phone_book[i].c_str()) == false)
            answer = false;
    }
    
    return answer;
}