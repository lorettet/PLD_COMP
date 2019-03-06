# Installation antlr
## Linux

(faites tout en root dans le doute)
A faire si vous les avez pas
```bash
apt install -y antlr4
apt install -y uuid-dev
apt install -y pkg-config
apt install -y cmake
```

Télécharger ça : "https://www.antlr.org/download/antlr-4.7.2-complete.jar"

Tapper :
```bash
CLASSPATH="antlr-4.7.2-complete.jar:." exec java -jar antlr-4.7.2-complete.jar "$@"
```

Télécharger et extraire ça : "https://www.antlr.org/download/antlr4-cpp-runtime-4.7.2-source.zip"

Dans le dossier extrait :

```
mkdir build run
cd build
cmake .. -DANTLR_JAR_LOCATION=full/path/to/antlr4.7.2-complete.jar -DWITH_DEMO=True # attention a bien changer le path!
make
make install
```

Ensuite aller dans le dossier exemple du git et :

```bash
make local
```

si ça compile c'est bon!

