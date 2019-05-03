#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
using namespace std;

class bwt_item
{
private:
    string str;
    int index;
public:
    string get_str();
    int get_idx();
    bool operator<(bwt_item& item);
    bool operator>(bwt_item& item);
    bool operator==(bwt_item& item);
    void set_value(const string _str, const int _index);
};

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

int bwt_transform(int *suffix_array, char *result, const string &ref_str){
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
        result[i] = ref_str.at(get);
        suffix_array[i] = bwt_matrix[i].get_idx();
    }

    return 0;
}

int main(){
    string a="banana$";
    int b[7];
    char c[7];

    bwt_transform(b,c,a);
    for(int i =0;i<7;i++){
        cout << b[i];
    }
}