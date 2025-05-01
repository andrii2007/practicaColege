#include <iostream>
#include <fstream>
#include <string>


std::string Caesar(std::string str,int key){
    std::string result;
    for (char c : str) {
        if (c == ' ') {
            result += c; // Preserve spaces
        }else{
        int asciiCode = (int)c;
        int resASCII= key+asciiCode; 
        if (asciiCode >= 65 && asciiCode <= 90 && resASCII <= 90 && resASCII >= 65) { // Uppercase letters
            result+=char(c+key); // Uppercase letters
            asciiCode = ((asciiCode - 65 + 3) % 26) + 65;
        }else if(asciiCode >= 65 && asciiCode <= 90 && resASCII <= 65){
            resASCII=90-(64-resASCII);
            result+=char(resASCII); // Uppercase letters
        }else if(asciiCode >= 65 && asciiCode <= 90 && resASCII >= 90){
            resASCII=65+(resASCII-91);
            result+=char(resASCII); // Uppercase letters
        }else if (asciiCode >= 97 && asciiCode <= 122  && resASCII <= 122 &&resASCII>=97) { // Lowercase letters
            asciiCode = ((asciiCode - 97 + 3) % 26) + 97;
            result+=char(c+key); 
        }else if(asciiCode >= 97 && asciiCode <= 122 && resASCII <= 97){
            resASCII=123-(97-resASCII);
            result+=char(resASCII); // Uppercase letters
        }else if(asciiCode >= 97 && asciiCode <= 122 ){
            resASCII=97+(resASCII-123);
            result+=char(resASCII); // Uppercase letters
    }else{
        result+=c;
    }
}
}
    return result;
}


std::string ATBACH(std::string str){

    std::string result;

    for(char c:str){
        if (c == ' ') {
            result += ' '; 
        }else if(c >= 65 && c <= 90){
            int temp=90-(c-65);
            result+=char(temp);
        }else if(c >= 97 && c <= 122){
            int temp=122-(c-97);
            result+=char(temp);
        }else{
            result+=c;
        }
}
    return result;

}


std::string xorEncryptDecrypt(std::string text, std::string key) {

    std::string result = text;
    int keyLength = key.length();

    for (int i = 0; i < text.length(); ++i) {
        result[i] = text[i] ^ key[i % keyLength]; 
    }

    return result;
}


std::string SmileCrypto(std::string str) {

    std::string arrayCap[] ={ "😀", "😃", "😄", "😁", "😆", "😊", "🙂", "😉", "😋", "😎", 
        "😍", "🥰", "😘", "😗", "😙", "😚", "🤗", "🤩", "😏", "😌","🍏","🍎","🍐","🐶","💣","🥳"};

    std::string arrayLOw[] ={ "✅", "$", "🥭", "📀", "😆", "🖖", "🛻", "🎱", "🐱", "🐭", 
            "🐨", "🐸", "❌", "✊", "🥸", "🎣", "🍌", "🫥", "🔟", "🎪","🤺","♜","Ł","∅","🥐","🥶"};

            std::string result;

            for(char c:str){
                if (c == ' ') {
                    result += ' '; 
                }else if(c >= 65 && c <= 90){
                    int temp=c-65;
                    result+=arrayCap[temp];
                }else if(c >= 97 && c <= 122){
                    int temp=c-97;
                    result+=arrayLOw[temp];
                    
                }
        }
            return result;

}

