# PLD_COMP

On va faire un compilo, en C++, c'est trop bien ...


##Tuto antlr :

### Installing antlr

0. Install Java (version 1.6 or higher)
1. Download
```
$ cd /usr/local/lib
$ curl -O https://www.antlr.org/download/antlr-4.7.2-complete.jar
```
Or just download in browser from website:
    [https://www.antlr.org/download.html](https://www.antlr.org/download.html)
and put it somewhere rational like `/usr/local/lib`.

2. Add `antlr-4.7.2-complete.jar` to your `CLASSPATH`:
```
$ export CLASSPATH=".:/usr/local/lib/antlr-4.7.2-complete.jar:$CLASSPATH"
```
It's also a good idea to put this in your `.bash_profile` or whatever your startup script is.

3. Create aliases for the ANTLR Tool, and `TestRig`.
```
$ alias antlr4='java -Xmx500M -cp "/usr/local/lib/antlr-4.7.2-complete.jar:$CLASSPATH" org.antlr.v4.Tool'
$ alias grun='java -Xmx500M -cp "/usr/local/lib/antlr-4.7.2-complete.jar:$CLASSPATH" org.antlr.v4.gui.TestRig'
```

#### Testing the installation

Either launch org.antlr.v4.Tool directly:

```
$ java org.antlr.v4.Tool
ANTLR Parser Generator Version 4.7.2
-o ___ specify output directory where all output is generated
-lib ___ specify location of .tokens files
...
```

or use -jar option on java:

```
$ java -jar /usr/local/lib/antlr-4.7.2-complete.jar
ANTLR Parser Generator Version 4.7.2
-o ___ specify output directory where all output is generated
-lib ___ specify location of .tokens files
...
```



### Installing the runtime

Download the runtime zip on https://www.antlr.org/download.html.

#### Compiling on Linux
- cd <antlr4-dir>
- mkdir build && mkdir run && cd build
- cmake .. -DANTLR_JAR_LOCATION=/usr/local/lib/antlr-4.7.2-complete.jar -DWITH_DEMO=True
- make
- make install
