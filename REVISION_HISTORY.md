* version 0.2.8 (Oct 14, 2014) Updated for libsequence 1.8.3 and C++11

* version 0.2.7 (Nov 9, 2013)  Updated for libsequence 1.7.8, which is required for this version

* version 0.2.7 (Feb. 4, 2009)  Compiles nicely now on gcc 4.3.x

* version 0.2.6 (May 15, 2008) Fixed bug in description of frequency filter option (-m) that affected several programs.  Also, tohudson2001 now outputs characters instead of integers on systems using current * versions of gcc.  This was a bug due to not typecasting the return value of toupper to char.

* version 0.2.5 (Jan 22, 2008) Use of "getopt" now behaves properly on Apple's "Leopard".

* version 0.2.4 (Sept. 21, 2005)  output from tohudson2001 is now all
uppercase, which makes sure that it is compatible with Hudson's program

* version 0.2.3 (Jan 12, 2003) -- configure script now checks for
required headers.

* version 0.2.2 (Nov 1, 2003) -- compatible (and requires) libsequence
&gt;= 1.3.3

* version 0.2.1 (Jul 29th 2003) -- mstoexhap now works with latest version of exhap

* version 0.2.0 -- compatible with gcc 2.95.  output of tohudson2001
and mstoexhap now slightly different (compatible with latest versions of
Hudson's rho estimation programs).

* version 0.1.8 -- updated to libsequence 1.2.1

* version 0.1.7 -- compatible with libsequence &gt;= 1.1.7

* version 0.1.6 -- tohudson2001 and toLDhat now use a common code
base, and both work to combine multiple FASTA files into 1 output.  There
are still some limitations in interface and functionality, but they are
working well for the moment

* version 0.1.5 -- tohudson2001 now works with multiple files.  No
outgroup support yet, and individuals must be in the same order in all files.

* version 0.1.4 -- now work with g++3 on OS X

* version 0.1.3: mstoexhap now takes a -d flag.  If you use this flag,
samples are assumed to be "a/d specified", i.e. 0 is ancestral, 1 is
derived.  If the flag is not used, ancestral,derived are assumed to be unknown

* version: 0.1.2 -- mstoexhap now assums a-d unspecified samples (i.e.
the outgroup is assumed to be unknown).  The previous version output a 0
(indicating ancestral) for the outgroup state, which was incorrect.

* version: 0.1.1 -- update to libsequence 1.0.4, resulting in
mstoexhap being much faster
