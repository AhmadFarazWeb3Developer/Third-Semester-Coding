#include <iostream>
#include <string>
using namespace std;

// Class to represent a node storing the meaning of a word
class MeaningNode {
public:
  string meaning;
  MeaningNode* next;
  MeaningNode(string _meaning) : meaning(_meaning), next(nullptr) {}
};

// Class to represent a node storing a word and its meanings
class WordNode {
public:
  string word;
  MeaningNode* meanings;
  WordNode* next;
  WordNode(string _word, string _meaning) : word(_word), next(nullptr) {
    meanings = new MeaningNode(_meaning);
  }

  ~WordNode() {
    delete meanings; // Free the dynamically allocated memory for meanings
  }
};

// Class to represent a node storing an alphabet and its words
class AlphabetNode {
public:
  char alphabet;
  WordNode* words;
  AlphabetNode* next;

  AlphabetNode(char _alphabet) : alphabet(_alphabet), next(nullptr) {
    words = nullptr;
  }

  ~AlphabetNode() {
    delete words; // Free the dynamically allocated memory for words
  }
};

// Class to represent a dictionary
class Dictionary {
public:
  AlphabetNode* head;
  AlphabetNode* findAlphabet(char _alphabet) {
    AlphabetNode* current = head;
    while (current != nullptr && current->alphabet != _alphabet) {
      current = current->next;
    }
    return current;
  }
  WordNode* findWord(AlphabetNode* alphabet, string _word) {
    if (alphabet == nullptr)
      return nullptr;
    WordNode* current = alphabet->words;
    while (current != nullptr && current->word != _word) {
      current = current->next;
    }
    return current;
  }

public:
  Dictionary() : head(nullptr) {}

  ~Dictionary() {
    while (head != nullptr) {
      AlphabetNode* temp = head;
      head = head->next;
      delete temp; // Free the dynamically allocated memory for alphabets
    }
  }

  void insertWord(string _word, string _meaning) {
    char firstChar = _word[0];
    if (firstChar < 'a' || firstChar > 'z') {
      cout << "Invalid word. Words should start with a lowercase letter."
        << endl;
      return;
    }

    if (head == nullptr) {
      head = new AlphabetNode(firstChar);
    }

    AlphabetNode* alphabet = findAlphabet(firstChar);

    if (alphabet == nullptr) {
      alphabet = new AlphabetNode(firstChar);
      alphabet->next = head;
      head = alphabet;
    }

    WordNode* existingWord = findWord(alphabet, _word);
    if (existingWord != nullptr) {
      cout << "Word already exists with the following meanings:" << endl;
      MeaningNode* currentMeaning = existingWord->meanings;
      while (currentMeaning != nullptr) {
        cout << currentMeaning->meaning << endl;
        currentMeaning = currentMeaning->next;
      }

      cout << "Do you want to add a new meaning? (y/n): ";
      char choice;
      cin >> choice;

      if (choice == 'y') {
        MeaningNode* newMeaning = new MeaningNode(_meaning);
        newMeaning->next = existingWord->meanings;
        existingWord->meanings = newMeaning;
        cout << "New meaning added successfully." << endl;
      }
      else {
        cout << "No new meaning added." << endl;
      }

      return;
    }

    WordNode* newWord = new WordNode(_word, _meaning);
    newWord->next = alphabet->words;
    alphabet->words = newWord;

    cout << "Word added successfully." << endl;
  }

  void searchWord(string _word) {
    char firstChar = _word[0];
    AlphabetNode* alphabet = findAlphabet(firstChar);

    if (alphabet == nullptr) {
      cout << "No words found for this alphabet." << endl;
      return;
    }

    WordNode* word = findWord(alphabet, _word);

    if (word == nullptr) {
      cout << "Word not found in the dictionary." << endl;
    }
    else {
      cout << "Meanings of the word '" << _word << "':" << endl;
      MeaningNode* currentMeaning = word->meanings;
      while (currentMeaning != nullptr) {
        cout << currentMeaning->meaning << endl;
        currentMeaning = currentMeaning->next;
      }
    }
  }

  void deleteWord(string _word) {
    char firstChar = _word[0];
    AlphabetNode* alphabet = findAlphabet(firstChar);

    if (alphabet == nullptr) {
      cout << "No words found for this alphabet." << endl;
      return;
    }

    WordNode* prev = nullptr;
    WordNode* current = alphabet->words;

    while (current != nullptr && current->word != _word) {
      prev = current;
      current = current->next;
    }

    if (current == nullptr) {
      cout << "Word not found in the dictionary." << endl;
      return;
    }

    if (prev == nullptr) {
      alphabet->words = current->next;
    }
    else {
      prev->next = current->next;
    }

    delete current; // Free the dynamically allocated memory for the word
    cout << "Word deleted successfully." << endl;
  }

  void printAlphabetically() {
    AlphabetNode* current = head;
    while (current != nullptr) {
      cout << "Alphabet: " << current->alphabet << endl;
      WordNode* currentWord = current->words;
      while (currentWord != nullptr) {
        cout << "  Word: " << currentWord->word << endl;
        MeaningNode* currentMeaning = currentWord->meanings;
        while (currentMeaning != nullptr) {
          cout << "    Meaning: " << currentMeaning->meaning << endl;
          currentMeaning = currentMeaning->next;
        }
        currentWord = currentWord->next;
      }
      current = current->next;
    }
  }

  void printReverseRecursively(WordNode* word) {
    if (word == nullptr)
      return;
    printReverseRecursively(word->next);

    cout << "Word: " << word->word << endl;
    MeaningNode* currentMeaning = word->meanings;
    while (currentMeaning != nullptr) {
      cout << "  Meaning: " << currentMeaning->meaning << endl;
      currentMeaning = currentMeaning->next;
    }
  }

  void printReverseUsingStack() {
    // Implementing this is left as an exercise for the user
    cout << "This feature is not implemented yet." << endl;
  }
};

int main() {
  Dictionary dictionary;

  char choice;
  string word, meaning;

  do {
    cout << "\nMenu:\n";
    cout << "1. Insert a new word\n";
    cout << "2. Search for a word\n";
    cout << "3. Delete a word\n";
    cout << "4. Print the dictionary words alphabetically\n";
    cout << "5. Print the dictionary in reverse order using recursion\n";
    cout << "6. Print the dictionary in reverse order using a stack\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case '1':
      cout << "Enter word: ";
      cin >> word;
      cout << "Enter meaning: ";
      cin >> meaning;
      dictionary.insertWord(word, meaning);
      break;
    case '2':
      cout << "Enter word: ";
      cin >> word;
      dictionary.searchWord(word);
      break;
    case '3':
      cout << "Enter word: ";
      cin >> word;
      dictionary.deleteWord(word);
      break;
    case '4':
      dictionary.printAlphabetically();
      break;
    case '5':
      dictionary.printReverseRecursively(dictionary.head->words);
      break;
    case '6':
      dictionary.printReverseUsingStack();
      break;
    case '7':
      cout << "Exiting program.\n";
      break;
    default:
      cout << "Invalid choice. Please try again.\n";
      break;
    }
  } while (choice != '7');

  return 0;
}
