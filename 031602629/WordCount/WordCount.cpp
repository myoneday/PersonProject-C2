#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
/*
int write()
{

	return 0;
}
*/
int main(int argc, char * argv[])
{
	//����һ������fp�ļ�ָ��
	FILE *fp;
	//c�洢ÿ���ַ�
	int c;
	//s�洢�м䵥��
	string s = "", word[100];
	int i = 0;
	//������ĿҪ�������ļ���
	int characters = 0, words = 0, lines = 1, wordc[100] = { 0 };
	//count����������ĸ�����Ƿ���4��������ĸ��t��־���ʣ�k�����ʸ���,tt����Ƿ��Ѿ����뵥�ʱ���,p�����ʿ��Լ����ı�־
	int count = 0, t = 0, k = 0, tt = 0, p = 1;
	if ((fp = fopen(argv[1], "r")) == NULL)//�򿪲������ɹ�
	{
		
	}
	if ((fp = fopen("test.txt", "r")) == NULL)//�򿪲������ɹ�
	{
		printf("The file can not be opened.\n");
		exit(1);//���������ִ��
	}
	else
	{
		printf("���ļ��ɹ�\n");
		while ((c = fgetc(fp)) != EOF)
		{
			if (c >= 128)
			{
				continue;
				/*
				s[i++]=c;
				printf("�����ַ�\n");
				*/
			}
			else
			{
				characters++;
				//����p��־����Ϊ�˸����ʵļ�������ʼ
				if (!((c >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z') || (c >= '0'&&c <= '9')))
				{
					p = 1;
				}
				if (t == 0 && !((c >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z')))
				{
					count = 0;
					p = 0;
				}
				if (c == '\n')
				{
					lines++;
				}
				if (p == 1 && ((c >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z')))
				{
					count++;
					if (c >= 'A'&&c <= 'Z')
						c = c - 32;
					s += char(c);
					if (count >= 4)
						t = 1;
				}
				else if (t == 1 && c >= '0'&&c <= '9')
				{
					s += c;
				}
				else if (t == 1 && !(c >= '0'&&c <= '9'))
				{
					tt = 0;
					for (i = 0;i<k;i++)
					{
						if (word[i] == s)
						{
							wordc[i]++;
							tt = 1;
						}
					}
					if (tt == 0)
					{
						//cout<<"����"<<s<<"\n";
						word[k] = s;
						wordc[k++] = 1;
					}
					s = "";
					t = 0;
				}
			}
		}
		if (t == 1)
		{
			tt = 0;
			for (i = 0;i<k;i++)
			{
				if (word[i] == s)
				{
					wordc[i]++;
					tt = 1;
				}
			}
			if (tt == 0)
			{
				word[k] = s;
				wordc[k++] = 1;
			}
		}
	}
	fclose(fp);
	printf("characters: %d\n", characters);
	printf("words: %d\n", words);
	printf("lines: %d\n", lines);
	for (i = 0;i<k;i++)
	{
		cout << "<" << word[i] << ">��" << wordc[i] << endl;
	}
	/*
	getchar();
	getchar();
	*/
	return 0;
}
