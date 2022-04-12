/*Задание: Написать программу, выводящую содержимое текстового файла input.txt
 * на консоль таким образом, чтобы ширина выводимого текста не превышала 40 символов, но слова разрывать нельзя.
 * Считаем, что слов длиннее 40 символов в файле нет, а разделяются слова пробелами и переводами строк.
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
			std::cout<<"Прочитаны все значения"<<std::endl;
		}
		else{
			std::cout<<"Ошибка в файле"<<std::endl;
		}
	}
	else{
		std::cout<<"Невозможно открыть файл"<<std::endl;
		if (errno==ENOENT){
			std::cout<<"Файл отсутствует"<<std::endl;
		}
		else{
			std::cout<<strerror(errno)<<std::endl;
		}
	}
	file.close();
	return 0;
}
