#include <iostream>
#include "Tape.hpp"

int main() {
    Tape* inputTape = new Tape((char*) "inputDate.txt");
    Tape* outputTape = new Tape((char*) "outputDate.txt");
    for (int i = 0; i < inputTape->size; i++) {
        outputTape->writeElem(inputTape->readElem());
        inputTape->shift(true);
    }
    return 0;
}
