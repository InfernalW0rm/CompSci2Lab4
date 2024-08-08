#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

using namespace std;

class FileNotFoundException : public exception 
{
public:
    const char* what() const noexcept override 
    {
        return "File not found.";
    }
};

class ColorFileFormatException : public exception 
{

public:
    const char* what() const noexcept override 
    {
        return "Color file format is incorrect.";
    }
};

class CoordinateOutOfRangeException : public exception 
{
public:
    const char* what() const noexcept override 
    {
        return "Coordinate out of range.";
    }
};

class ColorVectorOutOfRangeException : public exception 
{
    string message;

public:
    ColorVectorOutOfRangeException(const string& msg) : message(msg) {}

    const char* what() const noexcept override 
    {
        return message.c_str();
    }
};
#endif
