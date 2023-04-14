#include <cstdio>
#include "Tape.hpp"

int Tape::readElem() {
    fscanf(Tape::date, "%d", &(Tape::curElem));
    return Tape::curElem;
}

int Tape::shift(bool isRight) {
    int sym = 0;
    while((sym = fgetc(Tape::date)) != ' ') {
        if (sym == EOF) {
            fseek(Tape::date, 0, 0);
            Tape::curIndex = 0;
            return Tape::curIndex;
        }
    }
    Tape::curIndex++;

    return Tape::curIndex;
}

void Tape::writeElem(int value) {
    fprintf(Tape::date, "%d ", value);
}
