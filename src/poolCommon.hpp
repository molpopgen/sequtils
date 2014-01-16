//paramater things common to programs used to pool polymorphism data from multiple loci together
#include <vector>

struct params 
{
  unsigned mincount;
  bool do_gc;
  bool bi_allelic_only;
  std::vector<std::string> infiles;
  std::vector<int> distances;
  char *seqfile;
  char *posfile;
};

void parseargs(int argc, char *argv[], params *args);
void usage(const char *program);
