

/* Created by Anjuta version 0.1.9 */
/*	This file will not be overwritten */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
//#include <getoptFix.h>
#include <getopt.h>
#include <Sequence/SimParams.hpp>
#include <Sequence/SimData.hpp>

using namespace std;
using namespace Sequence;

void GenerateOutput (const  PolyTable *data, bool ad_spec);

int
main (int argc, char *argv[])
{
  bool ad_spec = false;
  extern int optind;
  int c;
  while ((c = getopt (argc, argv, "-d")) != -1)
    {
      switch (c)
	{
	case 'd':
	  ad_spec = true;
	  break;
	}
    }
  argc -= optind;
  argv+=optind;
  SimParams *p = new SimParams;
  p->fromfile(stdin);
  SimData *data = new SimData(p->totsam());

  std::ios_base::sync_with_stdio(true);
  int rv;
  while( (rv=data->fromfile(stdin)) != EOF)
    {
      GenerateOutput (data,ad_spec);
    }
  return (0);
}

void
GenerateOutput (const   PolyTable *data, bool ad_spec)
 {
  cout << data->size() << '\t' << data->numsites() << endl;
  for(unsigned i = 0 ; i < data->numsites() ; ++i)
    cout << data->position(i) << '\t';
  cout << endl;
    cout << "anc\t";
  if (ad_spec == false)
    {
      for(unsigned i = 0 ; i < data->numsites() ; ++i)
	cout << '?' << '\t';
    }
  else if (ad_spec == true)
    {
      for(unsigned i = 0 ; i < data->numsites() ; ++i)
	cout << '0' << '\t';
    }
  cout <<endl;
  for(unsigned i = 0 ; i < data->size() ; ++i)
    {
      cout <<"seq"<<i<<'\t';
      for(unsigned j = 0 ; j < data->numsites() ;++j)
	{
	  cout << (*data)[i][j] <<'\t';
	}
      cout << endl;
    }
  cout << endl;
}
