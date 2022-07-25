//
//  interval_map.hpp
//  Tink-Dell
//
//  Created by Tnguyen on 25.07.22.
//

#ifndef interval_map_hpp
#define interval_map_hpp


#include <iostream>
#include <map>

template<typename  K, typename V>class interval_map{
    
private:
    V m_valBegin;
    std::map<K, V>m_map;
public:
    //constructor
    interval_map(V const& val) : m_valBegin(val)
    {

   

    }
    
    //functions
    void assign(const K keyBegin, const K keyEnd, const V& val){
        
        if (!((keyBegin) < keyEnd)){
            return;
        }
        /*
            Do not use like line 27 and 28, because here is template the datatype of K is un predictable, not all datatype support for [] operator

         m_map[keyBegin] = val; // try to comment it
         m_map[keyEnd] = m_valBegin;
         
         */
        m_map.insert(std::make_pair(keyBegin, val));
        m_map.insert(std::make_pair(keyEnd, m_valBegin));
        if (m_map.empty() && val == m_valBegin) {
            return;
        }
        auto it_end = m_map.find(keyEnd);
        //auto it_end = m_map.count(keyEnd);
        
        if (auto lo = m_map.lower_bound(keyEnd);  it_end != m_map.end()){
            std::cout << "[" << it_end->second << ':' << lo->second << "]" << std::endl;
            it_end->second = lo->second;
        }
        else {
            it_end = m_map.insert(m_map.end(), std::make_pair(keyEnd, (--lo)->second));
        }
        
        // get the iterator of the beginning of the  input range
        auto it_begin = m_map.insert_or_assign(keyBegin, val).first; // insert_or_assign() method return a pair(it, bool) in this case we need to get the iterator then .first
        
        //merge to make the new range
        m_map.erase(std::next(it_begin), it_end);
        
        for (const auto& [key, val] : m_map)
            std::cout << "[" << key << ':' << val << "]";
        std::cout << '\n';
        
        // make canonical
        auto it_right = it_end;
        auto it_left = (it_begin != m_map.begin() ? std::prev(it_begin) : m_map .begin() );
        
        while (it_right != it_left){
            
            auto it_prev_right = std::prev(it_right);
            if(it_right->second == it_prev_right->second){
                m_map.erase(it_right);
            }
            
            //update it_right
            it_right = it_prev_right;
        }
        
    }
   
    
    void print(){
        
        for (const auto& [key, value] : m_map){
         
            std::cout<< "["<<key<< " : "<<value<<"]";
        }
        std::cout<<'\n';
    }
    
    
    // overload operator
    //look-up of the value associated with key
   V const& operator[](K const& key) const {
       auto it = m_map.upper_bound(key);
       if (it == m_map.begin()) {
           return m_valBegin;
       }
       else{
           return (--it)->second;
       }
   }
    
    
};

#endif /* interval_map_hpp */
