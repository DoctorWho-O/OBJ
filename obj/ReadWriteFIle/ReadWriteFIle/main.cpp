//
//  main.cpp
//  ReadWriteFIle
//
//  Created by DW on 2020/9/4.
//  Copyright © 2020 DW. All rights reserved.
//

#include <fstream>
#include <iostream>
using namespace std;
void readObj(string name)
{
    //读取
    ifstream ifs(name);//cube bunny Eight
    //写入
    ofstream ofs;
    ofs.open("/Users/dw/Desktop/vt.txt",ios::out);
    string s;
    while(getline(ifs,s))
    {
        if(s.length()<2)continue;
        //判断vt、vn、v三种情况，这三种第一个字母都是v
        if(s[0]=='v'){
            if(s[1]=='t'){//vt 0.581151 0.979929 纹理
               
               s.replace(s.find("vt"), 2, "");
               s.replace(s.find(" "), 1, "");
               s.replace(s.find(" "), 1, ",");
               s+=",";
               ofs << s << endl;
               
            }else if(s[1]=='n'){//vn 0.637005 -0.0421857 0.769705 法向量
               /*
               s.replace(s.find("vn"), 2, "");
               s.replace(s.find(" "), 1, "");
               s.replace(s.find(" "), 1, ",");
               s.replace(s.find(" "), 1, ",");
               s+=",";
               ofs << s << endl;
               */
            }else{//v -53.0413 158.84 -135.806 点
                /*
                s.replace(s.find("v"), 1, "");
                s.replace(s.find(" "), 1, "");
                s.replace(s.find(" "), 1, ",");
                s.replace(s.find(" "), 1, ",");
                s+=",";
                ofs << s << endl;
                */
            }
        }
        //第一个字母是f的情况
        else if(s[0]=='f'){//f 2443//2656 2442//2656 2444//2656 面
            /*
            s.replace(s.find("f"), 1, "");
            s.replace(s.find(" "), 1, "");
            while (s.find(" ")!=-1) {
                s.replace(s.find(" "), 1, ",");
            }
            while (s.find("/")!=-1) {
                s.replace(s.find("/"), 1, ",");
            }
            s+=",";
            ofs << s << endl;
            */
        }
    }
    ifs.close();
    ofs.close();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string file = "/Users/dw/Desktop/pikaqiu.obj";
    readObj(file);
    return 0;
}
