//semantic based classification - conncept weighting 

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
		int no_training_company=15;
		int no_business=7;
		int no_non_business=no_training_company-no_business;
	int no_testing_company=5,no_key=400;
	int no_manu=3000;

	string profile[no_business][no_key];
	string profile_non[no_non_business][no_key];
		string profile1[no_testing_company][no_key];
	int weigh[no_business]={0};
	int weigh_non[no_non_business]={0};	
	int weigh1[no_testing_company]={0};	
	string data;

   ifstream infile; 
   infile.open("C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\text_corpus.txt"); 
   string businessTerms[no_manu];
   int businessTerms_freq[no_manu];
   
    string nonbusinessTerms[no_manu];
   int nonbusinessTerms_freq[no_manu];


	int company[no_training_company];
	for(int k=0;k<no_training_company;k++)			
	company[k]=k+1;		

    int no_of_terms=0;
	while(infile>>data)
    {
	businessTerms[no_of_terms++]=data;
	}
	infile.close();	
	
	
	//calculating weights for each manuterm
	for(int i=0;i<no_of_terms;i++)
	{
		businessTerms_freq[i]=0;
		for(int j=0;j<no_of_terms;j++)
		{
			if(businessTerms[i]==businessTerms[j])
			businessTerms_freq[i]++;
		}
		
		cout<<businessTerms_freq[i]<<endl;
	}
	infile.open("C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\text_corpus_non_business.txt"); 
	int no_of_terms_non_manu=0;
	while(infile>>data)
    {
	nonbusinessTerms[no_of_terms_non_manu++]=data;
	}
	infile.close();	
	
	//calculating weights for each non-manuterm
	for(int i=0;i<no_of_terms_non_manu;i++)
	{
		nonbusinessTerms_freq[i]=0;
		for(int j=0;j<no_of_terms;j++)
		{
			if(nonbusinessTerms[i]==nonbusinessTerms[j])
			nonbusinessTerms_freq[i]--;
		}
		
		cout<<nonbusinessTerms_freq[i]<<endl;
/*		if(i%4==0)
		businessTerms_freq[i]=2;
		else if(i%3==0)
		businessTerms_freq[i]=3;
		else
		businessTerms_freq[i]=1;  */
	}

cout<<"out";
		
	/*	string str="C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\OR\\coding\\c";
		string base=".txt";
		*/
	
		
		string fileName_business[no_business] = {"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\001.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\002.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\003.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\004.txt",
				"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\011.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\012.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\014.txt"};
		
			int j;
	for(int i=0;i<no_business;i++)
	{
	 j=0;
	infile.open(fileName_business[i].c_str());
	while(infile>>data)
	{
	profile[i][j]=data;
	j++;
	}
	infile.close();
	}
	
	int q=0;
	for(int j=0;j<no_business;j++){
		weigh[j]=0;
		
		for(int k=0;k<no_key;k++){
			
			for(int i=0;i<no_of_terms;i++){
				
					if (profile[j][k]==nonbusinessTerms[i])	
					{
					weigh[j]=weigh[j]+nonbusinessTerms_freq[i];
				//	q=1;
					}
					if (profile[j][k]==businessTerms[i])		
					{
					weigh[j]=weigh[j]+businessTerms_freq[i];
				//	q=1;
}
//if(q==1)break;
			}				
		}
		
		cout<<"company"<<j+1<<" "<<weigh[j]<<endl;
	}
	
	string fileName_non_business[no_non_business]={"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\005.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\006.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\007.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\008.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\009.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\010.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\013.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\015.txt"
	};
	
		for(int i=0;i<no_non_business;i++)
	{
	 j=0;
	infile.open(fileName_non_business[i].c_str());
	while(infile>>data)
	{
	profile_non[i][j]=data;
	j++;
	}
	infile.close();
	}
	
	for(int j=0;j<no_non_business;j++){
		weigh_non[j]=0;
		
		for(int k=0;k<no_key;k++){
			
			for(int i=0;i<no_of_terms;i++){
				
					if (profile_non[j][k]==nonbusinessTerms[i])		
					weigh_non[j]=weigh_non[j]+nonbusinessTerms_freq[i];

					if (profile_non[j][k]==businessTerms[i])		
					weigh_non[j]=weigh_non[j]+businessTerms_freq[i];

			}				
		}
		
		cout<<"company"<<j+1<<" "<<weigh_non[j]<<endl;
	}
	
