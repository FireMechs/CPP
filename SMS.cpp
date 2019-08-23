#include <iostream>
#include <fstream>
#include <string>
//#include <experimental/filesystem>//not available in windows

using namespace std;

class students
{
	private:
		string name;
		 string	county;
		int reg , age , birthcert;
		long int phone_no;
		ofstream ofs;
		ifstream ifs; // reads the file
	public:
		students()
		{
			ofs.open("studentsDataTemp.txt");
			if(!ofs.is_open())
			{
				cerr << "The file could not be opened/created" << endl;
				exit(-1);
			}
		}
		void admit()
		{
			cin.ignore(256,'\n');
			cout << " Name:  " ;
			getline(cin , name );
			cout << " Age:  " ;
			cin >> age;
			cout << " Reg. NO:  ";
			cin >>  reg;
			cout << " Birth Cert. No:  ";
			cin >> birthcert;
			cout << " Phone NO: " ;
			cin >> phone_no;
			cout << " county: " ;
			cin >> county;
                        write_to();
			char ch;
			cout << " Another student(y/n): " ;
			cin >> ch;
			if(ch == 'Y' ||  ch == 'y')
			{
				admit();
			}
			else
			{
			}
		}
		void write_to()
		{
		   if(ofs.is_open())
                   	ofs << name << "	" << std::to_string(age) << "	" << std::to_string(reg) << "	" << std::to_string(birthcert) << "	" << std::to_string(phone_no) << "	" << county <<"\n";

		}
		void exam()
		{
		      int  temp_reg;
		      cout << " Enter Reg. No: " ;
		      cin  >> temp_reg;
		      cout << "Details: " << searchLine(std::to_string(temp_reg)) << endl;
		}
		string  searchLine(string search_key)/*searches the file*/
		{
		       ifs.open("studentsData.txt");
	                if(!ifs.is_open())
			{
		           cerr << "File not open " << endl;
	                   exit(-1);
			}
	                string find_line  , return_line;
			while(getline(ifs , find_line))
			{
				if(find_line.find(search_key , 0) != string::npos)
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
		      ~students()
		      {
			 ofs.close();
                         ifs.open("studentsDataTemp.txt");
			 ofs.open("studentsData.txt" , std::ios::app);
			 if(!ifs.is_open() && !ofs.is_open())
			 {
				 cerr << "Error , files could not be opened" << endl;
				 exit(-1);
			 }
			 ofs << ifs.rdbuf();
			 ofs.close();
			 ifs.close();
			 std::remove("studentsDataTemp.txt");
		      }
};
int main()
{
	students stud;

	cout << "\t\t\t\tSMS " << endl;
        cout << "\t\t 1 . Admit " << endl;
        cout << "\t\t 2 . Exam " << endl;
        cout << "\n\n\n " << endl;
        cout << "choose .. : " ;
	int select;
        cin >> select;
        switch(select)
	{
		case 1:
			stud.admit();
			break;
		case 2:
                       stud.exam();
		       break;
		default:
		       cerr << "Choice not available at this instant " << endl;
		       break;
	}
        stud.~students();
	return 0;
}
