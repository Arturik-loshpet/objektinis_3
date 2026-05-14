#include "funkcijos.h"
#include "library.h"
#include "patikrinimai.h"

int main() {
    std::string input;

    while (true) {
        std::cout << "Pasirinkite konteineri: 1 - vector, 2 - list, 3 - deque, 4 - mano vektorius: ";
        if (!read_input(input)) {
            return 0;
        }

        const int choice = validation(input);
        if (choice == 1) {
            return run_program<VectorContainer>("vector");
        }
        if (choice == 2) {
            return run_program<ListContainer>("list");
        }
        if (choice == 3) {
            return run_program<DequeContainer>("deque");
        }
        if (choice == 4) {
            return run_program<MyVectorContainer>("MyVector");
        }

        std::cout << "Iveskite tinkama sk!" << std::endl;
    }
}
