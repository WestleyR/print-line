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

  - [`x86_64`](https://?????foo)
    `wget https://??????`

  - [`darwin`](https://????)
    `wget https://?????`

  - [`armv7l`](https://?????)
    `wget https://??????`

  - [manpage](https://????)
    `wget https://?????`


Then to install:

```bash
sudo mv pl /usr/bin/  # or wherever you want to install it

sudo mv pl.1.gz /man/
```


<br>

