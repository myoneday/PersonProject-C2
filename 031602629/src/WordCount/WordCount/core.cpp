#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<fstream>
#include<map>
#include<iterator>
#include <vector>
#include "core.h"
using namespace std;
void tjb::readwj(FILE *fp)
{
	int c;
	while ((c = fgetc(fp)) != EOF)
	{
		wj += c;
	}
}
int tjb::getcharacters()
{
	return characters;
}
int tjb::getwords()
{
	return words;
}
int tjb::getlines()
{
	return lines;
}
void tjb::csort()
{
	int i, j;
	int end;
	map<string, int>::iterator it;
	for (it = mm.begin();it != mm.end();it++)
	{
		v.push_back(*it);
	}
	end = mm.size();
	for (i = 0;i < end && i < 10;i++)
		for (j = i + 1;j < end;j++)
		{
			if (v[i].second < v[j].second)
			{
				swap(v[i], v[j]);
			}
		}
}
int tjb::plsort(string word[], int wordc[], int k)
{
	string t1;
	int t2;
	int n = k;
	if (k > 10)
		n = 10;
	for (int i = 0;i < n;i++)
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
int tjb::zdsort(string word[], int wordc[], int k)
{
	string t1;
	int t2;
	int n = k;
	if (k > 10)
		n = 10;
	for (int i = 0;i < n;i++)
		for (int j = i + 1;j < n;j++)
		{
			if (strcmp(word[i].c_str(), word[j].c_str()) > 0)
			{
				//cout << word[i] << "和" << word[j] << "比较" << endl;
				//cout << strcmp(word[i].c_str(), word[j].c_str()) << endl;
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
int tjb::countzf()
{
	int count = 0;
	int c;
	int n = wj.size();
	for (int i = 0;i<n;i++)
	{
		c = wj[i];
		if (c < 128&&c>0)
			count++;
	}
	characters = count;
	return count;
}
int tjb::counths()
{
	int count=0;
	int c,cc='\n';
	int n = wj.size();
	/*
	if (lines == 1)
		count = 1;
	else if (lines == 0)
		count = 0;
	*/
	for(int i=0;i<n;i++)
	{
		c = wj[i];
		if (c == '\n'&&cc!='\n')
			count++;
		cc = c;
	}
	if (wj[n - 1] != '\n')
		count++;
	lines = count;
	return count;
}
int tjb::countdc()
{
	//count计数单词字母个数是否有4个以上字母，t标志单词，k代表单词个数,tt标记是否已经存入单词表中,p代表单词可以计数的标志
	int count = 0, t = 0, k = 0, tt = 0, p = 1;
	int c;
	//s存储中间单词
	string s = "", word[20000];
	int wcount = 0;
	int n = wj.size();
	for (int i = 0;i<n;i++)
	{
		c = wj[i];
		if (c<0||c>=128)
		{
			count = 0;
			continue;
			/*
			s[i++]=c;
			printf("中文字符\n");
			*/
		}
		else
		{
			if (t == 0 && !((c >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z')))
			{
				count = 0;
				s = "";
				p = 0;
			}
			//设置p标志，是为了给单词的计数做起始
			if (!((c >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z') || (c >= '0'&&c <= '9')))
			{
				p = 1;
				//t = 0;
			}
			if (p == 1 && ((c >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z')))
			{
				count++;
				if (c >= 'A'&&c <= 'Z')
					c = c + 32;
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
				wcount++;
				map<string, int>::iterator it = mm.find(s);
				if (it == mm.end())
					mm.insert(map<string, int>::value_type(s, 1));
				else
					mm[s]++;
				s = "";
				t = 0;
				count = 0;
			}
		}
	}
	if (t == 1)
	{
		wcount++;
		map<string, int>::iterator it = mm.find(s);
		if (it == mm.end())
			mm.insert(map<string, int>::value_type(s, 1));
		else
			mm[s]++;
	}
	words = wcount;
	//plsort(word, wordc, k);
	//zdsort(word, wordc, k);
	return words;
}
int tjb::write()
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
	for (int i = 0;i < v.size() && i < 10;i++)
	{
		cout << "<" << v[i].first << ">：" << v[i].second << endl;
		wt2 << "<" << v[i].first << ">: " << v[i].second << endl;
	}
	wt2.close();
	return 0;
}