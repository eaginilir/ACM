#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

class big_int
{
public:
	big_int() :integer("") {}

	big_int(string num):integer(num)
	{
		reverse(integer.begin(), integer.end());
	}

	//高精度加法
	big_int operator+(big_int& num)
	{
		string result;
		int max_size = max(this->integer.size(), num.integer.size());
		int remnant = 0;//进数
		
		for (int i = 0; i < max_size || remnant != 0; ++i)
		//确保所有位数和进数都被处理
		{
			int sum = remnant;
			if (i < integer.size())
			{
				sum += integer[i] - '0';
			}
			if (i < num.integer.size())
			{
				sum += num.integer[i] - '0';
			}
			result.push_back('0' + sum % 10);
			remnant = sum / 10;
		}

		reverse(result.begin(), result.end());

		return big_int(result);
	}

	//高精度乘法
	big_int operator*(big_int& num)
	{
		vector<int>result(integer.size() + num.integer.size(), 0);

		for (int i = 0; i < integer.size(); ++i)
		{
			for (int j = 0; j < num.integer.size(); ++j)
			{
				result[i + j] += (integer[i] - '0') * (num.integer[j] - '0');
				if (result[i + j] >= 10)
				{
					result[i + j + 1] += result[i + j] / 10;
					result[i + j] = result[i + j] % 10;
				}
			}
		}

		string result_str;
		bool leading_zero = true;
		for (auto it = result.rbegin(); it != result.rend(); ++it)
		//逆向遍历
		{
			int num = *it;
			if (num == 0 && leading_zero)
			{
				continue;
			}
			leading_zero = false;
			result_str.push_back(num + '0');
		}

		return big_int(result_str.empty() ? "0" : result_str);
	}

	friend ostream& operator<<(ostream& out,const big_int& num)
	{
		string result = num.integer;
		reverse(result.begin(),result.end());
		out << result;
		return out;
	}

private:
	string integer;

};


int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	big_int a(str1), b(str2);
	cout << a << endl;
	cout << b << endl;
	big_int sum = a + b;
	big_int product = a * b;
	cout << sum << endl;
	cout << product << endl;
	return 0;
}
