#include <iostream>
#include <fstream>
#include <iostream>
#include<bits/stdc++.h>
#include "httpParse.hpp"

using namespace std;

const char* readFile(const char* fileName);
int strnum=0;  //�ַ������� 
string s="";
map<string, string> post;  // ����һ��map����

void apart(char* result)  //��� 
{
	cout<<endl<<"---�ַ���ת��Ϊ�ṹ��---"<<endl; 
	string str6;
	
	int k=0,i=0,k3=0;
    while(s.length()!=0)
    {
       	k3=s.find("\\r\\n\\r\\n");
       	if(k3>0)
		{
			str6=s.substr((k3)+8,s.length()-k3);
		//	post["Entity-body"]=str6;
       	   // cout<<"str6:"<<str6<<endl;
		}
       	
		s=s.substr(0,k3);
    	k=s.find("\\r\\n");
    	if(k>=0)
    	{
    		string str1=s.substr(i,k-i);
    		int id_num=str1.find(':');
    		if(id_num>0)
    		{
    		   	string str2=str1.substr(0,id_num);
    		   	string str3=str1.substr(id_num+1,str1.length()-id_num);
    		   	post[str2]=str3;
			}
			else
			{
			   	int id_num2=str1.find(' ');
			   	string str4=str1.substr(0,id_num2);
			   	string str5=str1.substr(id_num2+1,str1.length()-id_num2);
			   	post["Version"]=str4;
			   	post["State-code"]=str5;
			   	//post["Status-line"]=str1;
			}
    		cout<<str1<<endl;
    		int k2=k+4;
    		s=s.substr(k2,s.length()-k2);
		}
		else
		{
			cout<<s<<endl;
			break;
	    }
	}	
	cout<<endl<<str6<<endl;
	for (map<string,string>::iterator it = post.begin(); it != post.end(); it++) 
	{
        cout << it->first << " " << it->second << endl;   
	}
} 

void connect(char* result)   //���� 
{
	string s1="";
	cout<<endl<<"---�ṹ��ת��Ϊ�ַ���---"<<endl; 
	for(int i=0;i<strlen(result);i++)
	{
		if(result[i]=='\n')
		{
			s1=s1+"\\r\\n";
		}
		else s1=s1+result[i];
	}
	cout<<s1<<endl;
}

void Parse(char* aff_filename,char* eff_filename)
{
	ofstream data2;
	data2.open(eff_filename,ios::out); 
	const char* result = readFile(aff_filename);
    cout <<"�������ݣ�"<<result;
	for(int i=0;i<strlen(result);i++)
    {
		s=s+result[i];  //ת��Ϊ�ַ��� 
    }

	if(strnum==1)
	{
		apart((char*) result);
	} 
	else
	{
		connect((char*) result);
	}
	data2.close();
}
 
 
const char* readFile(const char* fileName) {
	ifstream file(fileName);                            // ���ļ�
	char* content;
	content = (char*)malloc(sizeof(char) * 40960);           // �����ļ����Ϊ40K�����Զ���
	if (content)
	{
		char buff[1024];                                     // 1Kb�Ļ�����
		int pt = 0;
		strnum=0;
		while (file.getline(buff, 1024))                     // ���ж�ȡ�ļ���������
		{
			for (int i = 0; i < 1024; i++) {
				char tmp = buff[i];
				if (tmp == '\0') {                           // ����\0ʱ���У�������ȡ��һ��
					content[pt] = '\n';
					pt++;
					strnum++;
					break;
				}
				content[pt] = tmp;
				pt++;
			}
		}
		content[pt] = '\0';                                  // ��ȡ�����������ַ���β
		char* result = (char*)malloc(sizeof(char) * (++pt)); // ����pt+1���ֽڵ��ڴ�ռ�
		if (!result)
			return NULL;
		for (int i = 0; i < pt; i++) {
			result[i] = content[i];   
			//std::cout<<result[i]<<'\n';                       // �ַ�������
		}
		cout<<strnum<<'\n';
		return result;
	}
	return NULL;
}

/*
int main()
{
	Parse("input3.txt","output3.txt");
	return 0;
}
*/
