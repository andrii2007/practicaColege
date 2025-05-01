// #include <iostream>
// #include <cmath>
// #include <vector>


// std::string SmileDecrypto(std::string str) {
//     std::string arrayCap[] = { "😀", "😃", "😄", "😁", "😆", "😊", "🙂", "😉", "😋", "😎",
//                                "😍", "🥰", "😘", "😗", "😙", "😚", "🤗", "🤩", "😏", "😌",
//                                "🍏", "🍎", "🍐", "🐶", "💣", "🥳" };

//     std::string arrayLOw[] = { "✅", "$", "🥭", "📀", "😆", "❤️‍🩹", "🛻", "🎱", "🐱", "🐭",
//                                "🐨", "🐸", "❌", "⚽️", "🥸", "🎣", "🍌", "🫥", "🔟", "🎪",
//                                "🤺", "♜", "Ł", "∅", "🥐", "🥶" };

//     std::string result;

//     // Use iterators to correctly handle multi-byte characters (like emojis)
//     for (size_t i = 0; i < str.size();) {
//         if (str[i] == ' ') {
//             result += ' ';
//             ++i;
//             continue;
//         }

//         // Extract full emoji from UTF-8 string
//         size_t len = 1;
//         if ((str[i] & 0xF8) == 0xF0) len = 4; // 4-byte emoji
//         else if ((str[i] & 0xF0) == 0xE0) len = 3;
//         else if ((str[i] & 0xE0) == 0xC0) len = 2;

//         std::string emoji = str.substr(i, len);
//         i += len;

//         bool matched = false;

//         for (int j = 0; j < 26; ++j) {
//             if (emoji == arrayCap[j]) {
//                 result += static_cast<char>('A' + j);
//                 matched = true;
//                 break;
//             }
//             if (emoji == arrayLOw[j]) {
//                 result += static_cast<char>('a' + j);
//                 matched = true;
//                 break;
//             }
//         }

//         if (!matched) {
//             result += emoji; // unknown symbol, append as-is
//         }
//     }

//     return result;
// }


// // #include <iomanip>

// int main(){

//     std::string str = "😉✅🫥🐸😮‍💨";
//     int Tempstr = str.find("🤗");
//     std::cout<<Tempstr<<'\n';

//     // bool check =Tempstr == "😉";
//     // std::cout<<check<<'\n';
//         std::string arrayCap[] ={ "😀", "😃", "😄", "😁", "😆", "😊", "🙂", "😉", "😋", "😎", 
//             "😍", "🥰", "😘", "😗", "😙", "😚", "🤗", "🤩", "😏", "😌","🍏","🍎","🍐","🐶","💣","🥳"};
    
//         std::string arraylow[] ={ "✅", "$", "🥭", "📀", "😆", "❤️‍🩹", "🛻", "🎱", "🐱", "🐭", 
//                 "🐨", "🐸", "❌", "⚽️", "🥸", "🎣", "🍌", "😮‍💨", "🔟", "🎪","🤺","♜","Ł","∅","🥐","🥶"};
//     // std::cout<<array[24]<<'\n';
//     // std::cout<<sizeof(arrayCap)/sizeof(arrayCap[0])<<'\n';
//     // std::cout<<'\n';


//     // SmileCrypto("HELLO WORLD");
//     // std::cout<<SmileCrypto("AHELLO WORLD.")<<'\n';
//     // std::cout<<SmileCrypto("This is my pro ject")<<'\n';
//     std::cout<<SmileDecrypto("😉😆🐸🐸🥸 ❌🥐 📀😆✅🫥 🐸🥸♜😆")<<'\n';
//     return 0;
// }



// makeType(value,type);
// std::string firstPath,SecondPath;
// std::string word;
// int dec=0;
// for (int i=0; i<value.length(); i++)
// {
//     if (value[i]!=' '){
//         word+=value[i]; 
//     }else{
//         if(dec==1){
//             firstPath=word;
//         }else if(dec==0){
//             SecondPath=word;
//         }
//         dec++; 
//         word="";
// }
// }



