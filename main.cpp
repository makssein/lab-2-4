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
    //std::cerr << p << " " << p->number << std::endl;
    for(int i = 0; i < position; i++){
        p = p->next;
    }
    p->number = newNumber;
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

    addToPosition(head, -1, 2);

    printList(head);
    return 0;
}
