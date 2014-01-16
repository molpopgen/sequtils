#include<iostream>
//#include "getoptFix.h"
#include <getopt.h>

#if defined( __GNUG__ ) && __GNUG__ >= 3
#include <Sequence/FastaExplicit.hpp>
#else
#include <Sequence/Fasta.hpp>
#include <Sequence/Alignment.hpp>
#endif

#include <Sequence/PolySites.hpp>
#include <Sequence/SeqEnums.hpp>

using namespace std;
using namespace Sequence;
using namespace Alignment;

struct params 
{
  char *infile;
  char *outfile;
};

void parseargs(int argc, char *argv[],params *args);
void usage(void);

int main(int argc, char *argv[])
{
  params args;
  parseargs(argc,argv,&args);
  vector<Fasta> data;
  GetData(data,args.infile);
  assert(IsAlignment(data));
  if(Gapped(data))
    {
      RemoveTerminalGaps(data);
    }
  cout << data.size() << '\t' << data[0].length() << endl;
  for(unsigned int i = 0 ; i < data.size() ; ++i)
    {
      string n = data[i].GetName();
      if (n.length() > 10)
	cout << n.substr(0,10);
      else
	{
	  cout << n;
	  for(int i = 1 ; i < 10-n.length() ; ++i)
	    cout << " ";
	}
      cout << data[i].GetSeq() << endl;
    }
}

void parseargs(int argc, char *argv[], params *args)
{
if(argc==1){
usage();
exit(1);
}

args->infile=NULL;
args->outfile=NULL;

int c;

while ((c = getopt (argc, argv, "i:o:")) != -1)
{
  switch (c)
    {
    case 'i':
      args->infile = optarg;
      break;
    case 'o':
      args->outfile=optarg;
      break;
    }
}
 if (args->infile == NULL) {
   usage();
   exit(1);
 }
}

void usage(void)
{
  cerr << "useage: tophylip -i infile -o outfile"<<endl;
}
