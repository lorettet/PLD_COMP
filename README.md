# PLD_COMP

L'équipe projet H4311 est fier de vous presenter sont tout nouveau compilateur, surpassant de loin clang et g++ : g--

Lien du git : https://github.com/lorettet/PLD_COMP.git

#Makefile
## Cibles
- make clean : nettoie les dossiers bin
- make g4 : construit les fichiers antlr à partir de expr.g4
- make : compile le projet. Si la grammaire a changé, penser à faire make g4
- make test : clean, compile le projet et exécute le jeu de tests
- make quicktest : compile le projet et exécute le jeu de tests

L'executable est bin/exe
## Utilisation
Pour tester le projet il suffi de simplement exécuter make test. Un compte rendu des tests va alors s'afficher.

#Travail réalisé
Notre compilateur gère :
- les entiers de type int
- les déclarations simples et les declarations avec affectation
- les tableaux d'entiers
- Les opérations arythmetiques +, -, * et /
- Les afféctations
- Les return
- les if, if/else, if/else if/else
- les entiers/variables en temps qu'expression logique (sans ==, <, >...)
- les while
- les operations negative (-b, -f())
- les bloc, avec la porté des variables

Notre compilateur ne gère pas :
- les déclarations de type : int a, b,c;
- les opérateurs &, |, && et ||
- les for
- les not (!)

NB : les déclarations doivent être fait en debut de bloc, avant les instructions.

#Erreurs dans les tests
Notre jeu de test renvoi deux erreurs. Ce sont des partie du compilateur dont la grammaire a été implementée mais n'aboutissant à aucune règle dans l'IR ni en assembleur. Ce sont les operteur && et || ainsi que les if(expression) int a =4;. Nous n'avons pas pris le temps d'implémenter les opérateurs logiques, et le if/declaration ne releve d'aucun interet, nous avons donc preféré passer à coter.

---
---


# Tuto antlr :

## Antlr

### Prerequisites

```bash
$ apt install -y cmake
$ apt install -y clang
$ apt install -y curl
```

### Installation

0. Install Java (version 1.6 or higher)
1. Download
```bash
$ cd /usr/local/lib
$ curl -O https://www.antlr.org/download/antlr-4.7.2-complete.jar
```
Or just download in browser from website:
    [https://www.antlr.org/download.html](https://www.antlr.org/download.html)
and put it somewhere rational like `/usr/local/lib`.

2. Add `antlr-4.7.2-complete.jar` to your `CLASSPATH`:
```bash
$ export CLASSPATH=".:/usr/local/lib/antlr-4.7.2-complete.jar:$CLASSPATH"
```
It's also a good idea to put this in your `~/.bashrc` or whatever your startup script is.

3. Create alias for the ANTLR Tool
```bash
$ alias antlr4='java -Xmx500M -cp "/usr/local/lib/antlr-4.7.2-complete.jar:$CLASSPATH" org.antlr.v4.Tool'
```

### Testing the installation

Either launch org.antlr.v4.Tool directly:

```bash
$ java org.antlr.v4.Tool
ANTLR Parser Generator Version 4.7.2
-o ___ specify output directory where all output is generated
-lib ___ specify location of .tokens files
...
```

or use -jar option on java:

```bash
$ java -jar /usr/local/lib/antlr-4.7.2-complete.jar
ANTLR Parser Generator Version 4.7.2
-o ___ specify output directory where all output is generated
-lib ___ specify location of .tokens files
...
```



## Antlr Runtime

### Download

Download the runtime zip on [https://www.antlr.org/download.html](https://www.antlr.org/download.html).

### Compiling on Linux
```bash
$ cd <antlr4-dir>
$ mkdir build && mkdir run && cd build
$ cmake .. -DANTLR_JAR_LOCATION=/usr/local/lib/antlr-4.7.2-complete.jar -DWITH_DEMO=True
$ make
$ make install
```

## Test

```bash
$ cd <gitPLD-dir>/exemple/
$ make local
```


## Ubuntu script to use antlr4 command in makefile (in case the repo provided command is outdated)

May need to use sudo to execute following commands.

```bash
$ touch /usr/local/bin/antlr4
$ chmod +x /usr/local/bin/antlr4
$ nano /usr/local/bin/antlr4
```

Write the following in the antlr4 file :
```bash
#!/bin/bash
java -jar /usr/local/lib/antlr-4.7.2-complete.jar $@
```

If it isn't already added, add path to `/usr/local/bin` to the `PATH`.
```bash
$ nano ~/.bashrc
```
Add following line to the `.bashrc` :
```bash
export $PATH=/usr/local/bin:$PATH
```
