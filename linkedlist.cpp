

#include <iostream>
using namespace std;

// Lưu địa chỉ của 1 Node ?
// Node *
struct Node {
    char data;
    Node *next;
};

Node *makeNode(char value) {
    // Đây là hàm dùng để tạo ra 1 Node trong bộ nhớ dùng chung cho cả chương trình(heap)
    Node *newNode = new Node;

    // Gán data của newNode = value ?
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void pushBack(char value, Node *&head) {
    // Hàm thêm 1 phần tử vào cuối danh sách;
    if (head == nullptr) {
        head = makeNode(value);
        return;
    }

    Node *current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = makeNode(value);
}

void popBack(Node *&head) {
    if (head == nullptr) {
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node *current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
}
void print(Node *head) {
    // 5phut Viết hàm in ra danh sách liên kết phân cách nhau bởi ->
    Node *current = head;

    while (current != nullptr) {
        cout << current->data << "->";
        current = current->next;
    }
    cout << "null";
}

// TODO !

void pushFront(int value, Node *&head) {
    // Thêm 1 Phần tử vào đầu danh sách
    Node *newNode = makeNode(value);
    newNode->next = head;
    head = newNode;
}

void popFront(Node *&head) {
    // Xoá 1 phần tử ở đầu danh sách
    if (head == nullptr){
        return;
    }

    Node *current = head;
    head = head->next;
    delete current;
}

void insert(int value, int index, Node *&head) {
    // chèn 1 phần tử vào vị trí index
    if (index == 0 ){
        pushFront(value, head);
    }

    Node *current = head;
    int count = 0;

    while (current != nullptr && count < index - 1){
        current = current->next;
        count++;
    }

    if (current == nullptr) return;

    Node *newNode = makeNode(value);
    newNode->next = current->next;
    current->next = newNode;
}


int get(int index, Node* head) {
    // lấy giá trị của Node tại vị trí index
    Node *current = head;
    int count = 0;

    while (current != nullptr){
        if (count == index) return current->data;
        current = current->next;
        count++;
    }

    return -1;
}


int main() {
    Node *head = nullptr;

    // ((() () )())() Kiểm tra dãy ngoặc này có đúng hay ko ?
}