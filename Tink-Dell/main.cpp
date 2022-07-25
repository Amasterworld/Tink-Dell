//
//  main.cpp
//  Tink-Dell
//
//  Created by 25.07.22.
//

#include "interval_map.hpp"

int main(int argc, const char * argv[]) {
    
    interval_map<char, char> m('A');
    m.assign('a', 'g', 'G');
   // m.assign(1, 3, 'C');
    //m.print();
 //   m.assign(7, 9, 'D');
    //m.print();
  //  m.assign(3, 10, 'C');
    //m.print();
    //m.assign(0, 9, 'E');
    //m.assign(9, 11, 'E');
    for (int i = -2; i <= 10; ++i)
    std::cout <<  i << ' ' << m[i] << '\n';
    m.print();
    
    return 0;
}
