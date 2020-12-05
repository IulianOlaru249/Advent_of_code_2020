#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define max_rows 127
#define max_cols 7

using namespace std;

class Task {

    	vector<string> data; 

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
		while (!fin.eof() ) {
    			string x;
    			fin >> x;
			//cout << x << endl;
			data.push_back(x);
		}
        	fin.close();
    	}

	void get_seat_row(string ticket_code, int index, int front, int back, int *result)
	{
		if (index == 6) {
			if (ticket_code[index] == 'B') {
				*result = back;
				return;
			}
			if (ticket_code[index] == 'F') {
				*result = front;
				return;
			}
		}


		if (ticket_code[index] == 'B')
			get_seat_row(ticket_code, ++index, 1 + (front + back) / 2, back, result);
		else if (ticket_code[index] == 'F')
			get_seat_row(ticket_code, ++index, front, (front + back) / 2, result);
	}

	void get_seat_col(string ticket_code, int index, int front, int back, int *result)
	{
		if (index == 2) {
			if (ticket_code[index] == 'R') {
				*result = back;
				return;
			}
			if (ticket_code[index] == 'L') {
				*result = front;
				return;
			}
		}


		if (ticket_code[index] == 'R')
			get_seat_col(ticket_code, ++index, 1 + (front + back) / 2, back, result);
		else if (ticket_code[index] == 'L')
			get_seat_col(ticket_code, ++index, front, (front + back) / 2, result);
	}


    	int get_result()
	{
		int row, col;
		vector<long> ids;
		long max_id = INT_MIN;
		for (string s : data) {
			row = 0;
			col = 0;

			get_seat_row (s, 0, 0, max_rows, &row);
			get_seat_col (&s[7], 0, 0, max_cols, &col);

			long id = row * 8 + col;

			/* Part 1*/
			if (id >= max_id)
				max_id = id;

			/* Part 2*/
			ids.push_back(id);
		}

		sort(ids.begin(), ids.end());
		for (int i = 0; i < ids.size() - 1; i++)
			if (ids[i + 1] - ids[i] > 1) {
				cout << ids[i] + 1 << endl;
			}

		return max_id;
    	}

    	void print_output(int resust) 
	{
		cout << resust << endl;
    	}
};

int main()
{
	Task *task = new Task();
    	task->solve();
    	delete task;
    	return 0;
}
