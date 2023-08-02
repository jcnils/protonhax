# protonhax
Tool to help running other programs (i.e. Cheat Engine) inside Steam's proton.

## Usage
In Steam set the launch options for the desired game to `protonhax init %COMMAND%`

To list all running appids use\
`protonhax ls`

To run a program with proton use\
`protonhax run <appid> <path/to/program> [args...]`\
NOTE: The PATH variable is ignored

To run cmd.exe use\
`protonhax cmd <appid>`

To run a program natively with the environment variables that were used to launch the game originally use\
`protonhax exec <appid> <path/to/program> [args...]`\
NOTE: The PATH variable is ignored

## Installing

For it to work, you need to be able to access both `protonhax` and `envload` from the terminal. You can use one of the available packages or build it yourself.

### Build it yourself

1. Clone our repo `https://github.com/jcnils/protonhax.git`, or download the source from our [release page](https://github.com/jcnils/protonhax/releases)
2. Open the directory in a terminal.
3. Run `make`. It will build the `envload.c` using the `Makfile` into a file called `envload`.
4. Copy both `envload` and `protonhax` files to where you want to call them from and give proper permissions, Example `/usr/bin/protonhax` and `usr/bin/envload` with permission `755`.

Try to call `envload` and `protonhax` if a usage guide appears, it means they are working.

### Arch Linux
- https://aur.archlinux.org/packages/protonhax
- https://aur.archlinux.org/packages/protonhax-git/

## Contributing
Contributions are always welcome! Especially if they are packages for other distributions.

## TODO

[] Flatpak version for Steam Flatpak
[] Packages for other Linux distributions.
