#include <memory>
#include <iostream>
using namespace std;

struct Node {
    int data;
    std::shared_ptr<Node> next;
    std::shared_ptr<Node> prev;
};

void printForward(std::shared_ptr<Node> head) {
    std::shared_ptr<Node> traverse = head;
    while (traverse != nullptr) {
        cout << traverse->data << endl;
        traverse = traverse->next;
    }
}

void printBackward(std::shared_ptr<Node> tail) {
    std::shared_ptr<Node> traverse = tail;
    while (traverse != nullptr) {
        cout << traverse->data << endl;
        traverse = traverse->prev;
    }
}

int main()
{
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;

    std::shared_ptr<Node> node = std::make_shared<Node>();
    node->data = 0;
    node->next = nullptr;
    node->prev = node->next;
    head = node;
    tail = head;

    for (int i = 1; i < 10; i++){
        std::shared_ptr<Node> node = std::make_shared<Node>();
        node->data = i;
        node->next = nullptr;
        node->prev = tail;
        tail->next = node;
        tail = node;
    }

    cout << "Printing from head to tail: " << endl;

    printForward(head);

    cout << "Printing from tail to head: " << endl;

    printBackward(tail); 
    return 0;
}

