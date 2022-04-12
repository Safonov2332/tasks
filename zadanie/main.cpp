/*�������: �������� ���������, ��������� ���������� ���������� ����� input.txt
 * �� ������� ����� �������, ����� ������ ���������� ������ �� ��������� 40 ��������, �� ����� ��������� ������.
 * �������, ��� ���� ������� 40 �������� � ����� ���, � ����������� ����� ��������� � ���������� �����.
 */
#include<iostream>
#include<fstream>
#include<cerrno>
#include <sstream>
#include<cstring>
int main(){
	std::ifstream file;
	file.open("input.txt");
	if(file){
		const char* s;
		int sum=0,count=0;
		std::string s1;
		while(file>>s1){
			s=s1.c_str();
			if((sum+=strlen(s))<=40){
				if(count>0){
					std::cout<<" ";
				}
				std::cout<<s;
				sum++;
				count++;
			}
			else{
				std::cout<<std::endl<<s;
				sum=0;
				sum+=strlen(s);
			}
		}
		std::cout<<std::endl;
		if(file.eof()){
			std::cout<<"��������� ��� ��������"<<std::endl;
		}
		else{
			std::cout<<"������ � �����"<<std::endl;
		}
	}
	else{
		std::cout<<"���������� ������� ����"<<std::endl;
		if (errno==ENOENT){
			std::cout<<"���� �����������"<<std::endl;
		}
		else{
			std::cout<<strerror(errno)<<std::endl;
		}
	}
	file.close();
	return 0;
}