#include <iostream>
#include <cmath>
#include <vector>
#include <string>

bool checksFloat(std::string str){
    for(int i=0;i<str.size();i++){
        return true;
    }
    return false;
}



bool checkMinus(std::string str){
    if(str[0]=='-'){
        return true;
    }
return false;
}

std::string ConvertTo2(int x){
    std::vector<int> result;
    int temp=x;
    int dec=0;
    long int number=0;
do{
    result.push_back(temp%2);
    temp=temp/2;
    dec++;
}while(temp!=0);

for(int i=result.size()-1;i>=0;i--){
    number+=result.at(i);
    if(i!=0){
        number*=10;
    }
}

std::string str=std::to_string(number);
str.insert(0,"0B");

return str;
}

std::string ConvertTo8(int x){
    std::vector<int> result;
    int temp=x;
    int dec=0;
    int number=0;
do{
    result.push_back(temp%8);
    temp=temp/8;
    dec++;
}while(temp>7);
result.push_back(temp);

for(int i=result.size()-1;i>=0;i--){
    number+=result.at(i);
    if(i!=0){
        number*=10;
    }
}

std::string str=std::to_string(number);
str.insert(0,"0");

return str;
}

int ConvertTo10(std::string str){

    if(str[0] == '0'&& (str[1]=='b'||str[1]=='B')){
        str.erase(0,2);
        int decimal = std::stoi(str, nullptr, 2);
        return decimal;

    }else if(str[0] == '0' && str[1]!='x' && str[1]!='X'){
        str.erase(0,1);
        int eigth = std::stoi(str, nullptr, 8);
        return eigth;

    }else if(str[0]=='0' && (str[1]=='x'|| str[1]=='X')){
        str.erase(0,2);
        int sixteens = std::stoi(str, nullptr, 16);
        return sixteens;
    }else{
        return std::stoi(str);
    }

}

std::string ConvertTo16(int x){
    std::string results="";
    int temp=x;
    char arr[]="0123456789ABCDEF";
do{
    results=arr[temp%16]+results;
    temp=temp/16;
}while(temp>15);

results=arr[temp]+results;
results.insert(0,"0x");

return results;
}

std::string ChecksTypes(std::string first,int resultAction){
    if(checkMinus(first)){
        first=first.erase(0,1);
    }

    std::string resultOut;
    if(first[0] == '0'&&(first[1]=='b'||first[1]=='B')){
        return resultOut="(BIN)";
    }else if(first[0] == '0' && (first[1]!='x' && first[1]!='X')){
        return resultOut="(OCT)";
    }else if(first[0]=='0' && (first[1]=='x'|| first[1]=='X')){
        return resultOut="(HEX)";
    }else if(first[0]!='0'){
        return resultOut="(DEC)";
    }else{
        return 0;
    }
}

std::string doWithTypes(std::string first,int resultAction){
        std::string resultOut;
        if(first[0] == '0' && (first[1]=='b' || first[1]=='B')){
            return resultOut=ConvertTo2(resultAction);
        }else if(first[0] == '0' && (first[1]!='x' && first[1]!='X')){
            return resultOut=ConvertTo8(resultAction);
        }else if(first[0]=='0' && (first[1]=='x'|| first[1]=='X')){
            return resultOut=ConvertTo16(resultAction);
        }else{
            return resultOut=std::to_string(resultAction);
        }
}

std::string makeType(std::string &value,std::string type){
    if(type=="(BIN)"||type=="BIN"){
        return value.insert(0,"0b");
    }else if(type=="(HEX)"||type=="HEX"){
        return value.insert(0,"0x");
    }else if(type=="(OCT)"||type=="OCT"){
        return value.insert(0,"0");
    }else if(type=="(DEC)"||type=="DEC"){
        return value;
    }else{
        return 0;
    }
}

