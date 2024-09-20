#include <iostream>
#include <vector>
using namespace std;

const int length = 3;

// Oppgave a) og Oppgave b)
void handleInput(string *words, string &sentence) {
  cout << "Provide 3 words" << endl;
  for (int i = 0; i < length; i++) {
    cout << "Word nr" << i + 1 << ": ";
    cin >> words[i];
    string ending = i == length - 1 ? "." : " ";
    sentence += words[i] + ending;
  }
}

// Oppgave c)
void printLengthsOf(const string *words) {
  for (int i = 0; i < length; i++) {
    cout << "Length of Word nr" << i + 1 << ": " << words[i].size() << endl;
  }
}

bool canReplace(int toBeReplaced, int lastIndex) {
  if (lastIndex < toBeReplaced)
    cout << "Cannot replace from position: " << toBeReplaced << " since given string last index is: " << lastIndex << endl;
  return lastIndex < toBeReplaced;
}

// Oppgave e)
void replaceFromToWith(string &subject, int from, int to, string with) {
  if (canReplace(from, subject.size() - 1))
    return;

  for (int i = from; i <= to; i++) {
    if (canReplace(i, subject.size() - 1))
      return;
    subject.replace(i, 1, with);
  }
}

// Oppgave f)
string getSubStringOf(string subject, int cutoff) {
  if (subject.size() - 1 < cutoff)
    return subject;
  return subject.substr(0, cutoff);
}

// Oppgave g)
bool substringExists(string subject, string substring) {
  return subject.find(substring) != string::npos;
}

// Oppgave h)
void printIndexesOfSubstring(string subject, string substring) {
  if (!substringExists(subject, substring)) {
    cout << "\"" << substring << "\" does not exit in \"" << subject << "\"" << endl;
    return;
  }

  int index = subject.find(substring, 0);
  while (index != string::npos) {
    cout << "\"" << substring << "\" found at index " << index << endl;
    index = subject.find(substring, index + 1);
  }
}

int main() {
  string words[length];
  string sentence;

  handleInput(words, sentence);
  printLengthsOf(words);
  cout << "Length of Sentence: " << sentence.size() << endl;

  string sentence2 = sentence;
  replaceFromToWith(sentence2, 10, 12, "x");
  cout << "Sentence Copy after replacement: " << sentence2 << endl;
  string sentence_start = getSubStringOf(sentence, 5);
  cout << "Sentence is: " << sentence << endl;
  cout << "Sentence Start is: " << sentence_start << endl;

  string wordToCheck = "hello";
  string result = substringExists(sentence, wordToCheck) ? "Yes" : "No";
  cout << "Is \"" << wordToCheck << "\" substring of sentence: " << result << endl;

  string wordToCheck2 = "er";
  printIndexesOfSubstring(sentence, wordToCheck2);

  return 0;
}
