
In this coding challenge, the interviewers ask the candidate to make a interval_map with the initilal value from the constructor.
To insert the interval values the interviewers use the assign method and we have to implement this method

for example:  
interval_map <int, char> m('A'); 
m.assign (1,3 'B'); 1 is keyBegin and 3 is keyEnd, and char 'B is val 
m.print(); // will be [1, B] , [3, A]-> that means  -inf A ... 0 A. 1B, 2B, 3A 4A... +inf A, 
// include keyBegin but  does not include keyEnd.
m.assign(6, 9, G);
m.print(); // -inf A...0 A, 1 B, 2 B, 3 A,4 A, 5 A, 6 G 7 G 8 G, 9 A,..., +inf A

/*note that should make canonical: e.g., [1, 'C'], [4, C], [7, D]  is not allowed in m_map, the elements should merge if it is possible -> [1,C] [7,D]  */


ok now read carefully what they give us:

   V const& operator[](K const& key) const {
       auto it = m_map.upper_bound(key);
       if (it == m_map.begin()) {
           return m_valBegin;
       }
       else{
           return (--it)->second;
       }
   }

- they overload operator[] and then they get the iterator, it , with the method map::upper_bound ->return iterator after key, if this ite == map_begin() return initial value (m_valBegin)   that means as the example above m_map contains  [1, B] , [3, A], if we type std::cout << m[-1]<<'\n'; it return 'A'  because -1 is not in m_map and the iterator above the input key(-1) is m_map.begin(), and if we type std::cout << m[10]<<'\n'; 10 is over, then it = m_map.end(), then (--it) is the last element in m_map, and point to second = m_valBegin
that mean the m_map does not contain A from -inf to 1, from 1 to 2 contain C, then from 3 to +inf contain A, it only check condition then return the corresponding value.
The next thing we need to be carefull is: do not use operator [] to make a pair for exmaple m_map[keyBegin] = val; // NOOO
because the datatype for keyBegin can be string, char, int double, Note that it is template 
so use make_pair method to make a pair 

