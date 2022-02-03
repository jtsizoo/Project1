#include "Executive.h"

int main(int argc, char* argv[]) {
    //run game: ./prog {# of ships}
    if (argc != 2) {
        std::cout << "Invalid number of parameters\n";
    } else {
        int numShips = atoi(argv[1]);
        Executive exec(numShips);
        exec.run();
    }

    return 0;
}
