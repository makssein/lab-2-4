#include <iostream>
#include <vector>
#include "timer.hpp"

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

void clear(List* head){
    List* tmp;
    List* p = head->next;
    while (p != nullptr){
        tmp = p;
        p = p->next;
        delete tmp;
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

    std::vector<int> mas;

    for(int i = 0; i < 10000; i++){
        addToList(head, i);
    }
    Timer listTimer;
    for(int i = 0; i < 1000; i++){
        addToPosition(head, i*i, i);
    }
    std::cout << "Время, затраченное на обработку листа: " << listTimer.elapsed() << " секунд" << std::endl;


    //массив
    for(int i = 0; i < 10000; i++){
        mas.push_back(i);
    }
    auto iter = mas.cbegin();
    Timer masTimer;
    for(int i = 0; i < 1000; i++){
        mas.emplace(iter + i,i);
    }
    std::cout << "Время, затраченное на обработку массива: " << listTimer.elapsed() << " секунд" <<  std::endl;

    /*for (auto const &element: mas)
        std::cout << element << ' '; */
    //конец массива

    //printList(head);
    clear(head);
    return 0;
}
