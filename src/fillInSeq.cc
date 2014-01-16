#include <iostream>
#include <fstream>
#include <cassert>
#include <algorithm>
#include <iterator>
 
#if defined ( __GNUG__ ) && __GNUC__ >= 3
#include <Sequence/FastaExplicit.hpp>
#else
#include <Sequence/Fasta.hpp>
#include <Sequence/Clustalw.hpp>
#endif
#include <Sequence/SeqExceptions.hpp>

using namespace std;
using namespace Sequence;
using namespace Sequence::Alignment;

void process (std::vector<Fasta> *alignment);

int main(int argc, char **argv)
{
  vector<Fasta> alignment;
  for (unsigned i = 1 ; i < argc ; ++i)
    {
      char *infile = argv[i];
      try
	{
	  GetData(alignment,infile);
	}
      catch (SeqException &e)
	{
	  cerr << e << endl;
	  exit(10);
	}
      if ( IsAlignment(alignment) )
	{
	  process(&alignment);
	  copy(alignment.begin(),alignment.end(),
	       ostream_iterator<Fasta>(cout,"\n"));
	}
      else
	{
	  cerr << "file "<< infile << " does not appear aligned, skipping..."<<endl;
	}
    }
}

void process (std::vector<Fasta> *alignment)
{
  for (unsigned site = 0 ; site < (*alignment)[0].length() ; ++site)
    {
      for (unsigned seq = 0 ; seq < alignment->size() ; ++seq)
	{
	  if ( (*alignment)[seq][site] == '.' )
	    {
	      (*alignment)[seq][site] = (*alignment)[0][site];
	    }
	}
    }
}
