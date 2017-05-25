//preprocessing 
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
	int no_of_training_sets=15;
		string fileName[no_of_training_sets]={
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\bbc\\business\\001.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\bbc\\business\\002.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\bbc\\business\\003.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\bbc\\business\\004.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\bbc\\sport\\005.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\bbc\\tech\\006.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\bbc\\tech\\007.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\bbc\\tech\\008.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\bbc\\sport\\009.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\bbc\\sport\\010.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\bbc\\business\\011.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\bbc\\business\\012.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\bbc\\tech\\013.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\bbc\\business\\014.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\bbc\\tech\\015.txt"
				};
		
		string fileName1[no_of_training_sets]={
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning\\001.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning\\002.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning\\003.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning\\004.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning\\005.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning\\006.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning\\007.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning\\008.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning\\009.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning\\010.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning\\011.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning\\012.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning\\013.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning\\014.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning\\015.txt"

		};
		
			string fileName2[no_of_training_sets]={
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\001.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\002.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\003.txt",
			"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\004.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\005.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\006.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\007.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\008.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\009.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\010.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\011.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\012.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\013.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\014.txt",
		"C:\\Users\\chiru\\Desktop\\Academics\\Sem6\\data_mining\\project\\datasets_aftercleaning1\\015.txt"
		};
		
	
		ifstream infile;
		ofstream ofile;	
	
	
		
		for(int i=0;i<no_of_training_sets;i++)
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
  			
					}	
 		
  
 		 if (!infile.eof())
 			 {
    			cerr << "Fooey!\n";
  			}
  			
  			infile.close();
  			 ofile.close();

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
	//	   	arr1[k]=tolower(arr1[k]);
					}		 
   			
			   	 
		for(int k=0;k<arr1.size();k++)
				ofile<<arr1[k];						
  
  
 	 if (!infile.eof())
 		 {
 		   cerr << "Fooey!\n";
  		}	
  

	
	infile.close();
	ofile.close();
		
	}
			

}
