#include <iostream>
using namespace std;

class Stack {
public:
  int size;
  int* arr;
  int top;
  Stack(int size) {
    top = -1;
    this->size = size;
    arr = new int(size);
  }
  void PushElt(int element) {
    top++;
    arr[top] = element;
  }

  int topElt() { return arr[top]; }

  void PopElt() { top--; }

  void RemoveMiddle() {
    for (int i = size; i > size / 2; i--) {
      arr[i] = arr[i + 1];
      PopElt();
    }
  }
};

int main() {
  Stack stk(12);
  stk.PushElt(12);
  stk.PushElt(34);
  stk.PushElt(56);
  stk.PushElt(78);
  stk.PushElt(90);
  stk.PushElt(12);
  stk.PushElt(34);
  stk.PushElt(56);
  stk.PushElt(78);
  stk.PushElt(90);
  stk.PushElt(91);
  stk.PushElt(89);
  stk.PushElt(89);

  cout << "Top Element: " << stk.topElt() << endl;
  stk.RemoveMiddle();

  cout << "Top Element after removing middle: " << stk.topElt() << endl;

  return 0;
}
