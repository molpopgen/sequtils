#include <vector>
#include <string>
#include <utility>
#include <Sequence/PolySites.hpp>

using namespace Sequence;

typedef std::vector<double> vd;
typedef std::vector<std::string> vs;
typedef std::pair < PolySites, int > LocusPlusSpace;
typedef std::vector< LocusPlusSpace  > LocusList;


LocusList makeLocusList( std::vector<std::string> &infiles, std::vector<int> &distances,
			 std::vector<std::string> &names, unsigned *nsam, 
			 unsigned *nsites, unsigned *totLen,
			 bool biAllelicOnly=true,unsigned mincount=0);
