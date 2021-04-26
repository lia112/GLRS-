#include<iostream>
#include<algorithm>
#include<cstring>
#include <random>
#include <chrono>
#include<math.h>
#include<cstdio>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<string>
#include<string.h>
#include<set>
#include<map>
#include<stack>
#include<list>
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using ll = long long;
using namespace std;

class Hash {
private:
	int slot;
	list<int>* table;
public:
	Hash(int s);
	Hash(const Hash& h);
	~Hash();
	int HashFunction_D(int x);
	void Insert(int x);
	void Delete(int key);
	void DisplayHash();
};

Hash::Hash(int s) :slot(s) {
	this->table = new list<int>[slot];
}

Hash::Hash(const Hash& h) {
	this->slot = h.slot;
	this->table = new list<int>[slot];
	for (int i = 0; i < slot; i++)table[i] = h.table[i];
}

Hash::~Hash() {
	delete[] table;
	table = nullptr;
}

int Hash::HashFunction_D(int x) {
	return x % slot;
}

void Hash::Insert(int x) {
	int index = HashFunction_D(x);
	table[index].push_back(x);
}

void Hash::Delete(int key) {
	int index = HashFunction_D(key);
	list<int>::iterator i;
	for (i = table[index].begin(); i != table[index].end(); i++) {
		if (*i == key)break;
	}
	if (i != table[index].end()) {
		table[index].erase(i);
	}
}

void Hash::DisplayHash() {
	for (int i = 0; i < slot; i++) {
		cout << i;
		for (auto x : table[i])cout << "-->" << x;
		cout << endl;
	}
	return;
}

int main() {
	int a[] = { 15,11,27,8,12 };
	int n = sizeof(a) / sizeof(a[0]);
	Hash h(7);
	for (int i = 0; i < n; i++)h.Insert(a[i]);
	h.DisplayHash();
	h.Delete(12);
	h.DisplayHash();
	Hash h2(h);
	//h2.DisplayHash();
	h2.Delete(15);
	h.DisplayHash();
}
