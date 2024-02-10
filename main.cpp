#include<iostream>
#include<list>
using namespace std;

//全要素表示用テンプレート関数
template <class C>
void show(const C& data) {
	for (const auto& d : data)
		cout << d << " ";
	cout << "\n";
}

//構造体のリストをソート
struct SALES {
	int no;
	int num;
	//bool operator<(const SALES& rhs)const { return no < rhs.no; }
	//bool operator>(const SALES& rhs)const { return no > rhs.no; }
};
std::ostream& operator<<(std::ostream& s, const SALES& d) {
	return s << "(" << d.no << "," << d.num << ")";
}

int main()
{
#if 1
	cout << "売り上げ数リスト\n";
	list<SALES> sales{
		{ 1,10 }, { 3,30 },{ 2,20 }, { 1,10 }, { 2,20 }, { 3,30 },
	};
	show(sales);

#else
	cout << "ソート\n";
	sales.sort();
	show(sales);

	cout << "グループトータル\n";
	auto it = sales.begin();
	while (it != sales.end()) {
		int sum = 0;
		int no = it->no;
		while (it != sales.end() && no == it->no) {
			sum += it->num;
			++it;
		}
		cout << no << ":" << sum << endl;
	}

#endif
	cin.get();
}
