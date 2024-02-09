#include<iostream>
#include<list>
#include<unordered_map>
#include<map>
using namespace std;

//pair<int, string>�\���p
//ostream& operator<<(ostream& s, const pair<int, string>& d) {
//    return s << d.first << " " << d.second;
//}

//�S�v�f�\���p�e���v���[�g�֐�
template <class C>
void show(const C& data) {
	for (const auto& d : data)
		cout << d << " ";
	cout << "\n";
}

//emplace_back emplace_front emplace erase pop_back pop_front
#if 0
int main()
{
	list<int> data;

	cout << "������ɒǉ�\n";
	data.emplace_back(4);
	show(data);
	data.emplace_back(6);
	show(data);

	cout << "�ŏ��ɑ}��\n";
	data.emplace_front(2);
	show(data);

	cout << "�����̑O�Ɋ��}��\n";
	int odd = 1;
	auto it = data.begin();
	while (it != data.end()){
		if (*it % 2 == 0) {
			it = data.emplace(it,odd);
			++it;
			++it;
			//it = next(it, 2);
			odd += 2;
		}
		else {
			++it;
		}
	}
	show(data);

	cout << "����������\n";
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

	cout << "�Ō���폜\n";
	data.pop_back();
	show(data);

	cout << "�ŏ����폜\n";
	data.pop_front();
	show(data);

	system("pause>0");
}
#endif
//sort merge splice
#if 0
int main()
{
	list<int> data1{ 5,1,3 };
	list<int> data2{ 2,6,4 };

	data1.sort();
	show(data1);
	data2.sort(less<>());
	//data2.sort(greater<>());
	show(data2);

	data1.merge(data2);
	show(data1);
	cout << data2.size() << endl;

	for (int n = -2; n <= 0; ++n)data2.emplace_back(n);
	show(data2);
	data1.splice(data1.begin(), data2);
	show(data1);
	cout << data2.size() << endl;

	for (int n = 7; n <= 9; ++n)data2.emplace_back(n);
	show(data2);
	data1.splice(data1.end(), data2);
	show(data1);

	system("pause>0");
}
#endif
//�\���̃f�[�^�̃\�[�g
#if 0
struct SALES {
	int no; int num;
	bool operator<(const SALES& rhs)const { return no < rhs.no; }
	bool operator>(const SALES& rhs)const { return no > rhs.no; }
};
std::ostream& operator<<(std::ostream& s, const SALES& d) {
	return s << "(" << d.no << "," << d.num << ")";
}

int main()
{
	cout << "����グ���X�g\n";
	list<SALES> sales{
		{ 1,10 }, { 2,20 }, { 3,30 },
		{ 1,10 }, { 2,20 }, { 3,30 },
	};
	show(sales);

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

	cin.get();
}
#endif
//unordered_map���珤�i���A�P�����Ђ��ς��Ă���
#if 0
struct SALES {
	int no; int num;
	bool operator<(const SALES& rhs)const { return no < rhs.no; }
};
struct MENU {
	string name;
	int price;
};
int main()
{
	//cout << "����グ���X�g\n";
	list<SALES> sales;
	sales.emplace_back(3, 30);
	sales.emplace_back(2, 20);
	sales.emplace_back(1, 10);
	sales.emplace_back(3, 30);
	sales.emplace_back(2, 20);
	sales.emplace_back(1, 10);

	//cout << "�\�[�g\n";
	sales.sort();

	//cout << "���j���[�}�b�v\n";
	unordered_map<int, MENU> menu;
	menu[1] = { "�L�q",300 };
	menu[2] = { "���[����",500 };
	menu[3] = { "�`���[�n��",400 };
	menu[4] = { "���у}��",550 };

	//std::cout << "�O���[�v�g�[�^��\n";
	auto it = sales.begin();
	while (it != sales.end()) {
		//no���Ƃ�sales�f�[�^���W�v
		int sum = 0;
		int no = it->no;
		while (it != sales.end() && no == it->no) {
			sum += it->num;
			++it;
		}
		//�W�v���ʂ̕\��
		cout << menu[no].name << ":"
			<< sum << ":"
			<< menu[no].price * sum << endl;
	}

	cin.get();
}
#endif

#if 1
int main() {
	vector<int> v{ 1,2,4 };
	auto it = v.begin();
	it += 2;
	v.emplace(it, 3);
	show(v);

	int a[]{ 4,3,2,1 };
	show(a);

	cin.get();
}
#endif