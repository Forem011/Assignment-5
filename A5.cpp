#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
void countWordFrequencies(const string& inputFile, vector<pair<string, int>>& wordCount)// this is where the word requencies are stored, creates pairs with string (the word) and int (the word count)
{
ifstream file("input.txt");
 if (!file.is_open())// checks if file is opened properly
  {
    cout << "Error opening the file" << endl;
    return;
  }
string word;
while (file >> word)
  {
    string cleanword;
    for (char c : word) //processes each letter in the loop of the current word
      {
	if (isalpha(c))// checks if character is a letter, gets rid of punctuation marks
	  {
	    cleanword += tolower(c);// converts to lowercase 
	  }
      }
    if (!cleanword.empty())
      {
	bool found = false;// checks if word is already in vector
	for (auto& pair : wordCount)
	  {
	    if (pair.first == cleanword)
	      {
		pair.second++;
		found = true;
	      }
	  }
	if (!found)
	  {
	    wordCount.push_back({cleanword, 1});
      }
	cout << "Processing word: " << cleanword << endl; 
      }
  }
	file.close();
}
void writeWordFrequencies(const vector<pair<string, int>>& wordCount, const string& outputFile)
{
  ofstream output_file ("output.txt");
  if (!output_file.is_open())
    {
      cout << "Error opening output file" << endl;
      return;
    }
  for (const auto& pair : wordCount)
    {
      output_file << pair.first << ": " << pair.second << endl;
    }
  output_file.close();
    }
int main()
{
  vector<pair<string, int>> wordCount;
  countWordFrequencies ("input.txt", wordCount);
  writeWordFrequencies (wordCount, "output.txt");
    return 0;
}
      
