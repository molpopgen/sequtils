#if defined ( __GNUG__ ) && __GNUC__ >= 3
#include <Sequence/FastaExplicit.hpp>
#else
#include <Sequence/Alignment.hpp>
#include <Sequence/Fasta.hpp>
#endif
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

using namespace Sequence;
using namespace Alignment;
using namespace std;

int main(int argc, char *argv[])
{
  if(argc != 3)
    {
      cerr << "error"<<endl;
      exit(1);
    }
  char *posfile = argv[1];
  char *seqfile = argv[2];

  ifstream pos(posfile);
  unsigned int nsites;
  pos >> nsites;

  unsigned *positions = new unsigned[nsites+1];
  unsigned temp;
  char ch;
  pos >> temp >> ch;
  for(unsigned i = 0 ; i < nsites ; ++i)
    {
      pos >> positions[i];
    }
  pos.close();


  vector<Fasta> data;
  ifstream fix(seqfile);
  //read through the first 2 numbers, since they're not part of FASTA format
  fix >> temp;
  fix >> temp;

  Alignment::GetData(data,fix);
  assert(Alignment::IsAlignment(data));
  
  cout << data.size() << '\t' << nsites << endl;
  for(unsigned i =0 ; i < nsites ; ++i)
    {
      if (i < nsites-1)
	cout << positions[i] << '\t';
      else
	cout << positions[i] << endl;
    }
  for(unsigned i =0 ; i < nsites ; ++i)
    {
      if (i < nsites-1)
	cout << "?\t";
      else
	cout <<"?"<< endl;
    }
  for(unsigned i = 0 ; i < data.size(); ++i)
    {
      cout << data[i].GetName() << '\t';
      for(unsigned j = 0 ; j < data[i].length() ; ++j)
	{
	  if (j < data[i].length()-1)
	    cout << data[i][j] << '\t';
	  else 
	    cout << data[i][j] << endl;
	}
    }
  delete [] positions;
  exit(0);
}
