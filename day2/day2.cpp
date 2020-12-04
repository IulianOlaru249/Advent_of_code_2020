#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Task {

	int valid_pwds = 0;

public:
    	void solve()
	{
        	read_input();
		print_output(0);
    	}

 private:
	
    	void read_input()
	{
    		string range;
    		string chr;
    		string pwd;
        	ifstream fin("data.in");
		while (true) {
    			fin >> range;
    			fin >> chr;
    			fin >> pwd;

			int inf, sup;
			vector <string> tokens; 
			stringstream check1(range);
			string intermediate;
			while(getline(check1, intermediate, '-')) 
    			{ 
				tokens.push_back(intermediate);
    			}

        		inf = stoi(tokens[0]); 
        		sup = stoi(tokens[1]); 

			char c = chr[0];

			get_result (pwd, c, sup, inf);

    			if( fin.eof() ) break;
		}
        	fin.close();
    	}

    	int get_result(string pwd, char c, int sup, int inf)
	{

		if ((pwd[inf - 1] == c ) ^ (pwd[sup - 1] == c))
			valid_pwds++;

		/* PART 1
		int apar = 0;
		int size = pwd.length();
		for (int i = 0; i < size; i++)
			if (pwd[i] == c)
				apar ++;
			
		if (inf <= apar && sup >= apar) {
			valid_pwds++;
		}
		*/
		return 0;
    	}

    	void print_output(int result) 
	{
        	cout << valid_pwds << endl;
    	}
};

int main()
{
	Task *task = new Task();
    	task->solve();
    	delete task;
    	return 0;
}
