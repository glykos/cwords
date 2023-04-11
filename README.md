# cwords
Fast clustering of large multidimensional data sets
____________________________________________________________________


## Introduction

`cwords` is an attempt for very fast clustering of multidimensional data (for example,
data from principal component analysis). This is a work in progress, but even in its 
present form the program can cluster, for example, 6.3 million 5-dimensional data points 
in ~84 seconds on a old Intel Q9650 machine.

Note well : the program performs density-based clustering, so, (a) it is only suitable
for structured (not uniform) data, and, (b) only highly populated clusters will be assigned 
<<<<<<< HEAD
(and not all data points). Depending on the structure of your data 
=======
(and not all data points). The implication is that depending on the structure of your 
data, only a subset of the data points will be assigned to clusters.
>>>>>>> dev



## Prerequisites 

You'll need tcsh shell installed. `sudo apt install tcsh` should work on debian/ubuntu 
machines. The ready-to-go executables should work on recent linux distributions. If you need 
to compile the three C programs provided, a simple `gcc -o FILE -Ofast -fopenmp -pthread FILE.c -lpthread -lm` 
should do the trick.



## Structure of input data

The input to `cwords` is a plain ASCII file that should look like this :

```
      1   -0.3017017   -0.3564064    0.2360464   -0.4722232    0.4288760
      2    0.0474346   -0.6328480    0.5751719   -0.7150712    0.6210417
      3    0.1325109   -0.3721024    0.5942540   -0.7868665    0.5891944
      4   -0.1175150   -0.3157007    0.5488809   -0.6206126    0.3086355
      5    0.2651862   -0.2579887    0.6216121   -0.6695507    0.8647328
      .................
6310324   -1.2494680   -0.2818690   -2.0700936    0.2533956    0.4040829
6310325   -1.1238756   -0.1145879   -1.8796705    0.2570901    0.1367924
```

The first column is the data point identifier, and it must be an integer. 
The rest of the columns are the data points' coordinates in the multidimensional space 
(5 for this example). In its present form, `cwords` supports up-to 10 dimensional data.


## Using the program

Copy your data to the cwords directory, and then from the command line you say :

```
./cwords MYDATA.dat
```

and it should do it.




## Results

The file you want is `cwords_FINAL` which will look like this :

```
      8412   14  -1.4903095 -0.0092256  1.7815783 -0.1892026 -0.7727319
      8417   14  -1.5987231  0.1168284  1.9602894 -0.2719397 -0.9298855
      8442   14  -1.6215419  0.1764540  2.0331526 -0.3368094 -0.7936505
      8537   14  -1.6754376 -0.1634767  1.8656009 -0.2652288 -1.1340129
      8756   14  -1.6233163  0.0828736  1.8711712 -0.2448807 -0.8691955
      .................
   6309367    4  -1.6283491  0.9423138 -1.5060160 -0.5380138 -0.5182404
   6309371    4  -1.6364459  1.0094059 -1.3611180 -0.4456240 -0.1843502
```

The first column is the data point identifier, the second column is the cluster 
to which the point belongs. The clusters identifiers are integers. The rest of the 
columns are the coordinates of the points and are included so that you can check 
what the clustering did.


## Limitations

Too numerous to mention, but the important ones are :

* The program does not understand categorical data. Only numbers please.
* The program requires large data sets with significant densities. All my tests 
  are performed with data sets containing millions of data points.
* The program has been optimized for 5-dimensional data, because this is what
  we mostly have from our work (analysis of molecular dynamics simulations).
  I wouldn't be surprised if you find problems with other dimensionalities.
* The data are assumed to have similar/comparable range of values along the various 
  dimensions.



____________________________________________________________________

