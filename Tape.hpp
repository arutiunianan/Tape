#ifndef TAPE_HPP_
#define TAPE_HPP_

#include <cstdio>
#include <iostream>
#include "ITape.hpp"

class Tape: public ITape {
    public:
        int curElem_;
        int curIndex_;
        FILE* data_;
        int size_;
    public:
        Tape(char* fileName):
            curElem_(0),
            curIndex_(0),
            data_(NULL),
            size_(0)
            {
                data_ = fopen(fileName, "r+");
                while (shiftRight()) {
                    size_++;
                }
                if (fgetc(data_) != EOF)
                    size_++;
                fseek(data_, 0, SEEK_SET);
            }

        Tape(char* fileName, int size):
            curElem_(0),
            curIndex_(0),
            data_(NULL),
            size_(size)
            {
                clearFile(fileName);
                data_ = fopen(fileName, "r+");
            }

        Tape(char* fileName, int size, int elem):
            curElem_(0),
            curIndex_(0),
            data_(NULL),
            size_(size)
            {
                clearFile(fileName);
                data_ = fopen(fileName, "r+");
                for (int i = 0; i < size; i++) {
                    writeElem(elem);
                    shiftRight();
                }
                rewindLeft();
            }

        int readElem() override;

        int shiftRight() override;

        int rewindRight() override { return -1; }

        int shiftLeft() override { return -1; }

        int rewindLeft() override;

        void writeElem(int value) override;

        ~Tape() { fclose(data_); }
    private:
        void clearFile(char* fileName) {
            FILE* file = fopen(fileName, "w");
            fclose(file);
        }
};

#endif // TAPE_HPP_
