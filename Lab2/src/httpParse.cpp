#include <iostream>
#include <fstream>
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

const char* readFile(const char* fileName);
int strnum=0;  //�ַ������� 


int main()
{
	ofstream data2;
	data2.open("output2.txt",ios::out); 
	const char* result = readFile("input2.txt");
    cout <<"�������ݣ�"<<result;
	string s="";

	if(strnum==1)
	{
		cout<<endl<<"---�ַ���ת��Ϊ�ṹ��---"<<endl; 
		for(int i=0;i<strlen(result);i++)
       {
		   s=s+result[i];
       }
		int k=0,i=0;
        while(s.length()!=0)
       {
    	   k=s.find("\\r\\n");
    	   if(k>=0)
    	   {
    		   string str1=s.substr(i,k-i);
    		   cout<<str1<<endl;
    		   data2<<str1<<endl;
    		   int k2=k+4;
    		   s=s.substr(k2,s.length()-k2);
		   }
		   else
		   {
			   cout<<s<<endl;
			   data2<<s<<endl;
			   break;
	       }
	    }	
	} 
	else
	{
		cout<<endl<<"---�ṹ��ת��Ϊ�ַ���---"<<endl; 
		for(int i=0;i<strlen(result);i++)
		{
			if(result[i]=='\n')
			{
				s=s+"\\r\\n";
			}
			else s=s+result[i];
		}
		cout<<s<<endl;
		data2<<s<<endl;
	}
	data2.close();
	return 0; 
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
