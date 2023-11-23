//Task 1 C++ internship GUESSING GAME
#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main() {
	int user_num,guess=0,gen_num,x=time(0);
	srand(x);
	gen_num=rand()%100;
	cout<<"\t\t\t\tWelcome to NUMBER GUESSING GAME\n";
	cout<<"\tEnter a number between 1 to 100 to guess the secret number: ";
	while(1){
		cin>>user_num;
		guess++;
		cout<<"\n";
		if(user_num==gen_num){
			cout<<"\tYour guess is right, you won!!!\n";
			break;
		}
		else if(user_num>gen_num){
			cout<<"\n\tEntered number is greater than Secret Number, try with different number:";
		}
		else{
			cout<<"\n\tEntered number is lesser than Secret Number, try with different number:";
		}
	}
	cout<<"\n \t\t\t\t Total number of guesses = "<<guess<<"\n\n";
	return 0;
}
