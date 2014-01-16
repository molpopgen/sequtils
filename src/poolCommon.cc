#include <iostream>
#include "poolCommon.hpp"
//#include "getoptFix.h"
#include <getopt.h>

#include <cstring>
#include <cstdlib>

using namespace std;

void parseargs(int argc, char *argv[], params *args)
{
  if(argc==1){
    usage(argv[0]);
    exit(1);
  }
  args->mincount=0;
  args->do_gc=0;
  args->bi_allelic_only=0;
  args->seqfile=NULL;
  args->posfile=NULL;
 
  extern int optind;
  int c;
  unsigned nfiles;
  while ((c = getopt (argc, argv, "i:s:p:m:bg")) != -1)
    {
      switch (c)
	{
	case 'i':
	  nfiles = atoi(optarg);
	  for (unsigned i = 1 ; i <= 2*nfiles-1 ; ++i)
	    {
	      if (i % 2 == 0)
		args->distances.push_back (atoi (argv[optind++]));
	      else
		args->infiles.push_back(argv[optind++]);
	    }
	  break;
	case 's':
	  args->seqfile=optarg;
	  break;
	case 'p':
	  args->posfile=optarg;
	  break;
	case 'm':
	  args->mincount=atoi(optarg);
	  break;
	case 'g':
	  args->do_gc = 1;
	  break;
	case 'b':
	  args->bi_allelic_only = 1;
	  break;
	case '?':
	  cerr<<"error: unknown argument "<< argv[optind-1]<<endl;
	  usage(argv[0]);
	  exit(1);
	  break;
	}
    }
}

void usage(const char *program){
  cout << "usage:\n";
  cout << program <<" [options]\n";
  cout << "options:\n";
  cout << "-i n infile1 dist infile2 dist ... \n";
  cout << "-b  -- only process bi-allelic sites\n";
  cout << "-m <minfrec> -- only ananlyze sites with minor allele counts >= minfrec\n";
  cout << "\ti.e. minfrec = 2 excludes singletons\n";
  if (strcmp(program,"toLDhat")==0||strcmp(program,"./toLDhat")==0)
    {
      cout << "-s <seqfile> -- file to which to output converted data\n";
      cout << "-p <posfile> -- file to which to output seg site positions\n";
      cout << "-g -- set gene conversion option\n";
    }
}

