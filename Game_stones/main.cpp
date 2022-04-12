/* ������� ���� "�����"
 * 2 ������ - ������������ � ��������� ������ ���� �� �������
 * ���� ���� � ��� N ������ (N=10...20 ������)
 * �� ��� ����� ������ ����� 1, 2 ��� 3 �����.
 * ��� ������ ��������� ������ - ��������
 * 1. ����� ����. ����������� ���� �����, ����� ����������� ���� �� �������
 * 2.�� ���������� ���� ����������, ����� �� ������ �����
 * ���� �� - ��������� �� ��������� �������� �������� �����
 * 3. ���������������� ���� ������ ����������� �� ������������
 * 4. ����� ������ ����� ������� �������� ������� ���������� ������
 * 5. ���� ��� ���������� - �������, ������� ���� ���������.
 */
#include <iostream>
#include<iomanip>
#include<limits>
#include<random>

int main() {
	int choice;
		do{
			int win;
			std::default_random_engine rnd;
			std::random_device rdev;
			rnd.seed(rdev());
			std::uniform_int_distribution<> kol{20,30};
			std::uniform_int_distribution<> komp{1,3};
			int N=kol(rnd);
			std::cout<<"� ���� "<<N<<" ������"<<std::endl;
			do{
				int xod;
				vash_xod:
				std::cout<<"��� ���: ";
				if(not(std::cin>>xod)){
					std::cout<<"������������ ����.��������� ������ �����"<<std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
					goto vash_xod;
				}
				N=N-xod;
				std::cout<<"� ���� "<<N<<" ������"<<std::endl;
				if(N==0){
					win=1;
				}
				if (win==0){
					int my=komp(rnd);
					if(N<=3){
						my=N;
					}
					N=N-my;
					if(N==0){
						win=2;
					}
					std::cout<<"��� ���: "<<my<<std::endl;
					std::cout<<"� ���� "<<N<<" ������"<<std::endl;
				}
			}while(N!=0);
			switch(win){
			case 1:
				std::cout<<"� ��������."<<std::endl;
				break;
			case 2:
				std::cout<<"�� ���������."<<std::endl;
				break;
			}
			menu_retry:
			std::cout<<"������ �����? (1 - ��, 0 - ���)";
			if(not(std::cin>>choice)){
				std::cout<<"������������ ����.��������� ������ �����"<<std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				goto menu_retry;
			}
			switch(choice){
			case 0:
				std::cout<<"�� ��������!"<<std::endl;
				break;
			}
		}while(choice!=0);
	return 0;
}
