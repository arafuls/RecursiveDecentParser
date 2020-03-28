#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

/* - - - Globals - - - */
string line;	// Current line we are parsing
int index;		// For accessing our line

/* - - - Prototypes - - - */
bool A();
bool E();
bool O();
bool P();
bool U();
bool I();
bool C();
bool L();
bool D();

/* - - - Main - - - */
int main(int argc, char *argv[])
{
	// Input File
	ifstream file;
	file.open("input.txt");

	// Output File
	ofstream outfile;
	outfile.open("output.txt");

	if (!file)
	{
		std::cerr << "[ERROR] Could not open input file!\n";
		exit(EXIT_FAILURE);
	}

	while (!file.eof())
	{
		getline(file, line);
		index = 0; // Re-init index to 0 for each new line to be parsed

		string s = "'" + line + "' ";
		cout << right << setw(20) << s;

		string outputText = "The string \"" + line + "\" ";
		outfile << outputText;

		/* NOTE
			Changing the order of this if-statement will cause improper parsing.
			A() MUST BE called before checking index against line.length!
		*/
		if (A() && index == line.length())
		{
			cout << "exists within our language." << endl;
			outfile << "is in the language.\n";
		}
		else
		{
			cout << "DOES NOT exist within our language." << endl;
			outfile << "is not in the language.\n";
		}
	}

	file.close();
	outfile.close();
	//system("pause");
	return 0;
}

/* - - - FUNCTIONS - - - */
bool A() 
{
	if (I())
	{
		if (index < line.length() && line[index] == '=')
		{
			index++;

			if (E())
			{
				return true;
			}
		}
	}

	index = 0;
	if (E())
	{
		return true;
	}

	return false;
}


bool E()
{
	if (P())
	{
		while (O())
		{
			if (!P())
			{
				return false;
			}
		}
		return true;
	}

	return false;
}


bool O()
{
	if (index < line.length()  && (line[index] == '+' || line[index] == '-' || line[index] == '/' 
		|| line[index] == '*'))
	{
		index++;
		return true;
	}
	else if (index < line.length() && line[index] == '*')
	{
		index++;
		if (index < line.length() && line[index] == '*')
		{
			index++;
			return true;
		}
	}

	return false;
}


bool P()
{
	if (I() || L())
	{
		return true;
	}
	else if (U())
	{
		if (I() || L())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (index < line.length() && line[index] == '(')
	{
		index++;
		if (E())
		{
			if (index < line.length() && line[index] == ')')
			{
				index++;
				return true;
			}
		}
	}

	return false;
}


bool U()
{
	if (index < line.length() &&  (line[index] == '+' || line[index] == '-' || line[index] == '!'))
	{
		index++;
		return true;
	}

	return false;
}


bool I()
{
	if (C())
	{
		//index++;
		if (I())
		{
			return true;
		}
		else
		{
			return true;
		}
	}

	return false;
}


bool C()
{
	if (index < line.length() && line[index] >= 'a' && line[index] <= 'z')
	{
		index++;
		return true;
	}

	return false;
}


bool L()
{
	if (D())
	{
		if (L())
		{
			return true;
		}
		else {
			return true;
		}
	}
	else 
	{ 
		return false; 
	}
}


bool D()
{
	if (index < line.length() && line[index] >= '0' && line[index] <= '9') {
		index++;
		return true;
	}

	return false;
}