#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class fileRead
{
	private:
		ifstream ifs;//read from file
		ofstream ofs;//write to file
		string line; //temporary line holder
	public:
		void exam()
		{
			int temp_reg;
			float av_score;
			cout << "Enter Reg No: ";
			cin >> temp_reg;
			auto foundLine = searchLine(std::to_string(temp_reg));
			cout << "Details: " << foundLine << std::endl;
                        cout << "\n\n\tEnter  students' Average Score: ";
			cin >> av_score;
			appendToFile(foundLine , std::to_string(av_score));
		}
		void appendToFile(string  conLine , string Data)
		{
			ifs.open("studentsData.txt");
			ofs.open("studentsExam.txt");
			if(!ifs.is_open())
			{
				cerr << "The file could not open for file reading" << endl;
				exit(-1);
			}
			else
			{
				while(getline(ifs ,line))
				{
					if(line == conLine)
					{
						line +="	" + Data;//add the data to the line
					}
				       	ofs << line << "\n";
				}
			}
			ifs.close();
			ofs.close();
		}
		string searchLine(string searchKey)
		{
			ifs.open("studentsData.txt");
			if(!ifs.is_open())
			{
				cerr << "File Not open " << endl;
				exit(-1);
			}
			string find_line , return_line;
			while(getline(ifs,find_line))
			{
				if(find_line.find(searchKey , 0) != string::npos)
				{
					return_line = find_line;
				}
				else
				{
					continue;
				}

			}
			ifs.close();
			return return_line;
		}
};
int main()
{
	fileRead re;
	re.exam();
	return 0;
}

