#include <iostream>
#include <stack>
#include <string>
#include "zasobnik.h"

int main()
{

    char vlozenyText[50];
    int i, delkaTextu, pocetRozdilu = 0;


    std::cout << "zadej slovo, vetu nebo cislo (bez diakritiky) s nminimalni delkou 2 znaku: ";
    std::cin.getline(vlozenyText, 50);
    
    // zjištění délky znaku
    delkaTextu = strlen(vlozenyText);                                                     

    if (delkaTextu <= 1)                                                                   // alespoň dva znaky
    {
        std::cout << "Nezadali jste hodnotu s minimalnim poctem znaku a program budu nyni ukoncen. \n";
        return 0;

    }

    Stack stack;                                                                   // vytvoření zásobníku

    i == 0;
    for (i = 0; i <= delkaTextu - 1; i++) stack.Push(vlozenyText[i]);             // funkce Push zásobníku


    // Palindrom 

    i == 0;
    for (i = 0; i < delkaTextu; i++) {                                           // vyhodnocení shody
        if (vlozenyText[i] != stack.Pop())
        {
            pocetRozdilu = 1;                                                    
            break;
        }
    }
     // funkce Pop zásobníku
    while (!stack.IsEmpty()) std::cout << stack.Pop() << ", ";                

    if (pocetRozdilu == 0)
    {
        std::cout << vlozenyText << " je palindrom \n";                         
    }
    else
    {
        std::cout << vlozenyText << " neni palindrom \n";                        
    }
    return 0;
}