/*
Input

The first line of input gives the number of cases, N. N test cases follow. For each test case there will be:

One line containing the value C, the amount of credit you have at the store.
One line containing the value I, the number of items in the store.
One line containing a space separated list of I integers. Each integer P indicates the price of an item in the store.
Each test case will have exactly one solution.

Output

For each test case, output one line containing "Case #x: " followed by the indices of the two items whose price adds up to the store 
credit. The lower index should be output first.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;

void buying(ofstream& output, const vector<int>& prices, const unordered_map<int, int>& copy, int money, int aCase) {
	//go through vector, for each item, check hash table to see if there's a complement
	//if there's a complement, output result and break out of loop
	//else keep going through the vector
	//error checking at the end
	//should be O(n)
	for (int i = 0; i < prices.size(); i++) {
		unordered_map<int, int>::const_iterator item = copy.find(money - prices[i]);
		if (item != copy.end()) {
			if (i < item->second) {
				output << "Case #" << aCase << ": " << i + 1 << " " << item->second + 1 << endl;
			}
			else {
				output << "Case #" << aCase << ": " << item->second + 1 << " " << i + 1 << endl;
			}
			return;
		}
	}
	cerr << "Something's wrong, my frand" << endl;
}

void inventory(ifstream& input, ofstream& output) {
	//for every case, get money amount and put all the items in a vector and a hash table
	//call buying to figure out which 2 items add up to the money given
	vector<int> prices;
	unordered_map<int, int> copy;
	int cases;
	int money;
	int numItem;
	int item;
	input >> cases;
	for (int i = 1; i <= cases; i++) {
		input >> money >> numItem;
		for (int j = 0; j < numItem; j++) {
			input >> item;
			prices.push_back(item);
			copy[item] = j; //item becomes the key, and the value is the index in the vector
		}
		buying(output, prices, copy, money, i);
		prices.clear();
		copy.clear();
	}
}

int main() {
	ifstream input;
	input.open("A-large-practice.in");
	if (!input) {
		cerr << "Cannot open file";
		exit(0);
	}
	ofstream output;
	output.open("output.txt");
	inventory(input, output);
	input.close();
	output.close();
}
