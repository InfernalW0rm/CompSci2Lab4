//Andrew Diggs, Merek Mackenzie
//Comp Sci 2 Lab 4

#include "Picture.h"
#include "FileReader.h"
#include "Exceptions.h"
#include "StatTools.h"
#include "PemdasQuizzer.h"
#include <vector>
#include <iostream>

using namespace std;

int main() 
{
	//Picture Problem

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
	
	//Stat Tools Problem

	cout << endl << endl;
	cout << "|| STAT TOOLS ADVANCED ||" << endl;

	vector<int> data = { 1, 2, 2, 3, 4, 4, 4, 5, 6, 7, 8, 9 };

	cout << "Max: " << StatTools<int>::Max(data) << endl;
	cout << "Min: " << StatTools<int>::Min(data) << endl;
	cout << "Mean: " << StatTools<int>::Mean(data) << endl;
	cout << "Mode: " << StatTools<int>::Mode(data) << endl;
	cout << "Median: " << StatTools<int>::Median(data) << endl;

	cout << "\nStem-and-Leaf Plot:\n";
	StatTools<int>::StemAndLeaf(data);

	cout << "\nBar Chart:\n";
	StatTools<int>::BarChart(data);

	//Pemdas Quizzer Problem

	cout << endl << endl;
	cout << "|| PEMDAS QUIZ THAT WORKS ||" << endl;

	int numProblems;
	cout << "How many problems would you like to solve? " << endl;
	cin >> numProblems;

	generateProblem(numProblems);

	return 0;
}