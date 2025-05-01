#ifndef _PRODUCT_EXCEPTION_H_
#define _PRODUCT_EXCEPTION_H_

#include <exception>
#include <string>

class ProductException : public std::exception
{
private:
    std::string msg;

public:
    ProductException(const std::string error) noexcept : msg(error) {}

    const char *what() const noexcept override { return msg.data(); } // override контролирует синтаксис наследуемого дочерним классом виртуального метода

    virtual ~ProductException() {}
};

class ProductIncorrectIdException : public ProductException
{
public:
    ProductIncorrectIdException(const std::string error) noexcept : ProductException(error) {}

    ~ProductIncorrectIdException() {}
};

enum plugs
{
    SLAY,
    FSTAGE,
    OLEG,
    BOB
};

#endif