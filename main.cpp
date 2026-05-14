#include "funkcijos.h"
#include "library.h"
#include "patikrinimai.h"

void wait_before_exit() {
    std::cout << "Spauskite Enter, kad uzdarytumete programa...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

int main() {
    std::string input;

    while (true) {
        std::cout << "Pasirinkite konteineri: 1 - vector, 2 - list, 3 - deque, 4 - mano vektorius: ";
        if (!read_input(input)) {
            return 0;
        }

        const int choice = validation(input);
        if (choice == 1) {
            const int result = run_program<VectorContainer>("vector");
            wait_before_exit();
            return result;
        }
        if (choice == 2) {
            const int result = run_program<ListContainer>("list");
            wait_before_exit();
            return result;
        }
        if (choice == 3) {
            const int result = run_program<DequeContainer>("deque");
            wait_before_exit();
            return result;
        }
        if (choice == 4) {
            const int result = run_program<MyVectorContainer>("myVector");
            wait_before_exit();
            return result;
        }

        std::cout << "Iveskite tinkama sk!" << std::endl;
    }
}
