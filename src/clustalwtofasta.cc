#include <iostream>
#include <fstream>
#include <cassert>
#include <algorithm>
#include <iterator>
//#include "getoptFix.h"
#include <getopt.h>

#if defined ( __GNUG__ ) && __GNUC__ >= 3
#include <Sequence/FastaExplicit.hpp>
#else
#include <Sequence/Fasta.hpp>
#include <Sequence/Clustalw.hpp>
#endif

/*! \example clustalwtofasta.cc
  An program to read in a file of aligned sequences in ClustalW
  format, and print them out again in Fasta format.
*/
using namespace std;
using namespace Sequence;
//read in a clustalw file, convert to FASTA (print to stdout)
int
main (int argc, char *argv[])
{
	char *infile = NULL, *outfile = NULL;
	ifstream in;
	ofstream out;
	extern char *optarg;
	extern int optind;
	int c;
	while ((c = getopt (argc, argv, "i:o:")) != -1)
	{
		switch (c)
		{
		case 'i':
			infile = optarg;
			break;
		case 'o':
			outfile = optarg;
			break;
		}
	}
	argc -= optind;
	argv+=optind;
	ClustalW < Fasta > test;
	if (infile != NULL)
		in.open (infile);
	else {
	  cerr << "error: see manpage for usage info\n";
	}
	try
	{
		if (infile != NULL)
			in >> test;
	}
	catch (SeqException &e)
	{
	  e.print(cerr);
	  exit (10);
	}
	assert (test.IsAlignment ());	//check that all sequences are same length

	if (outfile != NULL)
	  {
	    out.open (outfile);
	    std::copy(test.begin(),test.end(),
		      std::ostream_iterator<Sequence::Fasta>(out,"\n"));
	  }
	else 
	  {
	    std::copy(test.begin(),test.end(),
		      std::ostream_iterator<Sequence::Fasta>(std::cout,"\n"));
	  }

	exit (0);
}
