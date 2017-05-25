//preprocessing of testing data
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;
int main()
{

	int max=3000;
	int no_of_testing_sets=5;
		string fileName[no_of_testing_sets]={
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\bbc\\business\\016.txt",
			"C:\\Users\\chiru\\Desktop\\new.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\bbc\\business\\018.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\bbc\\sport\\019.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\bbc\\tech\\020.txt",
				};
		
		string fileName1[no_of_testing_sets]={
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\testing_datasets_aftercleaning\\001.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\testing_datasets_aftercleaning\\002.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\testing_datasets_aftercleaning\\003.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\testing_datasets_aftercleaning\\004.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\testing_datasets_aftercleaning\\005.txt"

		};
		
			string fileName2[no_of_testing_sets]={
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\testing_datasets_aftercleaning1\\001.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\testing_datasets_aftercleaning1\\002.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\testing_datasets_aftercleaning1\\003.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\testing_datasets_aftercleaning1\\004.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\testing_datasets_aftercleaning1\\005.txt"
		};
		
	
		ifstream infile;
		ofstream ofile;	
	
	
		
		for(int i=0;i<no_of_testing_sets;i++)
		{
		//	cout<<"new tra"<<endl;
			vector<string> arr(max);
				vector <string> arr1(max);
		infile.open(fileName[i].c_str());
			ofile.open( fileName1[i].c_str());
		while(infile)
   			 {
   			 //	cout<<"m"<<endl;
   			string s;
   			if (!getline( infile, s )) break;

    		istringstream ss( s );
    
		    while ( ss )
    			{
      				string s;
      				if (!getline( ss, s, ',')) break;
       					arr.push_back( s );
      			}
      		
			  			
		}	  
  			for(int k=0;k<arr.size();k++)
			  	{
			ofile<<arr[k];	
    //		cout<<arr[k];
  			
					}	
 		
  
 		 if (!infile.eof())
 			 {
    			cerr << "Fooey!\n";
  			}
  			
  			infile.close();
  			 ofile.close();

//		for(int j=0;j<arr.size();j++)		
//			cout<<arr[j];				

//vector <vector <string> >data;
 			 infile.open(fileName1[i].c_str());
 			 	ofile.open( fileName2[i].c_str());

			 while (infile)
 				 {
  					  string s;
   					 if (!getline( infile, s )) break;

  					  istringstream ss( s );
    

  					  while (ss)
  						  {
     						 string s;
      							if (!getline( ss, s, '.')) break;
     							  arr1.push_back( s );
   						 }

   				 }
   				 
   				 	for(int k=0;k<arr1.size();k++)
		  			 {
		   	transform(arr1[k].begin(), arr1[k].end(), arr1[k].begin(), ::tolower);
					}		 
   			
   			
		for(int k=0;k<arr1.size();k++)
				ofile<<arr1[k];						
  
  
 	 if (!infile.eof())
 		 {
 		   cerr << "Fooey!\n";
  		}	
  
 //	for(int j=0;j<arr1.size();j++)		
//	cout<<arr1[j];	
	
	infile.close();
	ofile.close();
		
	}
			

}
