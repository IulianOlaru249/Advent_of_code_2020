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
	bool valid_iyr (int iyr) {
		if (iyr >= 2010 && iyr <= 2020)
			return true;
		return false;
	}

	bool valid_eyr (int eyr) {
		if (eyr >= 2020 && eyr <= 2030)
			return true;
		return false;
	}

	bool valid_byr (int byr) {
		if (byr >= 1920 && byr <= 2020)
			return true;
		return false;
	}

	bool valid_ecl (string ecl) {
		if (ecl.compare("amb") == 0)
			return true;
		if (ecl.compare("blu") == 0)
			return true;
		if (ecl.compare("brn") == 0)
			return true;
		if (ecl.compare("gry") == 0)
			return true;
		if (ecl.compare("grn") == 0)
			return true;
		if (ecl.compare("hzl") == 0)
			return true;
		if (ecl.compare("oth") == 0)
			return true;
		return false;
	}

	bool valid_hcl (string hcl) {
		if (hcl[0] != '#')
			return false;

		int hcl_size = hcl.size();
		for (int i = 1; i < hcl_size; i++) {
			if ((hcl[i] - '0' < 0 || hcl[i] - '0' > 9 ) && (hcl[i] - 'a' < 0 || hcl[i] - 'a' > 102)) {
				cout << hcl[i] << endl;
				return false;
			}
		}
		return true;
	}

	bool valid_pid (string pid) {
		if (pid.size() != 9)
			return false;
		return true;
	}

	bool valid_hgt (string hgt) {
		int hgt_size = hgt.size();
		int h = 0;
		for (int i = 0; i < hgt_size; i++) {
			if (hgt[i] - '0' >= 0 && hgt[i] - '0' <= 9 ) {
				h = h * 10 + hgt[i] - '0';
			}
			if (hgt[i] == 'c') {
				if (h >= 150 && h <= 193)
					return true;
			}
			if (hgt[i] == 'i') {
				if (h >= 59 && h <= 76)
					return true;
			}
		}
		return false;
	}
	
    	void read_input()
	{
		int count = 0;
		passports.push_back(map <string, string>());
    		string str;
		ifstream fin("data.in");
		while (!fin.eof() ) {
    			getline(fin, str);
			if(str.length() == 0) {
				passports.push_back(map <string, string>());
				count ++;
			}
			else {
				stringstream check1(str);
				string token;
				while(getline(check1, token, ' '))
    				{
					stringstream check2(token);
					pair<string, string> subToken;
					getline(check2, subToken.first, ':');
					getline(check2, subToken.second, ':');
					
					passports[count].insert(subToken);
    				}
			}
		}
        	fin.close();
    	}

    	int get_result()
	{
		int valid = 0;


		for (auto passport : passports) {

			int pass_size = passport.size();
			if ( pass_size == 8 || (pass_size == 7 && passport.find("cid") == passport.end())) {
				int byr = stoi( passport.find("byr")->second);
				int iyr = stoi( passport.find("iyr")->second);
				int eyr = stoi( passport.find("eyr")->second);
				string hgt = passport.find("hgt")->second;
				string hcl = passport.find("hcl")->second;
				string ecl = passport.find("ecl")->second;
				string pid = passport.find("pid")->second;
				if (valid_byr(byr) && valid_iyr(iyr) && valid_eyr(eyr) && valid_ecl(ecl) && valid_hcl(hcl) && valid_pid(pid) && valid_hgt(hgt)) {
					valid++;
				}
			}
		}
		return valid;
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
