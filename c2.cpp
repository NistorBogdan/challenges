#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <string.h>

using namespace std;

bool compareNoCase( const string& s1, const string& s2 ) {
    return strcasecmp( s1.c_str(), s2.c_str() ) <= 0;
}

int main()
{ 
    std::fstream myfile("2.names.random");

	if (myfile.fail()) 
	{
		cout << "Error opening file\n";
	}    

	vector<string> x;
	string tmp;

	while (myfile >> tmp)
	{
		x.push_back(tmp);
	}

	myfile.close();

    sort(x.begin(), x.end(),compareNoCase);

    ofstream output_file("answer.txt");
    ostream_iterator<std::string> output_iterator(output_file, "\n");
    std::copy(x.begin(), x.end(), output_iterator);
}