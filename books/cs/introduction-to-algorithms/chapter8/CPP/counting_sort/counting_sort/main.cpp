//
//  main.cpp
//  counting_sort
//
//  Created by Bater.Makhabel on 8/24/16.
//  Copyright © 2016 meta4all. All rights reserved.
//

#include <iostream>
#include <random>

int main(int argc, const char * argv[]) {
    // insert code here...
    const int dataset_size = 100;
    const int dataset_max_value = 100;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, dataset_max_value);

    int aaa[dataset_size];
    int bbb[dataset_size];
    int ccc[dataset_max_value+1];
    int max_value = 0;
    int total = 0;
    int idx = 0;
    
    
    for( idx=0; idx<dataset_size; idx++){
        aaa[idx] = dis(gen);
        
        ccc[aaa[idx]] += 1;
        
        max_value = (aaa[idx]>max_value)?aaa[idx]:max_value;
        std::cout << idx << " , " << aaa[idx] << " , " << max_value << " , " << ccc[aaa[idx] ]<< std::endl;
    }
    
    for( idx=0; idx<=max_value; idx++ ){
        total += ccc[idx];
        ccc[idx] = total;
    }
    
    for( idx=dataset_size-1; idx>=0; idx-- ){
        bbb[ccc[aaa[idx]]] = aaa[idx];
        ccc[aaa[idx]] -= 1;
    }
    
    for( idx=0; idx<dataset_size; idx++ ){
        std::cout << idx << " , " << bbb[idx] << std::endl;
    }
    return 0;
}
