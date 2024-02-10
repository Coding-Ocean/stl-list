#include<iostream>
#include<list>
using namespace std;

//全要素表示用テンプレート関数
template <class C>
void show(int n,const C& data) {
	cout << ' ' << n << ": ";
	for (const auto& d : data)
		cout << d << " ";
	cout << "\n";
}

//sort merge splice
int main()
{
#if 1
	cout << "最初のリスト\n";
	list<int> data1{ 5,1,3 };
	list<int> data2{ 2,6,4 };
	show(1,data1);
	show(2,data2);
#else

	cout << "sort\n";
	data1.sort();
	show(1,data1);
	data2.sort(less<>());
	//data2.sort(greater<>());
	show(2,data2);

	cout << "merge\n";
	data1.merge(data2);
	show(1,data1);
	if(data2.empty())cout << " 2: empty" << endl;

	cout << "splice\n";
	for (int n = -2; n <= 0; ++n)data2.emplace_back(n);
	show(2,data2);
	data1.splice(data1.begin(), data2);
	show(1,data1);
	if (data2.empty())cout << " 2: empty" << endl;

#endif
	system("pause>0");
}
