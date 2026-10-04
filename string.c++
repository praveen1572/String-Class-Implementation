#include<iostream>
using namespace std;
class STRING;
int strlen(STRING &);
void strcpy(STRING &,STRING &);
class STRING{
    char *str;
    public:
    STRING(){
        cout<<"default constructor"<<endl;
        str=new char[20];
        str[0]='\0';
    }

    STRING(const char* p){
        cout<<"parametrized constructor"<<endl;
        int i=0;
        while(p[i])
        i++;
        str=new char[i+1];
        i=0;
        while(p[i]){
        str[i]=p[i];
        i++;
        }
        str[i]='\0';
    }

    STRING(STRING &a){
        cout<<"copy constructor"<<endl;
        int i=0;
        while(a.str[i])
        i++;
        str=new char[i+1];
        strcpy(*this,a);
    }

    ~STRING(){
        cout<<"destructor"<<endl;
        if(str!=nullptr)
            delete[]str;
        str=nullptr;
    }
    friend int strlen(STRING &);
    friend void strcpy(STRING &,STRING &);
    friend void strncpy(STRING &,STRING &,int);
    friend int strcmp(STRING &,STRING &);
    friend int strncmp(STRING &,STRING &,int );
    friend void strcat(STRING &,STRING &);
    friend void strncat(STRING &,STRING &,int );
    friend void strrev(STRING &);
    friend void strupr(STRING &);
    friend void strlwr(STRING &);
    friend char* strchr(STRING &,char );
    friend char* strrchr(STRING &,char );
    friend char* strstr(STRING &,const char* );
    friend ostream& operator <<(ostream &,STRING &);
    friend istream& operator >>(istream &,STRING &);

    STRING& operator =(STRING &b){
        if(this->str!=b.str){
            delete []str;
            str=new char[strlen(b)+1];
            strcpy(*this,b);
        }
        return *this;
    }

    STRING operator +(STRING &b){
        int i=0,j=0;
        STRING c;
        while(this->str[i]){
            c.str[i]=this->str[i];
            i++;
            }
        while(b.str[j]){
            c.str[i]=b.str[j];
            j++;
            i++;
        }
        c.str[i]='\0';
        return c;
    }
    
    char& operator[](int n){
    return str[n];
    }

    bool operator>(STRING &b){
    int i=0;
    while((str[i]==b.str[i])&&str[i]){
    i++;
    }
    if(str[i]==b.str[i])
        return false;
    return str[i]>b.str[i];
    }
    
    bool operator<(STRING &b){
    int i=0;
    while((str[i]==b.str[i])&&str[i]){
    i++;
    }
    if(str[i]==b.str[i])
        return false;
    return str[i]<b.str[i];
    }
    
    bool operator>=(STRING &b){
    int i=0;
    while((str[i]==b.str[i])&&str[i]){
    i++;
    }
    return str[i]>=b.str[i];
    }

    bool operator<=(STRING &b){
    int i=0;
    while((str[i]==b.str[i])&&str[i]){
    i++;
    }
    return str[i]<=b.str[i];
    }

    bool operator==(STRING &b){
    int i=0;
    while((str[i]==b.str[i])&&str[i]){
    i++;
    }
    return str[i]==b.str[i];
    }  

    bool operator!=(STRING &b){
    int i=0;
    while((str[i]==b.str[i])&&str[i]){
    i++;
    }
    return !(str[i]==b.str[i]);
    }

};

int strlen(STRING &a){
    int len=0;
    while(a.str[len]){
        len++;
    }
    return len;
}

void strcpy(STRING &a,STRING &b){
    int i=0;
    while(b.str[i]){
        a.str[i]=b.str[i];
        i++;
    }
    a.str[i]='\0';
}

void strncpy(STRING &a,STRING &b,int n){
    int i=0;
    while(n&&b.str[i]){
        a.str[i]=b.str[i];
        i++;
        n--;
    }
    a.str[i]='\0';
}

int strcmp(STRING &a,STRING &b){
    int i=0;
    while((a.str[i]==b.str[i])&&a.str[i]){
        i++;
    }
    if(a.str[i]==b.str[i]) return 0;
    return a.str[i]-b.str[i];
}

int strncmp(STRING &a,STRING &b,int n){
    int i=0;
    while((a.str[i]==b.str[i])&&a.str[i]&&n){
        i++;
        n--;
    }
    if(a.str[i]==b.str[i]) return 0;
    return a.str[i]-b.str[i];
}