void showREsult(std::string value, std::string type){
    if(checksFloat(value)){
        std::string firstPath,SecondPath;
        std::string word;
        int dec=0;
        for (int i=0; i<value.length(); i++)
        {
            if (value[i]!=' '){
                word+=value[i]; 
            }else{
                if(dec==1){
                    firstPath=word;
                }else if(dec==0){
                    SecondPath=word;
                }
                dec++; 
                word="";
        }
        }

        int y1=ConvertTo10(firstPath);
        std::string result=ConvertTo16(y1);
        std::string resultSec=ConvertTo8(y1);
        std::string resultSecs=ConvertTo2(y1);
        int y2=ConvertTo10(SecondPath);
        std::string resultsecPath=ConvertTo16(y2);
        std::string resultSecPath=ConvertTo8(y2);
        std::string resultSecsPath=ConvertTo2(y2);
    
        if(result[2]=='0'){
            result.erase(0,3);
        }else{
            result.erase(0,2);
        }
        if(resultsecPath[2]=='0'){
            resultsecPath.erase(0,3);
        }else{
            resultsecPath.erase(0,2);
        }
    
        if(type=="(BIN)"||type=="BIN"){
            std::cout<<resultSec.erase(0,1)<<'.'<<resultSecPath.erase(0,1)<<" (OCT)"<<'\n';
            std::cout<<y1<<'.'<<y2<<" DEC"<<'\n';
            std::cout<<result<<'.'<<resultsecPath<<" (HEX)"<<'\n';
        }else if(type=="(HEX)"||type=="HEX"){
            std::cout<<resultSecs.erase(0,2)<<'.'<<resultSecsPath.erase(0,2)<<" (BIN)"<<'\n';
            std::cout<<resultSec.erase(0,1)<<'.'<<resultSecPath.erase(0,1)<<" (OCT)"<<'\n';
            std::cout<<y1<<'.'<<y2<<" DEC"<<'\n';
        }else if(type=="(OCT)"||type=="OCT"){
            std::cout<<resultSecs.erase(0,2)<<'.'<<resultSecsPath.erase(0,2)<<" (BIN)"<<'\n';
            std::cout<<y1<<'.'<<y2<<" DEC"<<'\n';
            std::cout<<result<<'.'<<resultsecPath<<" (HEX)"<<'\n';
        }else if(type=="(DEC)"||type=="DEC"){
            std::cout<<resultSecs.erase(0,2)<<'.'<<resultSecsPath.erase(0,2)<<" (BIN)"<<'\n';
            std::cout<<resultSec.erase(0,1)<<'.'<<resultSecPath.erase(0,1)<<" (OCT)"<<'\n';
            std::cout<<result<<'.'<<resultsecPath<<" (HEX)"<<'\n';
        }


    }else{
    int y=ConvertTo10(value);
    std::string result=ConvertTo16(y);
    std::string resultSec=ConvertTo8(y);
    std::string resultSecs=ConvertTo2(y);

    if(result[2]=='0'){
        result.erase(0,3);
    }else{
        result.erase(0,2);
    }

    if(type=="(BIN)"||type=="BIN"){
        std::cout<<resultSec.erase(0,1)<<" (OCT)"<<'\n';
        std::cout<<y<<" DEC"<<'\n';
        std::cout<<result<<" (HEX)"<<'\n';
    }else if(type=="(HEX)"||type=="HEX"){
        std::cout<<resultSecs.erase(0,2)<<" (BIN)"<<'\n';
        std::cout<<resultSec.erase(0,1)<<" (OCT)"<<'\n';
        std::cout<<y<<" DEC"<<'\n';
    }else if(type=="(OCT)"||type=="OCT"){
        std::cout<<resultSecs.erase(0,2)<<" (BIN)"<<'\n';
        std::cout<<y<<" DEC"<<'\n';
        std::cout<<result<<" (HEX)"<<'\n';
    }else if(type=="(DEC)"||type=="DEC"){
        std::cout<<resultSecs.erase(0,2)<<" (BIN)"<<'\n';
        std::cout<<resultSec.erase(0,1)<<" (OCT)"<<'\n';
        std::cout<<result<<" (HEX)"<<'\n';
    }
}

}

