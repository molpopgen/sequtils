/* 
   trimallgaps - remove all gaps from an aligment

   Copyright (C) 2001 Kevin Thornton

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  

*/

/*! \example trimallgaps.cc
  An example of removing gaps from a file of Fasta sequences.
*/

#include <iostream>
#include <fstream>
//#include "getoptFix.h"
#include <getopt.h>
#if defined( __GNUG__ )&& __GNUC__ >= 3
#include <Sequence/FastaExplicit.hpp>
#else
#include <Sequence/Fasta.hpp>
#include <Sequence/Alignment.hpp>
#endif

#define EXIT_FAILURE 1

using namespace std;
using namespace Sequence;
using namespace Alignment;


void display_help(void);
void output(const vector<Fasta> &data, ostream &o);

int main(int argc, char *argv[]) {
  char *infile = NULL;
  char *outfile = NULL;
  bool terminal_only = 0;
  extern char *optarg;
  int c;
  while ((c = getopt (argc, argv, "i:o:t")) != -1)
    {
      switch (c)
	{
	case 'i':
	  infile = optarg;
	  break;
	case 'o':
	  outfile = optarg;
	  break;
	case 't':
	  terminal_only = 1;
	  break;
	default:
	  display_help();
	  exit(EXIT_FAILURE);
	}
    }

  vector<Fasta> data;
  if (infile != NULL)
    GetData(data,infile);
  else{
    display_help();
    exit(EXIT_FAILURE);
  }

  if (! terminal_only)
    RemoveGaps(data);
  else
    RemoveTerminalGaps(data);

  if (outfile != NULL) {
    ofstream o(outfile);
    output(data,o);
  } else
    output(data,cout);

  exit(0);
}

void output(const vector<Fasta> &data, ostream &o) {
  for(unsigned int i = 0;i<data.size();++i)
    o<<data[i]<<endl;
}

void display_help(void) {
  cerr << "trimallgaps -i infile [options]\n";
  cerr << "options:\n";
  cerr << " -t : change behavior to only trim gaps from end of alignment\n";
  cerr << " -o : write results to outfile\n";
}
