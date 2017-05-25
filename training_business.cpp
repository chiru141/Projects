//preprocessing of business files
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<fstream>
using namespace std;
int main()
{

	int max=3000,no_stop_words=24;
	int no_of_training_sets=7;
	int k=0;
		
			string fileName2[no_of_training_sets]={	"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\001.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\002.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\003.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\004.txt",
				"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\011.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\012.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\014.txt"
		};
			ifstream infile;
		

int no_of_terms=0;
	vector<string> text_corpus(max);
		string word;
		for(int i=0;i<no_of_training_sets;i++)
		{
		
		infile.open(fileName2[i].c_str());
		while(infile>>word)
   			 {
   			 
				text_corpus[no_of_terms++]=word;
				
			}
			infile.close();
			
	//string text="this is a machine and a tractor";
		}
	string stopWords[no_stop_words]= {"is","this","and","a","in","all","about","of","with","use","are","the","these","done","your","&","for","an","called","at","to","from","now","one"};

	cout<<"\n words in the array:"<<endl;
	for(int i=0;i<text_corpus.size();i++)
	cout<<text_corpus[i]<<" ";
	int z=0;
for(int p=0;p<text_corpus.size();p++)
{
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


ofstream oFile;
oFile.open("C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\text_corpus.txt");
	for(int i=0;i<text_corpus.size();i++)
{

	oFile<<text_corpus[i]<<endl;
//	cout<<text_corpus[i]<<" ";
}

cout<<"size:"<<text_corpus.size()<<endl;
oFile.close();
	cout<<endl;
	cout<<"after removing stop words:"<<endl;
	for(int i=0;i<text_corpus.size();i++)
	cout<<text_corpus[i]<<" "; 
}
