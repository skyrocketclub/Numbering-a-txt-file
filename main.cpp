#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>

int main() {
   std::ifstream in_file {"romeoandjuliet.txt"};
   std::ofstream  out_file {"romeoandjuliet_numbered.txt"};
   
   if(!in_file){
       std::cerr<<"Error opening in_file"<<std::endl;
       return 1;
   }
   
   if(!out_file){
          std::cerr<<"Error opening out_file"<<std::endl;
          return 1;
   }
   
   std::string line;
   int line_number{1};
   
   while(getline(in_file,line)){
       
       //checking for any single letter in the sentence
      for(size_t i {0}; i<line.size(); i++){
            if(isalpha(line[i])){
           out_file<<std::setw(5)<<std::left<<line_number;
           line_number++;
           break;
            }
      }
      
    
       out_file<<line<<std::endl;
   }
   
   std::cout<<"File successfully numbered!"<<std::endl;
   
   in_file.close();
   out_file.close();
    return 0;
}