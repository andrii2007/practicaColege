#include <iostream>
#include <ctime>

std::string getUserChoice();
std::string getComputerChoice();
void showChoice(std::string  choice);
void Choosewinnre(std::string  player,std::string  computer,int &YourWin,int &ComputersWin,int &draw);
int choiceTypeGames();
void CallAll(int &YourWin,int &ComputersWin,int &draw);
void dashboard(int YourWin,int ComputersWin,int draw);


int main(){
    srand(time(NULL));
    
    int Repeat=2;
    int YourWin=0,ComputersWin=0,draw=0;
    
    do{
        int typeGames=choiceTypeGames();
        if(typeGames==1){
            CallAll(YourWin,ComputersWin,draw);
            }
            else if(typeGames==2){
                while(YourWin!=3&&ComputersWin!=3){
                    CallAll(YourWin,ComputersWin,draw);
                   dashboard(YourWin,ComputersWin,draw);
                }
            }else if(typeGames==3){
                while(YourWin!=5&&ComputersWin!=5){
                    CallAll(YourWin,ComputersWin,draw);
                    dashboard(YourWin,ComputersWin,draw);
                }
            }else if(typeGames==4){
                std::cout<<"Thank for games"<<'\n';
                Repeat=2;
                // dashboard(YourWin,ComputersWin,draw);
            }
            if(typeGames!=4){

                std::cout<<"Play again 1-Yes 2-No: ";
                std::cin>>Repeat;
                if(Repeat==2){
                    std::cout<<"Thank for games"<<'\n';
            }
        }

    }while(Repeat !=2);
    


 
    return 0;
}

void CallAll(int &YourWin,int &ComputersWin,int &draw){
    std::string player=getUserChoice();
    std::string computer=getComputerChoice();
    std::cout<<"Your choice is ";
    showChoice(player);
    std::cout<<"Computer choice is ";
    showChoice(computer);
    Choosewinnre(player,computer,YourWin,ComputersWin,draw);
}

int choiceTypeGames(){
    int player;
    int i=0;
    do{
        if(i>0){
            std::cout<<"Try again"<<'\n';
        }
        std::cout<<"Chose one of folowing\n";
        std::cout<<"1 is play once \n";
        std::cout<<"2 is play to 3 wins\n";
        std::cout<<"3 is play to 5 wins\n";
        std::cout<<"4 exit\n";
        std::cin>>player;
        i++;
    }while(player != 1 && player!=2 && player!=3&& player!=4);
    
    return player;
}

std::string getUserChoice(){
    std::string player;
    int i=0;
    do{
        if(i>0){
            std::cout<<"Try again"<<'\n';
        }
        std::cout<<"Chose one of folowing\n";
        std::cout<<"r is rock🪨 \n";
        std::cout<<"s is scissors✂️\n";
        std::cout<<"p is paper✋🏻\n";
        std::cin>>player;
        i++;
    }while(player != "s" && player!="r" && player!="p");
    
    return player;
}
std::string getComputerChoice(){
    std::string choice;
    srand(time(0));
    int Numchoice=(rand()%3)+1;

    switch (Numchoice)
    {
    case 1:
        choice="r";
        break;
    case 2:
        choice="p";
        break;
    case 3:
        choice="s";
        break;
    default:
        break;
    }
    return choice;
}


void showChoice(std::string choice){
    if(choice=="s"){
        std::cout<<"scissors✂️\n";
    }
    else if(choice=="r"){
        std::cout<<"Rock✋🏻\n";
    }
    if(choice=="p"){
        std::cout<<"paper🪨\n";
    };
}


void Choosewinnre(std::string  player,std::string  computer,int &YourWin,int &ComputersWin,int &draw){
    if("r" == player){
        if ("r"==computer){
            std::cout<<'\n';
            std::cout<<"No one won🤨\n";
            std::cout<<'\n';
            draw++;
        }else if("p"==computer){
            std::cout<<'\n';
            std::cout<<"computer won🥲\n";
            std::cout<<'\n';
            ComputersWin++;
        }else if("s"==computer){
            std::cout<<'\n';
            std::cout<<"You won😁\n";
            std::cout<<'\n';
            YourWin++;
        }  
    }else if("p" == player){
        if ("p"==computer){
            std::cout<<'\n';
            std::cout<<"No one won🤨\n";
            std::cout<<'\n';
            draw++;
        }else if("s"==computer){
            std::cout<<'\n';
            std::cout<<"computer won🥲\n";
            std::cout<<'\n';
            ComputersWin++;
        }else if("r"==computer){
            std::cout<<'\n';
            std::cout<<"You won😁\n";
            std::cout<<'\n';
            YourWin++;
        } 
    }else if("s" == player){
        if ("s"==computer){
            std::cout<<'\n';
            std::cout<<"No one won🤨\n";
            std::cout<<'\n';
            draw++;
        }else if("r"==computer){
            std::cout<<'\n';
            std::cout<<"computer won🥲\n";
            std::cout<<'\n';
            ComputersWin++;
        }else if("p"==computer){
            std::cout<<'\n';
            std::cout<<"You won😁\n";
            std::cout<<'\n';
            YourWin++;
        } 
}

}

void dashboard(int YourWin,int ComputersWin,int draw){
    std::cout<<"Your points: "<<YourWin<<'\n';
    std::cout<<"Computer Points: "<<ComputersWin<<'\n';
    std::cout<<"Draw Points: "<<draw<<'\n';
}