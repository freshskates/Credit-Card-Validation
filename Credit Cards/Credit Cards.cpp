#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
using namespace std;

bool isvalidcc(const string&);

int main()
{
	//
	// PLEASE DO NOT CHANGE function main
	//
	vector<string> cardnumbers = {
	"371449635398431", "4444444444444448", "4444424444444440", "4110144110144115",
		"4114360123456785", "4061724061724061", "5500005555555559", "5115915115915118",
		"5555555555555557", "6011016011016011", "372449635398431", "4444544444444448",
		"4444434444444440", "4110145110144115", "4124360123456785", "4062724061724061",
		"5501005555555559", "5125915115915118", "5556555555555557", "6011116011016011",
		 "372449635397431", "4444544444444448", "4444434444544440", "4110145110184115",
		"4124360123457785", "4062724061724061", "5541005555555559", "5125115115915118",
		"5556551555555557", "96011316011016011"
	};
	int i;
	vector<string>::iterator itr;

	for (i = 1, itr = cardnumbers.begin(); itr != cardnumbers.end(); ++itr, i++) {
		cout << setw(2) << i << " "
			<< setw(17) << *itr
			<< ((isvalidcc(*itr)) ? " is valid" : " is not valid") << endl;
	}

	return 0;
}


vector<string> valid_cards = { "4", "5", "37", "6" };
bool check_valid_start(const string& s) {
	for (auto& x : valid_cards) if (s.substr(0, 2).find(x) == 0) return true;
	return false;
}

bool cardinfo(const string& s) {
	int count = 0; 
	for_each(s.rbegin(), s.rend(), [i = 0, &count](auto& a) mutable -> void {
		int x = int(a) - '0';
		if (i++ % 2) count += x * 2 < 10 ? x * 2 : (x * 2) % 10 + (x * 2) / 10;
		else count += x;
	});
	return !(count % 10);
}

bool isvalidcc(const string& s) {
	if ((s.length() < 13 && s.length() > 16) || !check_valid_start(s)) return false;
	return cardinfo(s);
}
