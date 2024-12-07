#include <iostream>

using namespace std;


int mystrlen(char* str){
    int count=0;
    char* sptr=str;
    while(*sptr){
        count++;
        sptr++;
    }
    return count;



}

int mystrcmp(char* str1,char *str2){
    if( mystrlen(str1)>mystrlen(str2)) return 1;
    else if (mystrlen(str1)<mystrlen(str2)) return -1;

    int i=0;
while ((str1[i]==str2[i])&&(str1[i]!='\0') && (str2[i]!='\0')){


    i++;

}
return (str1[i] - str2[i]);

}

void strconcat(char* source,char* dest,int destSize){
int scount=0,dcount=0;
char* dptr=dest;
char* sptr=source;
while(*dptr){
dcount++;
dptr++;
}

while(*sptr){
scount++;
sptr++;
}
if(scount+dcount< destSize){
dptr=dest+dcount;
sptr=source;
while(*sptr)
{
*dptr=*sptr;
dptr++;
sptr++;
}
*dptr='\0';
printf("%s",dest);
}
else{printf("No Space available");}
}


class String{
private:
char*str;
int len;

public:

String(){
len=1;
str=new char[len];
str[0]='\0';
}

String(const char *ptr){
    int count=0;
    while(ptr[count])count++;
    len=count;
    str=new char[len+1];

    for(int i=0;i<len;i++){
    str[i]=ptr[i];
    }
    str[len]='\0';
}

String( String &z){
    this->len=z.len;
    this->str=new char[this->len+1];
    for(int i=0;i<this->len;i++){
        this->str[i]=z.str[i];
    }
    this->str[this->len]='\0';
}

String& operator=(String &&s) {
    if (this != &s) {
        delete[] str;
        str = s.str;
        len = s.len;
        s.str = nullptr;
        s.len = 0;
    }
    return *this;
}

int strLen(){
    return len;
}

void stringDisplay(){
cout<<str;
}

int operator==(String text){
return mystrcmp(this->str,text.str);
}

String operator+(const String &text) {
    String newStr;
    newStr.len = text.len + this->len;

    try {
        newStr.str = new char[newStr.len + 1];
        if (newStr.str == nullptr) throw exception();
    } catch (exception &e) {
        cout << "No Space";
    }

    int i;
    for (i = 0; i < this->len; i++) {
        newStr.str[i] = this->str[i];
    }
    for (i = 0; i < text.len; i++) {
        newStr.str[this->len + i] = text.str[i];
    }
    newStr.str[this->len + i] = '\0';

    return newStr;
}

~String(){
delete[]str;
}

};



int main()
{

    String str1 ("David");
    String str2 ("  Emad");
    String str3 ("Fahim");

    str3=str1+str2;

    cout<<endl<<"========================"<<endl;

    str3.stringDisplay();

    return 0;
}




