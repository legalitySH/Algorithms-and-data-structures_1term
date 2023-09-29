#include <iostream>
#include <cstring>

using namespace std;

struct StackNode {
    char data;
    StackNode* next;
};


class Stack {
public:
    Stack() {
        top = nullptr;
    }

    void push(char data) {
        StackNode* newNode = new StackNode;
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            cerr << "Стек пуст" << endl;
            return '\0';
        }
        StackNode* temp = top;
        top = top->next;
        char data = temp->data;
        delete temp;
        return data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    char peek() {
        if (isEmpty()) {
            cerr << "Стек пуст" << endl;
            return '\0';
        }
        return top->data;
    }

private:
    StackNode* top;
};


bool checkBrackets(const char* str) {
    int len = strlen(str);
    Stack stack;


    for (int i = 0; i < len; i++) {
        char c = str[i];
        switch (c) {
        case '(':
        case '[':
        case '{':
            stack.push(c);
            break;
        case ')':

            if (stack.isEmpty() || stack.pop() != '(') {
                return false;
            }
            break;
        case ']':
            if (stack.isEmpty() || stack.pop() != '[') {
                return false;
            }
            break;
        case '}':
            if (stack.isEmpty() || stack.pop() != '{') {
                return false;
            }
            break;
        default:
            break;
        }
    }

    return stack.isEmpty();
}

int main() {
    setlocale(0, "");
    char str[100];
    cout << "Введите строку: ";
    cin.getline(str, 100);

    if (checkBrackets(str)) {
        cout << "Good!" << endl;
    }
    else {
        cout << "Bad!" << endl;
    }


    return 0;
}
