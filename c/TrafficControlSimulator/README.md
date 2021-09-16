# Air Traffic Control Simulator

A simulator for an airport control tower.

## Compile

Make sure to install the required project [dependencies](#Dependencies) first. Now, one will have to define the
variable ```PKG_CONFIG_PATH``` that specifies additional paths in which ```pkg-config``` will search for its libs, in
this case we are interested in the ```allegro``` libs.

If the same steps for installing ```allegro``` were followed, then the following variable is defined this way:

```bash
$ export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig/
```

Now, the program needs to be compiled, in this case using ```gcc```:

```bash
$ gcc main.c -o main `pkg-config --libs allegro-5 allegro_main-5`
```

Note that the command ```pkg-config --libs allegro-5 allegro_main-5``` is executed, which passes the result to ```gcc```
. If ran separately, one could see the following:

```bash
$ pkg-config --libs allegro-5 allegro_main-5
-L/usr/local/lib -lallegro_main -lallegro
```

## Run

After the program is compiled following the corresponding [instructions](#Compile), the program is now ready to run:

```bash

./main
```

## Dependencies

For this project, a ```gcc``` compiler is required, as well as a package named ```allegro```.

### allegro

According to official [website](https://liballeg.org/), ```allegro``` is defined as cross-platform library mainly aimed
at video game and multimedia programming.

There may be different ways to install it, but this is the one that was done and is working.

First, download the latest version of the package. At the time of the
writing, [allegro-5.2.7.0](https://github.com/liballeg/allegro5/releases/download/5.2.7.0/allegro-5.2.7.0.tar.gz) is the
latest version. You can check what is the latest version [here](https://liballeg.org/download.html).

So download that version and extract the content:

```bash
$ cd /tmp
$ curl -L https://github.com/liballeg/allegro5/releases/download/5.2.7.0/allegro-5.2.7.0.tar.gz
$ tar -xvf allegro-5.2.7.0.tar.gz
$ cd allegro-5.2.7.0
```

Now, the package contains some ```README.md``` files. One can just follow those steps which will essentially guide one
through on how to build and install the package. One may want to check on those by himself or, for a quick install,
continue with the following instructions.

Like mentioned previously, the next step is performing a project build:

```bash
$ mkdir build/
$ cd build/
$ cmake ..
```

Note: if one doesn't have ```cmake``` installed, then install it first. In ```macOS```, one would simply
do ```brew install cmake```. Refer to documentation for more information, [here](https://cmake.org/).

Now that the build is done, all is left to do is install it:

```bash
$ sudo make install
```

Using ```sudo``` is required since it installs the lib under ```/usr/local/```, so elevated permissions are required
here.
