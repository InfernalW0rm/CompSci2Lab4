#include "Picture.h"
#include "FileReader.h"
#include "Exceptions.cpp"
#include <iostream>

using namespace std;

int main() 
{
	const string filename = "picture.txt";
	const int width = 50;
	const int height = 20;

	Picture picture(width, height);

	try 
	{
		readColorsFromFile(filename, picture);
		cout << picture;
	}
	catch (const FileNotFoundException& e) 
	{
		cout << e.what() << endl;
	}
	catch (const ColorFileFormatException& e) 
	{
		cout << e.what() << endl;
	}
	catch (const exception& e) 
	{
	cout << "An unexpected error occurred: " << e.what() << endl;
	}
	
	cout << endl << endl;
	cout << "|| STAT TOOLS ADVANCED ||" << endl;



	return 0;
}