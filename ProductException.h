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

// для id

class ProductIncorrectIdException : public ProductException
{
public:
    ProductIncorrectIdException(const std::string error) noexcept : ProductException(error) { std::cout << "id  " << std::endl; }

    ~ProductIncorrectIdException() {}
};

// для имени

class ProductIncorrectNameException : public ProductException
{
public:
    ProductIncorrectNameException(const std::string error) noexcept : ProductException(error) { std::cout << "  name  " << std::endl; }

    ~ProductIncorrectNameException() {}
};

// для ценника

class ProductIncorrectPriceException : public ProductException
{
public:
    ProductIncorrectPriceException(const std::string error) noexcept : ProductException(error) { std::cout << "  price  " << std::endl; }

    ~ProductIncorrectPriceException() {}
};

// для поставщика

class ProductIncorrectPlugException : public ProductException
{
public:
    ProductIncorrectPlugException(const std::string error) noexcept : ProductException(error) { std::cout << " plug  " << std::endl; }

    ~ProductIncorrectPlugException() {}
};

enum plugs
{
    SLAY,
    FSTAGE,
    OLEG,
    BOB
};

#endif