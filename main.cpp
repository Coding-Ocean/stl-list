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

//追加・削除
int main()
{
#if 1
	list<int> data;

	cout << "emplace_back おしりに追加\n";
	data.emplace_back(4);
	show(data);
	data.emplace_back(6);
	show(data);

#else
	cout << "emplace_front 最初に挿入\n";
	data.emplace_front(2);
	show(data);

	cout << "emplace 途中に挿入\n";
	//偶数の前に奇数を挿入
	int odd = 1;
	auto it = data.begin();
	while (it != data.end()){
		if (*it % 2 == 0) {
			it = data.emplace(it,odd);
			++it;
			++it;
			odd += 2;
		}
		else {
			++it;
		}
	}
	show(data);

	cout << "erace 途中を削除\n";
	//偶数を削除
	it = data.begin();
	while (it != data.end()){
		if (*it % 2 == 0) {
			it = data.erase(it);
		}
		else {
			++it;
		}
	}
	show(data);

	cout << "pop_back 最後を削除\n";
	data.pop_back();
	show(data);

	cout << "pop_front 最初を削除\n";
	data.pop_front();
	show(data);
#endif
	system("pause>0");
}
