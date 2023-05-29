#include <iostream>

#include "circular-linked-list.hpp"

int main() { 
    CircularLinkedList<int> hold;
    hold.InsertInOrder(0);
    hold.InsertInOrder(4);
    hold.Reverse();
    CircularLinkedList<int> reversed;
    reversed = hold;
    std::cout << reversed << '\n';
    /*
    CircularLinkedList<int> hold;
    hold.InsertInOrder(0);
    hold.InsertInOrder(1);
    hold.InsertInOrder(5);
    hold.InsertInOrder(2);
    hold.InsertInOrder(20);
    hold.InsertInOrder(11);
    CircularLinkedList<int> holdtwo(hold);
    std::cout << "original in order:  " << hold << '\n';
    holdtwo.Reverse();
    std::cout << "holdtwo after reversing:  " << holdtwo << '\n';
    holdtwo = hold;
    std::cout << "holdtwo after assignment operator:  " << holdtwo << '\n';
    CircularLinkedList<int> empty;
    hold = empty;
    std::cout << "empty list assignment:  " << hold << "\n"; 
    hold.Reverse();
    std::cout << "empty list assignment reversed:  " << hold << "\n"; 
    CircularLinkedList<int> holdthree(empty);
    std::cout << "empty list copy constructor:  " << holdthree << "\n"; 

    holdthree.InsertInOrder(1);
    holdthree.InsertInOrder(1);
    holdthree.Reverse();
    std::cout << "2 item list reversed:  " << holdthree; */
}
