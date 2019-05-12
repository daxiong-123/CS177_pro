#include "bwt.h"
using namespace std;

void bwt_item::set_value(const string _str, const int _index){
    str = _str;
    index = _index;
}
string bwt_item::get_str(){
    return str;
}
int bwt_item::get_idx(){
    return index;
}
bool bwt_item::operator<(bwt_item& item){
    if (str < item.get_str()) return true;
    else return false;
}

bool bwt_item::operator>(bwt_item& item){
    if (str > item.get_str()) return true;
    else return false;
}

bool bwt_item::operator==(bwt_item& item){
    if (str == item.get_str()) return true;
    else return false;
}

void bwt_transform(int *suffix_array, char *bwt,const string &ref_str){
    int str_len = ref_str.size();
    bwt_item bwt_matrix[str_len];
    
    for(int i = 0; i<str_len; i++){
        bwt_matrix[i].set_value(ref_str.substr(i),i);
    }

    sort(bwt_matrix, bwt_matrix+str_len);

    for(int i=0; i<str_len; i++){
        string str = bwt_matrix[i].get_str();

        int get = str_len-str.size()-1;
        if(get == -1) get = str_len -1;
        bwt[i] = ref_str.at(get);

        suffix_array[i] = bwt_matrix[i].get_idx();
    }
    bwt[str_len] = '\0';
}

void reverse_bwt(char *bwt, string *s, int str_len, LF_map* map){
    int i = 0;
    while(bwt[i] != '$'){
        *s += bwt[i];
        i = map->get_less(bwt[i]) + map->get_value(bwt[i],i);
    }

}




