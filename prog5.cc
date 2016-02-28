#include "prog5.h"


/**********************************************************
*Name        : Sai Gajjala Venkata
*ZID         : Z1762423
*Assignment  : 5
*Due Date    : 2/26/2016
************************************************************/


/**********************************************************
*Function Name        : buildMineField()
*Purpose              : creates the mine field of a given size
*                       
************************************************************/
void buildMineField(vector<vector<bool>>&mines, const double& mineProb)
{

	double rnd;                  
	int seed=1;                    //initialize seed
	srand(seed);

	for (unsigned i=0;i<mines.size();i++)
	{
		for(unsigned j=0;j<mines.size();j++)
		{
			//cout<<mines[i][j]<<"\t";
			rnd=rand()/(double(RAND_MAX)+1);   //evaluate rnd    
			if (rnd<mineProb)
				mines[i][j]=true;         //mine location
			else
				mines[i][j]=false;

		}
	
	}

	
}


/**********************************************************
*Function Name        : fixCounts()
*Purpose              : Creates a table of mine counts
*                       
************************************************************/


void fixCounts(const vector<vector<bool>>&mines, vector<vector<unsigned>>&counts)
{

	for(int i=0; i<(int)mines.size(); i++)
	{
		for(int j=0; j<(int)mines.size(); j++)
		{
			if (mines[i][j])    			            //if mine found
			{   
			    counts[i][j]++;             			//count
				if(i+1<(int)mines.size()) 
					counts[i+1][j] ++;
				if(i+1<(int)mines.size() && j+1 < (int)mines.size()) 
					counts[i+1][j+1] ++;
				if(j+1 < (int)mines.size()) 
					counts[i][j+1] ++;
				if(i-1>=0 && j+1 <(int) mines.size()) 
					counts[i-1][j+1] ++;
				if(i-1>=0) 
					counts[i-1][j] ++;
				if(i-1>=0 && j-1>=0) 
					counts[i-1][j-1] ++;
				if(j-1>=0) 
					counts[i][j-1] ++;
				if(j-1>=0 && i+1 <(int) mines.size()) 
					counts[i+1][j-1] ++;
     		}
			        
		}
		//cout<<endl;
	}


}

/**********************************************************
*Function Name        : displayMineLocations()
*Purpose              : Display mine locations
*                       
************************************************************/


void displayMineLocations(const vector<vector<bool>>&mines)
{
    
	for (unsigned i=0;i<mines.size();i++)
	{

		cout<<" ";
		cout<<setfill('-')<<setw(mines.size()*6)<<"-"<<endl;
		for(unsigned l=0;l<mines.size();l++)
			cout<<"|     ";
		cout<<"|"<<endl;
		for(unsigned j=0;j<mines.size();j++)
		{

			if(mines[i][j])                            //if mine found display X
				cout<<"|  X  ";
			else
				cout<<"|     ";

		}

	cout<<"|"<<endl;
	for(unsigned p=0;p<mines.size();p++)
		cout<<"|     ";
	cout<<"|"<<endl;
	}
	cout<<" ";
	cout<<setfill('-')<<setw(mines.size()*6)<<"-"<<endl;
}

/**********************************************************
*Function Name        : displayMineCounts()
*Purpose              : display mine counts
*                       
************************************************************/
void displayMineCounts(const vector<vector<unsigned>>&counts)
{

	for(unsigned i=0; i<counts.size(); i++)
	{
		cout<<" ";
		cout<<setfill('-')<<setw(counts.size()*6)<<"-"<<endl;
		for(unsigned l=0;l<counts.size();l++)
			cout<<"|     ";
		cout<<"|"<<endl;
		for(unsigned j=0; j<counts.size(); j++)
		{
            cout<<"|  "<<counts[i][j]<<"  ";                         //display mine counts
       	}
		cout<<"|"<<endl;
		for(unsigned p=0;p<counts.size();p++)
			cout<<"|     ";
		cout<<"|"<<endl;
	}		 
	cout<<" ";
	cout<<setfill('-')<<setw(counts.size()*6)<<"-"<<endl;
}

int main()
{

	unsigned size;
	double mineProb;

	//cout<<"Enter size of mine field and Enter probability of mine in a location:";

	while(cin>>size>>mineProb)                //continue till input is given
	{


		vector<vector<bool>> mineLocations(size, vector<bool>(size));              //initialize vector
		vector<vector<unsigned>> minesCounts(size, vector<unsigned>(size));

		buildMineField(mineLocations,mineProb);                                   //call function to build mine

		cout<<"\nMine Locations: size = "<<size<<" x "<<size<<", prob of mine = "<<mineProb<<endl;

		displayMineLocations(mineLocations);										//call function to display mine locations

		fixCounts(mineLocations,minesCounts);                                       //call function to fix mine counts
	
		cout<<"Mine Counts:"<<endl;

		displayMineCounts(minesCounts);                                           ////call function to display mine counts
	}
	
	return 0;


}