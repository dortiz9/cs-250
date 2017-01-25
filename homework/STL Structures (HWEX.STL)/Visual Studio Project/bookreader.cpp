/*
* Author: Danny Ortiz
* STL Structures (HWEX.STL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "Page.hpp"

void LoadPages(vector<Page>& pages, const string& filename)
{
	ifstream input(filename);
	string line;
	string pageText = "";
	int lineCount = 0;
	int pageCount = 0;
	Page addPage;

	while (getline(input, line))
	{
		pageText = pageText + "\n" + line;

		lineCount++;
		if (lineCount == 27)
		{

			// Add page to book now
			addPage.text = pageText;
			pages.push_back(addPage);
			pageCount++;

			// Reset the page text
			pageText = "";

			// Reset the line count
			lineCount = 0;
		}

	}

	input.close();
}

void ReadBook(vector<Page>& pages)
{
	int currentPage = 0;
	int totalPages;

	bool done = false;
	totalPages = pages.size();
	while (!done)
	{
		pages[currentPage].Display();
		cout << "--- PAGE " << currentPage + 1 << " OF " << totalPages << "---------------------------------" << endl;
		cout << "(N)ext Page, (P)revious Page, (Q)uit" << endl;
		cout << ">> ";
		string choice;
		cin >> choice;

		if (choice == "Q" || choice == "q") 
		{ 
			done = true; 
		}
		else if (choice == "N" || choice == "n")
		{
			if (currentPage + 1 < totalPages)
			{
				currentPage++;
			}
		}
		else if (choice == "P" || choice == "p")
		{
			if (currentPage - 1 >= 0)
			{
				currentPage--;
			}
		}
	}
}

int main()
{

	vector<Page> pages;

	LoadPages(pages, "Aesop.txt");
	ReadBook(pages);

	return 0;
}