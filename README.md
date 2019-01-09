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
make
sudo make install
```

<br>

Optnaly you can install with difrant `prefix`:

```bash
make
sudo make install prefix=/wherever/you/want
```

### Download the pre-compiled code:

Click to download `pl` for your system:

  - [`x86_64`](https://?????foo)<br>
    `wget https://github.com/WestleyR/print-line/raw/master/pre-compiled/x86_64/pl`

  - [`darwin`](https://????)<br>
    `wget https://?????`

  - [`armv7l`](https://?????)<br>
    `wget https://??????`

  - [manpage](https://????)<br>
    `wget https://?????`


Then to install:

```bash
INSTALL_TO="/usr/bin"  # or wherever you want to install it
sudo mv pl ${INSTALL_TO} && sudo chmod +x ${INSTALL_TO}/pl

sudo mv pl.1.gz /usr/share/man/man1/
```


<br>

