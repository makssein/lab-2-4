#include <iostream>

struct List{
    List* next;
    int number;
};
void addToList(List* head, int number){
    List* p = new List;
    p->number = number;

    p->next = head->next;
    head->next = p;
}

void addToPosition(List* head, int newNumber, int position){
    List* p = head;
    int i = 0;
    while (i <= position) {
        if (p == nullptr) {
            break;
        }
        if (i == position) {
            List* z = new List;
            z->next = p->next;
            p->next = z;
            z->number = newNumber;
        }
        p = p->next;
        i++;
    }
}

void printList(List* head){
    List* p = head->next;
    while (p != nullptr)
    {
        std::cout << p->number << std::endl;
        p = p->next;
    }
}


int main() {
    List* head = new List;
    head->next = nullptr;


    for(int i = 0; i < 5; i++){
        addToList(head, i);
    }

    addToPosition(head, -1, 0);

    printList(head);
    return 0;
}
