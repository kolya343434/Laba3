#include <locale>  
#include <clocale> 
#include "interface.hpp"




int main() {
    
    std::setlocale(LC_ALL, "Russian");
    interface();
   
    return 0;
}