#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Task {

    	vector<string> data; 

public:
    	void solve()
	{
        	read_input();
        	print_output();
    	}

 private:
	
    	void read_input()
	{
		int count;
        	ifstream fin("data.in");
		while (!fin.eof() ) {
    			string x;
    			fin >> x;
			data.push_back(x);
		}
        	fin.close();
    	}

    	void get_result(int x, int y, int slopeX, int slopeY, int *res)
	{
		if (x >= data.size())
			return ;

		if (y >= data[x].length())
			y -= data[x].length();

		if (data[x][y] == '#')
			*res = *res + 1;

		get_result(x + slopeX, y + slopeY, slopeX, slopeY, res);
    	}

    	void print_output() 
	{
		long final_res = 1;
		int res;
		for (int i = 1; i < 8; i += 2) {
			res = 0;
			get_result(0, 0, 1, i, &res);
			final_res *= res;
			cout << i << ":" << res << endl;
		}
		res = 0;
		get_result(0, 0, 2, 1, &res);
		cout << res << endl;
		final_res *= res;
		cout << final_res << endl;
    	}
};

int main()
{
	Task *task = new Task();
    	task->solve();
    	delete task;
    	return 0;
}