std::string SmileDecrypto(std::string str) {
    std::string arrayCap[] = { "😀", "😃", "😄", "😁", "😆", "😊", "🙂", "😉", "😋", "😎",
                               "😍", "🥰", "😘", "😗", "😙", "😚", "🤗", "🤩", "😏", "😌",
                               "🍏", "🍎", "🍐", "🐶", "💣", "🥳" };

    std::string arrayLOw[] = { "✅", "$", "🥭", "📀", "😆", "🖖", "🛻", "🎱", "🐱", "🐭",
                               "🐨", "🐸", "❌", "✊", "🥸", "🎣", "🍌", "🫥", "🔟", "🎪",
                               "🤺", "♜", "Ł", "∅", "🥐", "🥶" };

    std::string result;
    for (int i = 0; i < str.size();) {

        if (str[i] == ' ') {
            result += ' ';
            ++i;
            continue;
        }

        int len = 1;
        if ((str[i] & 0xF8) == 0xF0) len = 4; // 4-byte emoji
        else if ((str[i] & 0xF0) == 0xE0) len = 3;
        else if ((str[i] & 0xE0) == 0xC0) len = 2;

        // Single-byte ASCII: 0xxxxxxx (values 0-127)
        // Two bytes: 110xxxxx 10xxxxxx
        // Three bytes: 1110xxxx 10xxxxxx 10xxxxxx
        // Four bytes: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
        
        // The bitwise operations check these patterns:
        
        // & 0xF8 masks the first 5 bits. If they match 11110xxx (0xF0), it's a 4-byte character
        // & 0xF0 masks the first 4 bits. If they match 1110xxxx (0xE0), it's a 3-byte character
        // & 0xE0 masks the first 3 bits. If they match 110xxxxx (0xC0), it's a 2-byte character

        std::string emoji = str.substr(i, len);
        i += len;

        bool matched = false;

        for (int j = 0; j < 26; ++j) {
            if (emoji == arrayCap[j]) {
                result += static_cast<char>('A' + j);
                matched = true;
                break;
            }
            if (emoji == arrayLOw[j]) {
                result += static_cast<char>('a' + j);
                matched = true;
                break;
            }
        }

        if (!matched) {
            result += emoji; 
        }
    }

    return result;
}



// 😉😆🐸🐸🥸 ❌🥐 📀😆✅🫥 🐸🥸♜😆