/*	int c=0;
	int min=weigh[0];
	int max_neg=-1;
	for(int i=0;i<no_training_company;i++)
	{
		if(weigh[i]<0)
		{
		c++;
		max_neg=weigh[i];
	}
	}
	if(c==0)*/
	
	int max_non_business=weigh_non[0];
	int min_business=weigh[0];
	int c=0;
	for(int i=0;i<no_business;i++)
	{
		if(min_business>weigh[i])
		min_business=weigh[i];
	}
	
		for(int i=0;i<no_non_business;i++)
	{
		if(weigh_non[i]<0)
		{
		c++;
		max_non_business=weigh_non[i];
	}
	}
	if(c==0)
	{
		max_non_business=weigh_non[0];
	for(int i=0;i<no_non_business;i++)
	{
			if(max_non_business<weigh_non[i])
				max_non_business=weigh_non[i];
	}
	}
	else
	{
		for(int i=0;i<no_non_business;i++)
	{
			if(weigh_non[i]<0 && max_non_business<weigh_non[i] )
				max_non_business=weigh_non[i];
	}
	}
	cout<<"min:"<<min_business<<endl;
	cout<<"max"<<max_non_business<<endl;
	int w=(min_business+max_non_business)/2;
	cout<<w<<endl;
		
		
		string fileName[no_testing_company] = {	"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\testing_datasets_aftercleaning1\\001.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\testing_datasets_aftercleaning1\\002.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\testing_datasets_aftercleaning1\\003.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\testing_datasets_aftercleaning1\\004.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\testing_datasets_aftercleaning1\\005.txt"};
	
//	for(int i=0;i<no_company;i++)
//	string filename[i]
	

//cout<<"jvj";
	for(int i=0;i<no_testing_company;i++)
	{
	 j=0;
	infile.open(fileName[i].c_str());
	while(infile>>data)
	{
	profile1[i][j]=data;
	j++;
	}
//	cout<<"hbjh";
	infile.close();
	}
	
//	cout<<"ghjv";
	for(int j=0;j<no_testing_company;j++){
		weigh1[j]=0;
		
		for(int k=0;k<no_key;k++){
			
			for(int i=0;i<no_of_terms;i++){
				
					if (profile1[j][k]==nonbusinessTerms[i])		
					weigh1[j]=weigh1[j]+nonbusinessTerms_freq[i];

					if (profile1[j][k]==businessTerms[i])		
					weigh1[j]=weigh1[j]+businessTerms_freq[i];

			}				
		}
		//weigh[j]=weigh[j];
		cout<<"company"<<j+1<<" "<<weigh1[j]<<endl;
	}
	
/*	int avg=0;
	for(int i=0;i<no_company;i++)
	{
		avg+=weigh[i];
	}
	
	avg/=no_company;*/
	
		int actual_manu=3;
	int actual_non_manu=2;
	
	int actual_business[actual_manu]={1,2,3};
	int predicted_business[5]={};
	int predicted=0;
	cout<<"Business companies:"<<endl;
	for(int i=0;i<no_testing_company;i++)
	{
		if(weigh1[i]>w)
		{
				cout<<company[i]<<endl;
				predicted_business[predicted]=company[i];
				predicted++;
		}
	
		
	}
	int tp=0;
	for(int i=0;i<actual_manu;i++)
	{
		for(int j=0;j<predicted;j++)
		{
			if(actual_business[i]==predicted_business[j])
			{
				tp++;
			}
		}
	}

	int fp = predicted-tp;

//	int c=actual_non_manu-no_company+actual_manu;
	int fn=actual_manu-tp; //b
	int tn=actual_non_manu-fp;  //d
	
	float accuracy = (float)(tp+tn)/(tp+tn+fn+fp);
	float precision = (float)tp/(tp+fp);
	float recall=(float)tp/(tp+fn);
	float f_measure=(float)(2*((precision*recall)/(precision+recall)));
	
	cout<<endl;
	cout<<"Predicted \t \t Actual"<<endl;
	cout<<"\t \t"<<"business"<<"\t"<<"non-business"<<endl;
	cout<<"business"<<"\t \t"<<tp<<"\t \t"<<fp<<endl;
	cout<<"non-business"<<"\t"<<fn<<"\t \t"<<tn<<endl;
	
	cout<<endl;
	cout<<"accuracy:"<<accuracy<<endl;
	cout<<"precision:"<<precision<<endl;
	cout<<"recall:"<<recall<<endl;
	cout<<"f_measure:"<<f_measure<<endl;
	

}
