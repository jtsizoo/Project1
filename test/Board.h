#ifndef BOARD_H
#define BOARD_H


class Board {
    private:
    int m_size;
    char** placeGrid;
    char** shotGrid;

    public:
    Board(int size);
    ~Board();
    void insertShip(int size, int row, int col, char dir);

};

#endif