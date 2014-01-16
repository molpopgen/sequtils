/* 
   revcom - reverse and complement a nucleic acid sequence

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

/*!
  \example revcom.cc
  An example of reversing and complementing a file of Fasta
  sequences.
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <Sequence/Fasta.hpp>
//#include "getoptFix.h"
#include <getopt.h>

#define EXIT_FAILURE 1
#define VERSION "0.1.0"

using namespace std;

using namespace Sequence;

void display_help(void);

int main(int argc, char *argv[]) {

  char *infile = NULL;
  char *outfile = NULL;
  int c;

  while((c = getopt(argc,argv,"i:o:hV")) != -1){
      switch(c) {
      case 'i':
	infile = optarg;
	break;
      case 'o':
	outfile = optarg;
	break;
      case 'h':
	display_help();
	exit(0);
	break;
      case 'V':
	cout << "revcom version: "<< VERSION <<"\n";
	exit(0);
	break;
      case '?':
	cerr << "unknown argument: " << optarg << "\n";
      }
  }

  if (infile==NULL){
    cerr << "type revcom -h for help\n";
    exit(EXIT_FAILURE);
 }

  class Fasta sequence;
  ifstream input;
  ofstream out;
  input.open(infile);
  //  sequence = new Fasta;

  while(! input.eof()) {
    input >> sequence;
    sequence.Revcom();
    if(outfile) {
      out.open(outfile,ios::app);
      out << sequence<< '\n';
      out.close();
    } else {
      cout << sequence << '\n';
    }
  }

  //  delete sequence;

  exit(0);
}

void display_help(void) {
  cerr << "revcom -i infile [options]\n";
  cerr << "options:\n";
  cerr << "-o : write results to outfile\n";
}
