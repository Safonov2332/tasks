/* Задание Игра "Камни"
 * 2 игрока - пользователь и компьютер делают ходы по очереди
 * есть куча в ней N камней (N=10...20 рандом)
 * За ход игрок обязан взять 1, 2 или 3 камня.
 * Кто забрал последний камень - проиграл
 * 1. Нужен цикл. Завершается цикл тогда, когда проигрывает один из игроков
 * 2.По окончаниии игры спрашиваем, будем ли играть снова
 * Если да - переходим на следующию итерацию внешнего цикла
 * 3. Пользовательский ввод должен проверяться на корректность
 * 4. Перед каждым ходом следует выводить текущее количество камней
 * 5. Если ход компьютера - выводим, сколько берёт компьютер.
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
			std::cout<<"В куче "<<N<<" камней"<<std::endl;
			do{
				int xod;
				vash_xod:
				std::cout<<"Ваш ход: ";
				if(not(std::cin>>xod)){
					std::cout<<"Некорректный ввод.Требуется ввести число"<<std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
					goto vash_xod;
				}
				N=N-xod;
				std::cout<<"В куче "<<N<<" камней"<<std::endl;
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
					std::cout<<"Мой ход: "<<my<<std::endl;
					std::cout<<"В куче "<<N<<" камней"<<std::endl;
				}
			}while(N!=0);
			switch(win){
			case 1:
				std::cout<<"Я проиграл."<<std::endl;
				break;
			case 2:
				std::cout<<"Вы проиграли."<<std::endl;
				break;
			}
			menu_retry:
			std::cout<<"Играем снова? (1 - да, 0 - нет)";
			if(not(std::cin>>choice)){
				std::cout<<"Некорректный ввод.Требуется ввести число"<<std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				goto menu_retry;
			}
			switch(choice){
			case 0:
				std::cout<<"До свидания!"<<std::endl;
				break;
			}
		}while(choice!=0);
	return 0;
}
