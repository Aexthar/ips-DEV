#include <iostream>
#include <armadillo>
#include "../hdr/solution-ho.h"

int main(){

    arma::mat A = {{1, 2}, {3, 4}}; // C++11
    arma::mat B = {{5, 6}, {7, 8}}; // C++11
    ( A * B.t() * 2 ).print("result");

    Solution1DHO s(4, 1, 1);
    
    std::cout << "value is " << s.calcFacile(2) << std::endl; 

    s.exportPoints(-100,100,100,true);

    return 0;
}