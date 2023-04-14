#ifndef ITAPE_HPP_
#define ITAPE_HPP_

class ITape {
    public:
        virtual ~ITape() = default;
        virtual int readElem() = 0;
        virtual int shift(bool isRight) = 0;
        virtual void writeElem(int value) = 0;
};

#endif // ITAPE_HPP_
