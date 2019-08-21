#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>

template <typename Tv>
void print_arg(Tv v)
{
	std::cout << "{";
	unsigned int i = 0;
	for (auto x : v) {
		std::cout << x;
		if (v.size() != ++i)
			std::cout << ", ";
	}
	std::cout << "}";
}
int sparent[1000000];
int dparent[1000000];

int find(int *p, int x) {
	if (x == p[x]) {
		return x;
	}
	else {
		int pp = find(p, p[x]);
		p[x] = pp;
		return pp;
	}

}


void Union(int *p, int x, int y) {
	x = find(p, x);
	y = find(p, y);

	if (x != y) {
		p[y] = x;
	}
}

int main(void) {
	using namespace std;
	std::string in;
	std::string str;
	std::cin >> in;

	map<string, int> same;
	map<string, int> diff;
	vector<string> vs;
	vector<string> vd;
	vs.push_back("");
	vd.push_back("");

	int key = 1;
	int dkey = 1;

	std::stringstream ss(in);
	while (std::getline(ss, str, '&')) {
		std::string null;
		std::getline(ss, null, '&');
		auto i = 0u;
		string s1, s2;
		while (i < str.length()) {
			if (str[i] == '=') {
				if (str[i + 1] == '=') {
					s1 = str.substr(0, i);
					s2 = &str[i + 2];
					i += 1;
					if (same[s1] == 0) {
						sparent[key] = key;
						same[s1] = key++;
						vs.push_back(s1);
					}
					if (same[s2] == 0) {
						sparent[key] = key;
						same[s2] = key++;
						vs.push_back(s2);
					}
					Union(sparent, same[s1], same[s2]);
				}
				else {
					s1 = str.substr(0, i - 1);
					s2 = &str[i + 1];
					if (!diff[s1]) {
						dparent[dkey] = dkey;
						diff[s1] = dkey++;
						vd.push_back(s1);
					}
					if (!diff[s2]) {
						dparent[dkey] = dkey;
						diff[s2] = dkey++;
						vd.push_back(s2);
					}
					Union(dparent, diff[s1], diff[s2]);
				}
			}
			i++;
		}
	}
	string answer = "";
	for (int i = 1; i < key; i++) {
		if (sparent[i] != i) {
			answer = answer + vs[sparent[i]] + "==" + vs[i] + "&&";
		}
	}
	for (int i = 1; i < dkey; i++) {
		if (dparent[i] != i) {
			answer = answer + vd[dparent[i]] + "!=" + vd[i] + "&&";
		}
	}
	answer.pop_back();
	answer.pop_back();
	cout << answer;
}