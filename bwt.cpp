#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include"LF_map.h"
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

void bwt_transform(int *suffix_array, char *bwt, const string &ref_str){
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

}

void reverse_bwt(char *bwt, string *s, int str_len, LF_map* map){
    int i = 0;
    char front[10];
    for(int i = 0; i<str_len;i++) front[i] = bwt[i];

    sort(front, front+str_len);
    cout << front << endl;
    while(bwt[i] != '$'){
        *s += bwt[i];
        i = map->get_less(bwt[i]) + map->get_value(bwt[i],i);
    }

}

void exact_match(char *bwt, const string s, LF_map* map){
    char c = s.back();
    int sp = map->get_less(c);
    int ep = map->get_less(c)+1;
    int i = s.size() - 2;

    while(sp<ep and i>= 0){
        c = s[i];
        sp = map->get_less(c) + map->get_value(c,sp-1) + 1;
        ep = map->get_less(c) + map->get_value(c,ep);
        i--;
    }
    cout << sp << " " << ep << endl; 
}

int main(){
    string s = "ACGTGTCAT$";
    string s1 = "";
    string s2 = "ACG";
    char bwt[10];
    int sa[10];
    bwt_transform(sa,bwt,s);

    LF_map map(10, s);
    map.init_table(bwt);
    cout << bwt << endl;
    reverse_bwt(bwt,&s1,10,&map);
    exact_match(bwt,s2,&map);
    cout << s << endl;
}
