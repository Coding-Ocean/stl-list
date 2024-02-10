#include<iostream>
#include<list>
using namespace std;

//�S�v�f�\���p�e���v���[�g�֐�
template <class C>
void show(const C& data) {
	for (const auto& d : data)
		cout << d << " ";
	cout << "\n";
}

//�\���̂̃��X�g���\�[�g
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
	cout << "����グ�����X�g\n";
	list<SALES> sales{
		{ 1,10 }, { 3,30 },{ 2,20 }, { 1,10 }, { 2,20 }, { 3,30 },
	};
	show(sales);

#else
	cout << "�\�[�g\n";
	sales.sort();
	show(sales);

	cout << "�O���[�v�g�[�^��\n";
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
