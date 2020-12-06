#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Task {

	vector<map <string, string>> passports;

public:
    	void solve()
	{
        	read_input();
        	print_output(get_result());
    	}

 private:
	int count = 0;
		
    	void read_input()
	{
    		string str;
		int member = 0;
		vector<int> apar (123, 0);
		ifstream fin("data.in");
		while (!fin.eof() ) {
    			getline(fin, str);
			if(str.length() == 0) {
				for (int i = 97; i < 123; i++)
					if (apar[i] == 1) {
						count ++;
						apar[i] = 0;
				}
				member = 0;
				break;
			}
			else {
				cout << str << endl;
				int len = str.length();
				/* Part 1 */
				for (int i = 0; i < len; i++) {
					apar[str[i]] = 1;
				}
				/* Part 2 */
				}
				cout << endl;
			}
		}
        	fin.close();
    	}

    	int get_result()
	{

		return count;
    	}

    	void print_output(int result) 
	{
		cout << result << endl;	
		
    	}
};

int main()
{
	Task *task = new Task();
    	task->solve();
    	delete task;
    	return 0;
}
