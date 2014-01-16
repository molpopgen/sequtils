#include <vector>
#include <string>
#include <cctype>
#include <iostream>
#include <poolCommon.hpp>
#include <makeLocusList.hpp>

using namespace std;
using namespace Sequence;
void GenerateOutput( const LocusList &pooled, const vector<string> &names,
		     const unsigned nsam, const unsigned nsites );

int
main (int argc, char *argv[])
{
  params args;
  parseargs(argc,argv,&args);
  vs names;
  unsigned nsam,nsites,Len;
  LocusList pooled = makeLocusList(args.infiles,args.distances,names,
				   &nsam,&nsites,&Len,
				   args.bi_allelic_only,args.mincount);
  GenerateOutput (pooled, names, nsam, nsites);
  return (0);
}

void GenerateOutput( const LocusList &pooled, const vector<string> &names,
		     const unsigned nsam, const unsigned nsites )
{
  cout << nsam << '\t' << nsites << '\n';

  //output the positions first
  for (unsigned i = 0 ; i < pooled.size() ; ++i)
    {
      vd pos = pooled[i].first.GetPositions();
      for (unsigned j = 0 ; j < pos.size() ; ++j)
	{
	  cout << unsigned(pos[j])+pooled[i].second << '\t';
	}
    }
  cout << '\n';

  //output ? for the outgroup state
  cout << "anc\t";
  for(unsigned i = 0 ; i < nsites ; ++i)
    {
      cout << "?\t";
    }
  cout << '\n';

  //now, make a copy of the data (inefficient but simple)
  vs copy;
  copy.resize(nsam);
  for (unsigned i = 0 ; i < pooled.size() ; ++i)
    {
      vs temp = pooled[i].first.GetData();
      for(unsigned j = 0 ; j < nsam ; ++j)
	{
	  copy[j] += temp[j];
	}
    }

  for (unsigned i = 0 ; i < nsam ; ++i)
    {
      cout << names[i];
      for (unsigned j = 0 ; j < nsites ; ++j)
	{
	  cout << '\t' << char(toupper(copy[i][j]));
	}
      cout << '\n';
    }
  cout << endl;
}
