#include <iostream>
#include <string>
#include <cassert>

#include "algorithms.hpp"

using namespace std;

void IndexOfTests() {
	cout << "IndexOf tests: ";

	string s = "abcdefghijklmnopqrstuvwxyzqwertyuiopasdfghjklzxcvbnm";
	string s1 = s;
	string s2 = s.substr(26);
	string s3 = s.substr(1);
	string s4 = s.substr(13);
	string s5 = s.substr(20);
	string s6 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

	assert(IndexOfNaive(s, s1) == 0);
	assert(IndexOfNaive(s, s2) == 26);
	assert(IndexOfNaive(s, s3) == 1);
	assert(IndexOfNaive(s, s4) == 13);
	assert(IndexOfNaive(s, s5) == 20);
	assert(IndexOfNaive(s, s6) == -1);

	assert(IndexOfKnutMorrisPratt(s, s1) == 0);
	assert(IndexOfKnutMorrisPratt(s, s2) == 26);
	assert(IndexOfKnutMorrisPratt(s, s3) == 1);
	assert(IndexOfKnutMorrisPratt(s, s4) == 13);
	assert(IndexOfKnutMorrisPratt(s, s5) == 20);
	assert(IndexOfKnutMorrisPratt(s, s6) == -1);

	assert(IndexOfRabinKarp(s, s1) == 0);
	assert(IndexOfRabinKarp(s, s2) == 26);
	assert(IndexOfRabinKarp(s, s3) == 1);
	assert(IndexOfRabinKarp(s, s4) == 13);
	assert(IndexOfRabinKarp(s, s5) == 20);
	assert(IndexOfRabinKarp(s, s6) == -1);

	cout << "OK" << endl;
}

int main() {
	IndexOfTests();
}