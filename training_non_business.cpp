//preprocessing 
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<fstream>
using namespace std;
int main()
{

	int max=1000,no_stop_words=23;
	int no_of_training_sets=8;
	int k=0;
	
		
			string fileName2[no_of_training_sets]={
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\005.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\006.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\007.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\008.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\009.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\010.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\013.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\015.txt"
		};
		
		
		
		int no_of_terms;
		ifstream infile;
	
			
//tokenization
	vector<string> text_corpus(max);
		string word;
		for(int i=0;i<no_of_training_sets;i++)
		{
			no_of_terms=0;
		infile.open(fileName2[i].c_str());
		while(infile>>word)
   			 {
   			 
				text_corpus[no_of_terms++]=word;
			}
			infile.close();
		}
	string stopWords[no_stop_words]= {"is","this","and","a","in","all","about","of","with","use","are","the","these","done","your","&","at","an","called","to","from","now","one"};
cout<<"hg"<<endl;
	cout<<"\n words in the array:"<<endl;
	for(int i=0;i<text_corpus.size();i++)
	cout<<text_corpus[i]<<" ";
	int z=0;
for(int p=0;p<text_corpus.size();p++)
{
//	cout<<"bv";
	for(int j=0;j<text_corpus.size();j++)
	{
		for(int k=0;k<no_stop_words;k++)
		{
			if(text_corpus[j]==stopWords[k])
			{
			text_corpus.erase(text_corpus.begin()+j);
	    	}
		}				
	}
}

//infile.close();
ofstream oFile;
oFile.open("C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\text_corpus_non_business.txt");

cout<<"size:"<<text_corpus.size()<<endl;

	for(int i=0;i<text_corpus.size();i++)
	oFile<<text_corpus[i]<<"\n";
oFile.close();
cout<<endl;
	cout<<"after removing stop words:"<<endl;
	for(int i=0;i<text_corpus.size();i++)
	cout<<text_corpus[i]<<" "; 
}