void start(int &choice){
    std::cout<<"1-Convert from 1 system to others"<<'\n';
    std::cout<<"2-Calculatu to number other systems"<<'\n';
    std::cout<<"3-Exit"<<'\n';
    std::cin>>choice;
    std::cin.ignore();
}

bool CheckCorectTypes(std::string CheckCorectTypes,std::string value){
    if(CheckCorectTypes=="BIN"||CheckCorectTypes=="(BIN)"){
        int check=0;
        for(int i=0;i<value.length();i++){
            if(value[i]=='.'||value[i]==0 || value[i]=='0'){
                check=check;

            }else if(value[i]=='.'||value[i]==1 || value[i]=='1'){
                check=check;
            }else {
                check++;
            }

        }
        return check==0;

    }else if(CheckCorectTypes=="OCT"||CheckCorectTypes=="(OCT)"){
        int check=0;
        for(int i=0;i<value.length();i++){
            if(value[i]>=0 && value[i]<=7){
                check=check;
            }else if(value[i]=='.'||value[i]=='0'||value[i]=='1'||value[i]=='2'||value[i]=='3'||value[i]=='4'||value[i]=='5'||value[i]=='6'||value[i]=='7') {
                check=check;
            }else{
                check++;
            }
        }
        return check==0;
    }else if(CheckCorectTypes=="HEX"||CheckCorectTypes=="(HEX)"){
        int check=0, number=0,
        letter =0;
        for(int i=0;i<value.length();i++){
            if(value[i]>=0 && value[i]<=9 && number==0){
                check=check;
               number++;
               letter=0;
            }else if((value[i]=='.'||value[i]=='0'||value[i]=='1'||value[i]=='2'||value[i]=='3'||value[i]=='4'||value[i]=='5'||value[i]=='6'||value[i]=='7'||value[i]=='8'||value[i]=='9')&&number==0){
                check=check;
                number++;
                letter=0;
            }else if((value[i]=='.'||value[i]=='A'||value[i]=='B'||value[i]=='C'||value[i]=='D'||value[i]=='E'||value[i]=='F')&&letter==0){
                check=check;
                number=0;
                letter++;
            }else{
                check++;
            }
        }
        return check==0;
    }else if(CheckCorectTypes=="DEC"||CheckCorectTypes=="(DEC)"){
        int checks=0;
        for(int i=0;i<value.length();i++){
            if(value[i]=='.'||value[i]=='0'||value[i]=='1'||value[i]=='2'||value[i]=='3'||value[i]=='4'||value[i]=='5'||value[i]=='6'||value[i]=='7'||value[i]=='8'||value[i]=='9'){
                checks=checks;
            }else{
                checks++;
            }
        }
            return checks==0;
        }else{
        std::cout<<"Try again"<<'\n';
        return  false;
    }
}

bool FirstChoiceConverte(){

    std::string line, word="";
    std::cout<<"Enter your number in format (value) (type): ";
    getline (std::cin, line);

    line+=" ";
    std::string type="",value="";
    
    int dec=0;
    for (int i=0; i<line.length(); i++)
    {
        if (line[i]!=' '){
            word+=line[i]; 
        }else{
            if(dec==1){
                type=word;
            }else if(dec==0){
                value=word;
            }
            dec++; 
            word="";
    }
    }

    

    
    if (CheckCorectTypes(type,value))
    {
        makeType(value,type);
        showREsult(value,type);
        return false;

    }else{
        if(type=="(BIN)"||type=="BIN"){
            std::cout<<"Your type is not correct BIN it`s number from 0 to 1"<<'\n';
        }else if(type=="(OCT)"||type=="OCT"){
            std::cout<<"Your type is not correct OCT it`s number from 0 to 7"<<'\n';
        }else if(type=="(HEX)"||type=="HEX"){
            std::cout<<"Your type is not correct HEX it`s number from 0 to 9 and A to F also letter and number cannot be beside"<<'\n';
        }else if(type=="(DEC)"||type=="DEC"){
            std::cout<<"Your type is not correct DEC it`s number from 0 to 9"<<'\n';
    }
        return true;

    }
}

