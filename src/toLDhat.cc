#include <fstream>
#include "poolCommon.hpp"
#include "makeLocusList.hpp"

using namespace std;

void GenerateOutput( const LocusList &pooled, const vector<string> &names,
		     const unsigned nsam, const unsigned nsites, unsigned totLen,
		     const struct params &args);

int main(int argc, char *argv[])
{
  params args;
  parseargs(argc,argv,&args);
  if (args.seqfile==NULL||args.posfile==NULL)
    {
      usage(argv[0]);
      exit(1);
    }
  vs names;
  unsigned nsam,nsites,Len;
  LocusList pooled = makeLocusList(args.infiles,args.distances,names,&nsam,&nsites,&Len,
				   args.bi_allelic_only,args.mincount);
  GenerateOutput(pooled,names,nsam,nsites,Len,args);
}

void GenerateOutput( const LocusList &pooled, const vector<string> &names,
		     const unsigned nsam, const unsigned nsites, unsigned totLen,
		     const struct params &args)
{
  //output posfile
  ofstream posfile(args.posfile);
  posfile << nsites << '\t' << totLen << "\tL\n";
  for (unsigned i = 0 ; i< pooled.size() ; ++i)
    {
      vd temp = pooled[i].first.GetPositions();
      for (unsigned j = 0 ; j < temp.size() ; ++j)
	posfile << unsigned(temp[j])+pooled[i].second << '\n';
    }
  posfile.close();

  //  output sitesfile
  ofstream sitesfile(args.seqfile);
  sitesfile << nsam << '\t' << nsites << '\n';

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
      unsigned S = 1;
      sitesfile << '>' << names[i] << '\n';
      for (unsigned j = 0 ; j < nsites ; ++j)
	{
	  sitesfile << copy[i][j];
	  if (S++ == 80)
	    {
	      sitesfile << '\n';
	      S = 1;
	    }
	}
      sitesfile << '\n';
    }
}

