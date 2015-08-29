#include <iostream>
#include <string>

using namespace std;

int main() {
	int base;
	string input;
	cin >> input >> base;
	int noInt = 0;
	float noDecimal = 0;
	bool isFloat = false;
	
	if (input.find('.') == string::npos) //check if input not contains dot(.)
	{
		int multiply = 1;
		for (int i = input.size() - 1; i >= 0; i--) {
			noInt = noInt + (int)(input[i] - '0') * multiply;
			multiply = multiply * 10;
		}
	}
	else //input contains dot(.)
	{
		int dotPosition = input.find('.');
		int multiply = 1;
		for (int i = input.size() - 1; i > dotPosition; i--) {
			noDecimal = noDecimal + (int)(input[i] - '0') * multiply;
			multiply = multiply * 10;
		}
		multiply = 1;
		for (int i = dotPosition - 1; i >= 0; i--) {
			noInt = noInt + (int)(input[i] - '0') * multiply;
			multiply = multiply * 10;
		}
		isFloat = true;
	}

	bool flag = true;
	string result = "";
	while(flag)//process full number
	{
		flag = false;
		if (base <= 10) {
			if (noInt != 0) {
				result = to_string(noInt%base) + result;
				noInt = noInt / base;

				flag = true;
			}
		}
		else {
			if (noInt != 0) {
				int x = noInt%base;
				if (x < 10) {
					result = to_string(x) + result;
				}
				else {

					char alphabet = 'A';
					alphabet = alphabet + (x - 10);
					result = alphabet + result;
				}
				
				noInt = noInt / base;

				flag = true;
			}
		}
	}
	if (isFloat) {//process float
		float decimal = noDecimal;
		while (decimal > 1)
			decimal = decimal * 0.1;
		flag = true;
		string decResult = "";
		while (flag)
		{
			flag = false;
			if (decimal != 0) {
				decimal = base * decimal;
				int x = decimal;
				for (int i = 0; i < base; i++)
				{
					if (x % base == i) {
						if (i < 10)
							decResult = decResult + to_string(i);
						else {
							char alphabet = 'A';
							alphabet = alphabet + (i - 10);
							result = result + alphabet;
						}
						decimal = decimal - x;
						break;
					}
				}
				flag = true;
			}
		}
		result = result + '.' + decResult;

	}
	cout << result << endl;
	return 0;
}