bool SecondChoiceCalculator(){


    std::cout<<"Enter your number in format (value1) (action) (value2): "<<'\n';
    std::cout<<"(action: +, -, *, /)"<<'\n';
    std::cout<<"(value1 and value2: 0b, 0x, 0, 0B, 0X)"<<'\n';
    std::cout<<"If you want write 0 write for example 00"<<'\n';
    std::cout<<"Enter: ";
    std::string line, word="";
    getline (std::cin, line);
    line+=" ";
    std::string first="",second="",symbow;
    int dec=0;
    for (int i=0; i<line.length(); i++)
    {
        if (line[i]!=' '){
            word+=line[i];  
        }else{
            if(dec==0){
                first=word;
            }else if(dec==1){
                symbow=word;
            }else if(dec==2){
                second=word;
            }
            dec++;
            word="";
    }
    }

    std::string SecondCopy=second;
    std::string firstCopy=first;

    if(checkMinus(second)){
        second.erase(0,1);

    }

    if(checkMinus(first)){
        first.erase(0,1);
    }
    std::cout<<first<<'\n';



    std::string typesLEtters1= ChecksTypes(first,0);
    std::string typesLEtter2= ChecksTypes(second,0);
    int y,y2;



    std::string copyFirst=first;
    std::string copySecond=second;

    if(typesLEtters1=="(BIN)"||typesLEtters1=="BIN"){
        copyFirst.erase(0,2);
    }else if(typesLEtters1=="(HEX)"||typesLEtters1=="HEX"){
        copyFirst.erase(0,2);
    }else if(typesLEtters1=="(OCT)"||typesLEtters1=="OCT"){
        copyFirst.erase(0,1);
    }else if(typesLEtters1=="(DEC)"||typesLEtters1=="DEC"){
        copyFirst.erase(0,0);
    }

    if(typesLEtter2=="(BIN)"||typesLEtter2=="BIN"){
        copySecond.erase(0,2);
    }else if(typesLEtter2=="(HEX)"||typesLEtter2=="HEX"){
        copySecond.erase(0,2);
    }else if(typesLEtter2=="(OCT)"||typesLEtter2=="OCT"){
        copySecond.erase(0,1);
    }else if(typesLEtter2=="(DEC)"||typesLEtter2=="DEC"){
        copySecond.erase(0,0);
    }


    int checkCorrectTypes=0;

    if (CheckCorectTypes(typesLEtters1,copyFirst)){
        y=ConvertTo10(first);
        checkCorrectTypes++;
    }else{
        if(typesLEtters1=="(BIN)"||typesLEtters1=="BIN"){
            std::cout<<"Your type is not correct BIN it`s number from 0 to 1"<<'\n';
        }else if(typesLEtters1=="(OCT)"||typesLEtters1=="OCT"){
            std::cout<<"Your type is not correct OCT it`s number from 0 to 7"<<'\n';
        }else if(typesLEtters1=="(HEX)"||typesLEtters1=="HEX"){
            std::cout<<"Your type is not correct HEX it`s number from 0 to 9 and A to F also letter and number cannot be beside"<<'\n';
        }else if(typesLEtters1=="(DEC)"||typesLEtters1=="DEC"){
            std::cout<<"Your type is not correct DEC it`s number from 0 to 9"<<'\n';
    }
    }

    if (CheckCorectTypes(typesLEtter2,copySecond)){
        y2=ConvertTo10(second);
        checkCorrectTypes++;
    }else{
        if(typesLEtter2=="(BIN)"||typesLEtter2=="BIN"){
            std::cout<<"Your type is not correct BIN it`s number from 0 to 1"<<'\n';
        }else if(typesLEtter2=="(OCT)"||typesLEtter2=="OCT"){
            std::cout<<"Your type is not correct OCT it`s number from 0 to 7"<<'\n';
        }else if(typesLEtter2=="(HEX)"||typesLEtter2=="HEX"){
            std::cout<<"Your type is not correct HEX it`s number from 0 to 9 and A to F also letter and number cannot be beside"<<'\n';
        }else if(typesLEtter2=="(DEC)"||typesLEtter2=="DEC"){
            std::cout<<"Your type is not correct DEC it`s number from 0 to 9"<<'\n';
    }
    }

    
    if(checkMinus(SecondCopy)){
        y2*=-1;

    }

    if(checkMinus(firstCopy)){
        y*=-1;
    }


    if(checkCorrectTypes==2){
    int resultAction;
    switch (symbow[0])
    {
    case '+':
        resultAction=y+y2;
        break;
    case '*':
        resultAction=y*y2;
        break;
    case '-':
        resultAction=y-y2;
        break;
    case '/':
        if(y2=='0'|| y2==0){
            std::cout<<"You cannot divide by 0"<<'\n';
            return false;
        }else{
            resultAction=y/y2;
        }
        break;
        
    default:
        break;
    }
    if(resultAction<0){
        std::cout<<resultAction<<" "<<"(DEC)"<<'\n';
    }else{
        if(ChecksTypes(first,resultAction)==ChecksTypes(second,resultAction)&& ChecksTypes(second,resultAction)!="(DEC)" ){
            std::cout<<doWithTypes(first,resultAction)<<" "<<ChecksTypes(first,resultAction)<<'\n';
            std::cout<<resultAction<<" "<<"(DEC)"<<'\n';
            
        }else if(ChecksTypes(first,resultAction)==ChecksTypes(second,resultAction)&& ChecksTypes(second,resultAction)=="(DEC)"){
            std::cout<<resultAction<<" "<<"(DEC)"<<'\n';
        }else if (ChecksTypes(first,resultAction)!=ChecksTypes(second,resultAction)&& ChecksTypes(second,resultAction)!="(DEC)"){
            std::cout<<doWithTypes(first,resultAction)<<" "<<ChecksTypes(first,resultAction)<<'\n';
            std::cout<<doWithTypes(second,resultAction)<<' '<<ChecksTypes(second,resultAction)<<'\n';
            std::cout<<resultAction<<" "<<"(DEC)"<<'\n';
        }else {
            std::cout<<doWithTypes(first,resultAction)<<" "<<ChecksTypes(first,resultAction)<<'\n';
            std::cout<<doWithTypes(second,resultAction)<<' '<<ChecksTypes(second,resultAction)<<'\n';
    }   
}

    return false;
}else{

    return true;
}
}




int main(){

    std::cout<<"Welcome to the calculator"<<'\n';

    int AgainStart=0;

    int choice;
    do{

    start(choice);

    if(choice==1){
    bool continueCalculator;
        do{
            continueCalculator= FirstChoiceConverte();
        }while(continueCalculator);
        
        std::cout<<"Do you want to start again? (1-yes, 0-no): ";
        std::cin>>AgainStart;
        std::cin.ignore();
        std::cout<<'\n';

}else if(choice==2){
    bool continueCalculator;

    do{
        continueCalculator= SecondChoiceCalculator();

    }while(continueCalculator);
  
    std::cout<<"Do you want to start again? (1-yes, 0-no): ";
    std::cin>>AgainStart;
    std::cin.ignore();
    std::cout<<'\n';

}else if(choice==3){
    std::cout<<"Thanks:)";
    AgainStart=0;
}else{
    std::cout<<"Try again choice from 1 to 3"<<'\n';
    start(choice);
}


}while(AgainStart!=0);

    return 0;
}
