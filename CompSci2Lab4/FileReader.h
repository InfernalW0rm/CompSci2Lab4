#ifndef FILEREADER_H
#define FILEREADER_H
#include "Picture.h"
#include "Exceptions.h"
#include <string>
using namespace std;

void readColorsFromFile(const string& filename, Picture& picture);
#endif
