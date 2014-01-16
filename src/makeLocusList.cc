#include "makeLocusList.hpp"
#if defined( __GNUG__) && __GNUC__ >= 3
#include <Sequence/FastaExplicit.hpp>
#else
#include <Sequence/Alignment.hpp>
#include <Sequence/Fasta.hpp>
#endif
using namespace std;
using namespace Sequence;
using namespace Alignment;

LocusList makeLocusList( std::vector<std::string> &infiles, std::vector<int> &distances,
			 std::vector<std::string> &names, unsigned *nsam,unsigned *nsites,
			 unsigned *totLen,
			 bool biAllelicOnly,unsigned mincount)
{
	LocusList pooled;

	vector < Fasta >locus;	    //one locus at a time
	vector< int > lengths;              //to store lengths of sequences
	bool KnowNames = 0;
	*nsam = 0;
	*nsites = 0;
	*totLen = 0;
	//read in all the data from the infiles
	for (unsigned int i = 0; i < infiles.size (); ++i)
	{
		GetData (locus, infiles[i].c_str ());
		if (Gapped (locus))
			RemoveTerminalGaps (locus);
		lengths.push_back(locus[0].length());
		*totLen += locus[0].length();
		*nsam = locus.size ();

		PolySites p(locus,biAllelicOnly);
		if(mincount > 0)
		  {
		    p.ApplyFreqFilter(mincount);
		  }
		*nsites += p.numsites();

		if ( i == 0)
		  {
		    pooled.push_back( LocusPlusSpace(p,0) );
		  }
		else 
		  {
		    //to the positions at the current locus, we
		    //must add the length of the last sequence,
		    //plus what we needed to add to the 
		    //positions at that locus
		    int add = ( lengths[i-1]   ) + distances[i-1] + pooled[i-1].second;
		    pooled.push_back( LocusPlusSpace(p,add ) );
		  }
		vd t = pooled[pooled.size()-1].first.GetPositions();

		if (!(KnowNames))
		{
			names.resize (locus.size ());
			for (unsigned int j = 0; j < locus.size (); ++j)
				names[j] = locus[j].GetName ();
			KnowNames = 1;
		}
		locus.clear();
	}
	return pooled;
}
