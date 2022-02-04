#include "Executive.h"

int main(int argc, char* argv[]) {
    //run game: ./prog {# of ships}
    if (argc != 2) std::cout << "Invalid number of parameters\n";
	else if(atoi(argv[1]) < 1 || atoi(argv[1]) > 5) std::cout << "Invalid number of ships!\n";
	else
	{
        int numShips = atoi(argv[1]);
        Executive exec(numShips);
        exec.run();
    }

    return 0;
}
