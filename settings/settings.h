
/* 
 * File:   settings.h
 * Author: Razuvaev Daniil
 * Created on 9 декабря 2015 г., 19:03
 */
#include <map>
#include <string>
#include <iostream>
using namespace std;
class settings_t 
{
public:
   settings_t(string object_name);
   void import_settings();
   void export_settings();
   void add_setting(string setting_name,double* value);
   void add_setting(string setting_name,int* value);
   
private:
   string object_name_;
   
   map <string,int*> int_settings_;
   map <string,double*> double_settings_;
};