void strcat(STRING &a,STRING &b){
    int i,j=0;
    i=strlen(a);
    while(b.str[j]){
        a.str[i]=b.str[j];
        i++;
        j++;
    }
    a.str[i]='\0';
}

void strncat(STRING &a,STRING &b,int n){
    int i,j=0;
    i=strlen(a);
    while(b.str[j]&&j<n){
        a.str[i]=b.str[j];
        i++;
        j++;
    }
    a.str[i]='\0';
}

void strrev(STRING &a){
    int i=0,j=strlen(a)-1;
    char t;
    while(i<j){
        t=a.str[i];
        a.str[i]=a.str[j];
        a.str[j]=t;
        i++;
        j--;
    }
}

void strupr(STRING &a){
    int i=0;
    while(a.str[i]){
        if(a.str[i]>='a'&&a.str[i]<='z')
            a.str[i]=a.str[i]^1<<5;
        i++;
    }
}

void strlwr(STRING &a){
    int i=0;
    while(a.str[i]){
        if(a.str[i]>='A'&&a.str[i]<='Z')
            a.str[i]=a.str[i]^1<<5;
        i++;
    }
}

char* strchr(STRING &a,char ch){
    int i=0;
    while((a.str[i]!=ch)&&(a.str[i]))
        i++;
    if(a.str[i]=='\0') return nullptr;
    return a.str+i;
}

char* strrchr(STRING &a,char ch){
    int i=strlen(a)-1;
    while((a.str[i]!=ch)&&(i+1))
        i--;
    if(i<0) return nullptr;
    return a.str+i;
}

char* strstr(STRING &a,const char* b){
    int i=0,len=0,k;
    while(b[len])
        len++;
    while(a.str[i]){
        if(a.str[i]==b[0]){
            k=0;
            while(b[k]){
                if(b[k]!=a.str[i+k])
                    break;
                k++;
            }
            if(b[k]=='\0')
                return a.str+i;
        }
        i++;
    }
    return nullptr;
}

ostream& operator <<(ostream& cout,STRING &a){
cout<<a.str;
return cout;
}

istream& operator >>(istream& cin,STRING &a){
cin.getline(a.str,20);
return cin;
}
int main()
{
    STRING s1;
    STRING s2("Hello");
    STRING s3(s2);

    cout<<"s2="<<s2<<endl;
    cout<<"s3="<<s3<<endl;

    s1=s2;
    cout<<"s1="<<s1<<endl;

    STRING s4("World");
    STRING s5=s2+s4;
    cout<<"s2+s4="<<s5<<endl;

    cout<<"s5[1]="<<s5[1]<<endl;

    cout<<"s2>s4="<<(s2>s4)<<endl;
    cout<<"s2<s4="<<(s2<s4)<<endl;
    cout<<"s2>=s4="<<(s2>=s4)<<endl;
    cout<<"s2<=s4="<<(s2<=s4)<<endl;
    cout<<"s2==s3="<<(s2==s3)<<endl;
    cout<<"s2!=s4="<<(s2!=s4)<<endl;

    STRING a("ABC");
    STRING b;
    strcpy(b,a);
    cout<<"strcpy="<<b<<endl;

    STRING c;
    strncpy(c,a,2);
    cout<<"strncpy="<<c<<endl;

    cout<<"strcmp="<<strcmp(a,b)<<endl;
    cout<<"strncmp="<<strncmp(a,b,2)<<endl;

    STRING d("Hello");
    STRING e("World");
    strcat(d,e);
    cout<<"strcat="<<d<<endl;

    STRING f("Hello");
    STRING g("World");
    strncat(f,g,3);
    cout<<"strncat="<<f<<endl;

    STRING h("ABCDE");
    strrev(h);
    cout<<"strrev="<<h<<endl;

    STRING i("hello");
    strupr(i);
    cout<<"strupr="<<i<<endl;

    STRING j("HELLO");
    strlwr(j);
    cout<<"strlwr="<<j<<endl;

    STRING k("HELLO");
    char *p=strchr(k,'L');
    if(p)
        cout<<"strchr="<<p<<endl;

    p=strrchr(k,'L');
    if(p)
        cout<<"strrchr="<<p<<endl;

    STRING l("HelloWorld");
    p=strstr(l,"World");
    if(p)
        cout<<"strstr="<<p<<endl;

    cout<<"strlen="<<strlen(l)<<endl;

    STRING input;
    cout<<"Enter string(max 19 characters):";
    cin>>input;
    cout<<"input="<<input<<endl;

    return 0;
}
