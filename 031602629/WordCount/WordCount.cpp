#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<fstream>
using namespace std;
int plsort(string word[], int wordc[], int k)
{
	string t1;
	int t2;
	int n = k;
	if (k > 10)
		n = 10;
	for(int i=0;i<n;i++)
		for (int j = i + 1;j < k;j++)
		{
			if (wordc[i] > wordc[j])
			{
				t1 = word[i];
				word[i] = word[j];
				word[j] = t1;
				t2 = wordc[i];
				wordc[i] = wordc[j];
				wordc[j] = t2;
			}
		}
	return 0;
}
int zdsort(string word[], int wordc[], int k)
{
	string t1;
	int t2;
	int n = k;
	if (k > 10)
		n = 10;
	for (int i = 0;i < k;i++)
		for(int j= i+1;j<n;j++)
		{
			if (strcmp(word[i].c_str(), word[j].c_str())>0)
			{
				cout << word[i] << "��" << word[j] << "�Ƚ�" << endl;
				cout << strcmp(word[i].c_str(), word[j].c_str()) << endl;
				t1 = word[i];
				word[i] = word[j];
				word[j] = t1;
				t2 = wordc[i];
				wordc[i] = wordc[j];
				wordc[j] = t2;
			}
		}
	return 0;
}
int write(int characters, int words, int lines, string word[], int wordc[],int k)
{
	/*
	FiLE * wt;
	wf=fopen("result.txt","w");
	fclose(wt);
	*/
	/*
	fstream wt;
	wt.open("result.txt", ios::out, 0);
	wt << "hello";
	wt.close();
	*/
	ofstream wt2("result.txt");
	//wt2.open("result2.txt", ios::out, 0);
	wt2 << "characters: " << characters << endl;
	wt2 << "words: " << words << endl;
	wt2 << "lines: " << lines << endl;
	for (int i = 0;i < k;i++)
	{
		wt2 << "<" << word[i] << ">: " << wordc[i] << endl;
	}

	wt2.close();
	return 0;
}
int main(int argc, char * argv[])//
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
	//path���������ļ�·��
	char *path;
	/*
	if ((fp = fopen(argv[1], "r")) == NULL)//�򿪲������ɹ�
	{
		
	}
	*/
	if (argv[1] != NULL)
	{
		path = argv[1];
	
	}
	else
	{
		path = "test.txt";
	}
	if ((fp = fopen(path, "r")) == NULL)//�򿪲������ɹ�
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
				count = 0;
				continue;
				/*
				s[i++]=c;
				printf("�����ַ�\n");
				*/
			}
			else
			{
				characters++;

				
				if (t == 0 && !((c >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z')))
				{
					count = 0;
					p = 0;
				}
				//����p��־����Ϊ�˸����ʵļ�������ʼ
				if (!((c >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z') || (c >= '0'&&c <= '9')))
				{
					p = 1;
					//t = 0;
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
					words++;
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
			words++;
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
	plsort(word, wordc, k);
	zdsort(word, wordc, k);
	fclose(fp);
	printf("characters: %d\n", characters);
	printf("words: %d\n", words);
	printf("lines: %d\n", lines);
	for (i = 0;i<k;i++)
	{
		cout << "<" << word[i] << ">��" << wordc[i] << endl;
	}
	
	write(characters,words,lines,word,wordc,k);
	
	getchar();
	getchar();
	system("pause");
	return 0;
}
