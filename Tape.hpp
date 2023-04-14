#ifndef TAPE_HPP_
#define TAPE_HPP_

#include <cstdio>
#include <iostream>
#include "ITape.hpp"

class Tape: public ITape {
    public:
        int curElem;
        int curIndex;
        FILE* date;
        int size;
    public:
        Tape(char* inputFileName):
            curElem(0),
            curIndex(0),
            date(NULL),
            size(0)
            {
                date = fopen(inputFileName, "r+");
                do {
                    size++;
                } while (shift(true) != 0);
            }
        int readElem() override;
        int shift(bool isRight) override;
        void writeElem(int value) override;
        ~Tape() { fclose(date); }
};

#endif // TAPE_HPP_
