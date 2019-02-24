# pl - Print Line

`pl` it short for `print line`.

<br>

## Demo:

```bash
$ pl "hello world"
hello world

$ pl --red "hello world (red)"
hello world (red)

$ pl --blue "hello (blue) " -r --red "world (red)"
hello (blue) world (red)
```

<br>

## Install:

```bash
git clone https://github.com/WestleyR/print-line
cd print-line/
./configure [--prefix=/where/to/install]  # default: /usr/bin
make
sudo make install
```

*And yes, this supports `tcc` (tiny c compiler), use the `--compiler=tcc` when running `./configure`.*

<br>

## Download the pre-compiled code:

***NOTE:** You may not get the latest version by downloading the precompiled, check you version by running `./pl --version`.*

Click to download `pl` for your system:

  - [`x86_64`](https://github.com/WestleyR/print-line/raw/master/pre-compiled/static/x86_64/pl)<br>
    `wget https://github.com/WestleyR/print-line/raw/master/pre-compiled/static/x86_64/pl`

  - [`darwin`](https://????)<br>
    `wget https://?????`

  - [`armv7l`](https://github.com/WestleyR/print-line/raw/master/pre-compiled/static/armv7l/pl)<br>
    `wget https://github.com/WestleyR/print-line/raw/master/pre-compiled/static/armv7l/pl`

  - [manpage](https://????)<br>
    `wget https://?????`


### Then to install:

```bash
chmod +x pl
sudo mv pl /usr/local/bin

sudo mv pl.1.gz /usr/share/man/man1/
```


<br>