void choiceMenu(int choice,int ChoiceType,int method){
    if(ChoiceType==1){
        if(choice==1){
          if(method==1){
              std::cout<<"Enter text: ";
              std::string text;
              std::getline(std::cin, text);
              std::cout<<"Enter key: ";
              int key;
              std::cin>>key;
              std::cout<<Caesar(text,key)<<std::endl;
          }else if(method==2){
              std::cout<<"Enter text: ";
              std::string text;
              std::getline(std::cin, text);
              std::cout<<ATBACH(text)<<std::endl;
          }else if(method==3){    
              std::cout<<"Enter text: ";
              std::string text;
              std::getline(std::cin, text);

            //   std::cout<<"Enter key: ";
            //   std::string key;
            //   std::getline(std::cin, key);
            //   std::cout<<xorEncryptDecrypt(text,key)<<std::endl;

              std::cout<<SmileCrypto(text)<<std::endl;
          }else if(method==4){    
            std::cout<<"Enter text: ";
            std::string text;
            std::getline(std::cin, text);
            std::cout<<"Enter key: ";
            std::string key;
            std::getline(std::cin, key);
            std::cout<<xorEncryptDecrypt(text,key)<<std::endl;

        }else{
              std::cout<<"Invalid method"<<std::endl;
          }
      }else if(choice==2){
          if(method==1){
              std::cout<<"Enter text: ";
              std::string text;
              std::getline(std::cin, text);
              std::cout<<"Enter key: ";
              int key;
              std::cin>>key;
              std::cout<<Caesar(text,key*(-1))<<std::endl;
          }else if(method==2){
              std::cout<<"Enter text: ";
              std::string text;
              std::getline(std::cin, text);
              std::cout<<ATBACH(text)<<std::endl;
          }else if(method==3){    
              std::cout<<"Enter text: ";
              std::string text;
              std::getline(std::cin, text);
            //   std::cout<<"Enter key: ";
            //   std::string key;
            //   std::getline(std::cin, key);
            //   std::cout<<xorEncryptDecrypt(text,key)<<std::endl;
            std::cout<<SmileDecrypto(text)<<std::endl;

          }else if(method==4){    
            std::cout<<"Enter text: ";
            std::string text;
            std::getline(std::cin, text);
            std::cout<<"Enter key: ";
            std::string key;
            std::getline(std::cin, key);
            std::cout<<xorEncryptDecrypt(text,key)<<std::endl;

        }else{
              std::cout<<"Invalid method"<<std::endl;
          }
      }else if(choice==3){
          std::cout<<"Goodbye!"<<std::endl;
      }else{
          std::cout<<"Invalid choice"<<std::endl;
      }
  }
  

  else if(ChoiceType==2){
    if(choice==1){
          if(method==1){
              std::cout<<"Enter file for read: ";
              std::string text;
              std::cin>>text;
              std::cout<<"Enter file for write: ";
              std::string text2;
              std::cin>>text2;
              std::cout<<"Enter key: ";
              int key;
              std::cin>>key;
              std::cin.ignore();

              std::ifstream inFile(text);
              if (!inFile) {
                  std::cout << "Error opening file for reading!\n";
              }
              std::ofstream outFile(text2);  
              if (!outFile) {
                  std::cout << "Error opening file for writing!\n";
              }
  
              std::string line;
            //   std::cout << "Contents of " << text << ":\n";
              while (std::getline(inFile, line)) {
                 outFile<<Caesar(line,key)<<std::endl;
              }
              outFile.close();
              inFile.close();

          }else if(method==2){
            std::cout<<"Enter file for read: ";
            std::string text;
            std::cin>>text;
            std::cout<<"Enter file for write: ";
            std::string text2;
            std::cin>>text2;
            std::cin.ignore();

            std::ifstream inFile(text);
            if (!inFile) {
                std::cout << "Error opening file for reading!\n";
            }
            std::ofstream outFile(text2);  
            if (!outFile) {
                std::cout << "Error opening file for writing!\n";
            }

            std::string line;
          //   std::cout << "Contents of " << text << ":\n";
            while (std::getline(inFile, line)) {
               outFile<<ATBACH(line)<<std::endl;
            }
            outFile.close();
            inFile.close();


          }else if(method==3){    
            std::cout<<"Enter file for read: ";
            std::string text;
            std::cin>>text;
            std::cout<<"Enter file for write: ";
            std::string text2;
            std::cin>>text2;
            // std::cout<<"Enter key: ";
            // std::string key;
            // std::cin>>key;
            std::cin.ignore();

            std::ifstream inFile(text);
            if (!inFile) {
                std::cout << "Error opening file for reading!\n";
            }
            std::ofstream outFile(text2);  
            if (!outFile) {
                std::cout << "Error opening file for writing!\n";
            }

            std::string line;
            while (std::getline(inFile, line)) {
            //    outFile<<xorEncryptDecrypt(line,key)<<std::endl;
               outFile<<SmileCrypto(line)<<std::endl;
            }
            outFile.close();
            inFile.close();
          }else if(method==4){    
            std::cout<<"Enter file for read: ";
            std::string text;
            std::cin>>text;
            std::cout<<"Enter file for write: ";
            std::string text2;
            std::cin>>text2;
            std::cout<<"Enter key: ";
            std::string key;
            std::cin>>key;
            std::cin.ignore();

            std::ifstream inFile(text);
            if (!inFile) {
                std::cout << "Error opening file for reading!\n";
            }
            std::ofstream outFile(text2);  
            if (!outFile) {
                std::cout << "Error opening file for writing!\n";
            }

            std::string line;
            while (std::getline(inFile, line)) {
               outFile<<xorEncryptDecrypt(line,key)<<std::endl;
            }
            outFile.close();
            inFile.close();
          }
          else{
              std::cout<<"Invalid method"<<std::endl;
          }
        }else if(choice==2){
            if(method==1){
                std::cout<<"Enter file for read: ";
                std::string text;
                std::cin>>text;
                std::cout<<"Enter file for write: ";
                std::string text2;
                std::cin>>text2;
                std::cout<<"Enter key: ";
                int key;
                std::cin>>key;
                std::cin.ignore();
  
                std::ifstream inFile(text);
                if (!inFile) {
                    std::cout << "Error opening file for reading!\n";
                }
                std::ofstream outFile(text2);  
                if (!outFile) {
                    std::cout << "Error opening file for writing!\n";
                }
    
                std::string line;
              //   std::cout << "Contents of " << text << ":\n";
                while (std::getline(inFile, line)) {
                   outFile<<Caesar(line,key*(-1))<<std::endl;
                }
                outFile.close();
                inFile.close();
  
            }else if(method==2){
              std::cout<<"Enter file for read: ";
              std::string text;
              std::cin>>text;
              std::cout<<"Enter file for write: ";
              std::string text2;
              std::cin>>text2;
              std::cin.ignore();
  
              std::ifstream inFile(text);
              if (!inFile) {
                  std::cout << "Error opening file for reading!\n";
              }
              std::ofstream outFile(text2);  
              if (!outFile) {
                  std::cout << "Error opening file for writing!\n";
              }
  
              std::string line;
            //   std::cout << "Contents of " << text << ":\n";
              while (std::getline(inFile, line)) {
                 outFile<<ATBACH(line)<<std::endl;
              }
              outFile.close();
              inFile.close();
  
  
            }else if(method==3){    
              std::cout<<"Enter file for read: ";
              std::string text;
              std::cin>>text;
              std::cout<<"Enter file for write: ";
              std::string text2;
              std::cin>>text2;
            //   std::cout<<"Enter key: ";
            //   std::string key;
            //   std::cin>>key;
              std::cin.ignore();
  
              std::ifstream inFile(text);
              if (!inFile) {
                  std::cout << "Error opening file for reading!\n";
              }
              std::ofstream outFile(text2);  
              if (!outFile) {
                  std::cout << "Error opening file for writing!\n";
              }
  
              std::string line;
              while (std::getline(inFile, line)) {
                //  outFile<<xorEncryptDecrypt(line,key)<<std::endl;
               outFile<<SmileDecrypto(line)<<std::endl;

              }
              outFile.close();
              inFile.close();
          }else if(method==4){    
            std::cout<<"Enter file for read: ";
            std::string text;
            std::cin>>text;
            std::cout<<"Enter file for write: ";
            std::string text2;
            std::cin>>text2;
            std::cout<<"Enter key: ";
            std::string key;
            std::cin>>key;
            std::cin.ignore();

            std::ifstream inFile(text);
            if (!inFile) {
                std::cout << "Error opening file for reading!\n";
            }
            std::ofstream outFile(text2);  
            if (!outFile) {
                std::cout << "Error opening file for writing!\n";
            }

            std::string line;
            while (std::getline(inFile, line)) {
               outFile<<xorEncryptDecrypt(line,key)<<std::endl;

            }
            outFile.close();
            inFile.close();
        }else{
              std::cout<<"Invalid method"<<std::endl;
          }
      
  }else if(choice==3){
          std::cout<<"Goodbye!"<<std::endl;
      }else{
          std::cout<<"Invalid choice"<<std::endl;
      }
  }
  
  
  else if(ChoiceType==3){
    std::cout<<"Goodbye!"<<std::endl;
}


}



int main() {

    std::cout<<"Welcome to program"<<std::endl;
    std::cout<<"1) Encrypt text"<<std::endl;
    std::cout<<"2) Decrypt text"<<std::endl;
    std::cout<<"3) Exit"<<std::endl;

    std::cout<<"Enter your choice: ";
    int choice;
    std::cin>>choice;
    std::cin.ignore(); 

    std::cout<<"What type of text do you want to encrypt/decrypt?"<<std::endl;
    std::cout<<"1) Text"<<std::endl;
    std::cout<<"2) File"<<std::endl;
    std::cout<<"3) Exit"<<std::endl;
    std::cout<<"Enter your choice: ";

    int ChoiceType;
    std::cin>>ChoiceType;
    std::cin.ignore();  

    std::cout<<"Enter method of encrypt: ";
    std::cout<<"Welcome to program"<<std::endl;
    std::cout<<"1) method of caesar"<<std::endl;
    std::cout<<"2) Method of Atbach"<<std::endl;
    std::cout<<"3) Method of SmileCrypt "<<std::endl;
    std::cout<<"4) Method of XOR"<<std::endl;

    int method;
    std::cin>>method;
    std::cin.ignore();

    choiceMenu(choice,ChoiceType,method);

    return 0;
}
