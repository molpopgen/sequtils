#sequtils 

This is a collection of old utilities for manipulating DNA sequence data.

###Revision history

[Here](REVISION_HISTORY.md)

###Source code

The source code is available [here](https://github.com/molpopgen/sequtils)

###Dependencies 

The package dependes on the following libraries for compilation:

* [libsequence](http://molpopgen.github.io/libsequence)

In addition, you'll need a compiler supporting the C++11 language standard.

###Installation

Simplest case:

```
./configure
make
sudo make install
```

Installing into your home directory:

```
./configure --prefix=$HOME
make
make install
```

Installing when dependencies are in non-standard locations:

(for this example, I'm assuming dependencies are installed into /opt)

```
./configure CXXFLAGS=-I/opt/include LDFLAGS=-L/opt/lib
make 
sudo make install
```

If the depdendencies are in your home folder:

```
./configure CXXFLAGS=-I/$HOME/include LDFLAGS=-L/$HOME/lib
make 
make install
```

The options to ./configure shown above may be mixed and matched.

###Documentation

The following programs have "man" pages that will be available after installation:

* clustalwtofasta
* revcom
* toLDhat
* trimallgaps
