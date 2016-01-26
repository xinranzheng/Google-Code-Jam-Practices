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

#include <iostram>
#include <fstream>
#include <vector>
#include <unordered_map>
using namspace std;

void buying(const vector<int>& prices, const unordered_map<int, int>& copy, int money, int case) {
	//go through vector, for each item, check hash table to see if there's a complement
	//if there's a complement, output result and break out of loop
	//else keep going through the vector
	//error checking at the end
	//should be O(n)
	for (int i = 0; i < prices.size(); i++) {
		unordered_map<int, int>::const_iterator item = copy.find(money - prices[i]);
		if (item != copy.end()) {
			if (i < item->second) {
				cout << "Case #" << case << ": " << i << " " << item->second << endl;
			}
			else {
				cout << "Case #" << case << ": " << item->second << " " << i << endl;
			}
			break;
		}
	}
	cerr << "Something's wrong, my frand";
}

void inventory(ifstream& input) {
	//for every case, get money amount and put all the items in a vector and a hash table
	//call buying to figure out which 2 items add up to the money given
	vector<int> prices;
	unordered_map<int, int> copy;
	int cases;
	int money;
	int numItem;
	int item;
	int vector<int> items;
	input >> cases;
	for (int i = 1; i <= cases; i++) {
		input >> money >> numItem;
		for (int j = 0; j < numItem; j++) {
			input >> item;
			items.push_back(item);
			copy[item] = j; //item becomes the key, and the value is the index in the vector
		}
		buying(prices, copy, money, i);
	}
}

int main() {
	ifstream input;
	input.open("A-small-practice.in");
	if (!input) {
		cerr << "Cannot open file";
		exit(0);
	}
	inventory(input);
}
