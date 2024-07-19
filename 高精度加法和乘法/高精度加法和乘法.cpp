#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

class big_int
{
public:
	big_int() :integer("\0") {}

	big_int(string num):integer(num)
	{
		reverse(integer.begin(), integer.end());
	}

	big_int operator+(big_int& num)
	{
		string result;
		int max_size = max(this->integer.size(), num.integer.size());
		int remnant = 0;//进数
		
		

	}

private:
	string integer;


};


int main()
{
	
	return 0;
}
