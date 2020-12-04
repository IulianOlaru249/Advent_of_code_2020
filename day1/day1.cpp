#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Task {

    	vector<int> data; 

public:
    	void solve()
	{
        	read_input();
        	print_output(get_result());
    	}

 private:
	
    	void read_input()
	{
        	ifstream fin("data.in");
		while (true) {
    			int x;
    			fin >> x;
			data.push_back(x);
    			if( fin.eof() ) break;
		}
        	fin.close();
    	}

    	int get_result()
	{
		int size = data.size();
		for (auto i = data.begin(); i != data.end()--; ++i)
			for (auto j = i; j != data.end(); ++j)
				for (auto k = j; k != data.end(); ++k)
					if (*i + *j + *k == 2020) {
						cout << *i << " " << *j << " " << *k << endl;
						return ( *i * *j * *k);
					}
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
