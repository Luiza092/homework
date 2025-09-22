#include <iostream>
#include <vector>

int findSubsequence(const std::vector<int> &mainv, const std::vector<int> &subv){
    if(subv.size() == 0 || subv.size() > mainv.size()){
        return -1;
    }

    for(size_t i = 0; i <= mainv.size() - subv.size(); ++i){
        bool match = true;
        for(size_t j = 0; j < subv.size(); ++j){
            if(mainv[i + j] != subv[j]){
                match = false;
                break;
            }
        }
        if(match){
            return static_cast<int>(i); 
        }
    }

    return -1;
}

int main(){
    std::vector<int> main_vec = {1, 2, 3, 4, 5, 6};
    std::vector<int> sub_vec  = {3, 4, 5};

    int index = findSubsequence(main_vec, sub_vec);

    std::cout << "Index: " << index << '\n'; 
    return 0;
}

