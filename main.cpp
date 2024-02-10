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

//�ǉ��E�폜
int main()
{
#if 1
	list<int> data;

	cout << "emplace_back ������ɒǉ�\n";
	data.emplace_back(4);
	show(data);
	data.emplace_back(6);
	show(data);

#else
	cout << "emplace_front �ŏ��ɑ}��\n";
	data.emplace_front(2);
	show(data);

	cout << "emplace �r���ɑ}��\n";
	//�����̑O�Ɋ��}��
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

	cout << "erace �r�����폜\n";
	//�������폜
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

	cout << "pop_back �Ō���폜\n";
	data.pop_back();
	show(data);

	cout << "pop_front �ŏ����폜\n";
	data.pop_front();
	show(data);
#endif
	system("pause>0");
}
